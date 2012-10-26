#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "RSTNode.hpp"

template <typename Data>
class RST : public BST<Data> {
	public:
		// insert the node into the RST
		// returns true if successful
		virtual bool insert(const Data& item) {
			RSTNode<Data> *node = new RSTNode<Data>(item);
			if (BST<Data>::insert(node)) {
				// debugging output
				/*
				std::cout << "----------" << std::endl;
				std::cout << "Inserting: " << item << std::endl;
				std::cout << "With Priority: " << node->getPriority() << std::endl;
				if (node->parent) {
					std::cout << "Parent: " << node->parent->data << std::endl;
				} else {
					std::cout << "Parent: Empty" << std::endl;
				}
				*/
				restore(node);
				return true;
			}

			return false;
		}

		// check priority and perform necessary rotations
		void restore(RSTNode<Data>* node) {
			RSTNode<Data> *parent = (RSTNode<Data>*)(node->parent);
			if (!parent) {
				return;
			}

			while (parent && parent->getPriority() < node->getPriority()) {
				bool newRoot = false;
				if (!node->parent->parent) {
					newRoot = true;
				}

				if (parent->left == node) {
					//std::cout << "Rotating right with pivot:" << node->parent->data << std::endl;
					node = rotateWithLeftChild(node->parent);
				} else {
					//std::cout << "Rotating left with pivot: " << node->parent->data << std::endl;
					node = rotateWithRightChild(node->parent);
				}

				//std::cout << "Rotate Returned Node: " << node->data << std::endl;
				if (newRoot) {
					this->root = node;
					this->root->parent = 0;
					//std::cout << "New Root: " << this->root->data << std::endl;
				}

				// debugging output
				/*
				std::cout << "================================================================" << std::endl;
				structure(this->root);
				std::cout << "================================================================" << std::endl;
				std::cout << "(!!!)" << std::endl;
				*/

				fixParentPointers(this->root);
				//fixParentPointers(node);
				parent = (RSTNode<Data>*)(node->parent);
			}
		}

		// traverse the tree and relink the parent pointers
		void fixParentPointers(BSTNode<Data>* node) {
			if (node == 0) {
				return;
			}
			if (node->left) {
				node->left->parent = node;
			}
			if (node->right) {
				node->right->parent = node;
			}
			fixParentPointers(node->left);
			fixParentPointers(node->right);
		}

		// output the tree structure, used for debugging
		void structure(BSTNode<Data>* node) {
			if (node == 0) {
				return;
			}
			std::cout << node->data << "\tL: ";
			if (node->left) {
				std::cout << node->left->data;
			} else {
				std::cout << "NULL";
			}
			std::cout << "\t\tR: ";
			if (node->right) {
				std::cout << node->right->data;
			} else {
				std::cout << "NULL";
			}
			std::cout << "\t\tPriority: " << ((RSTNode<Data>*)node)->getPriority() << std::endl;
			std::cout << std::endl;;
			structure(node->left);
			structure(node->right);
		}

	private:
		RSTNode<Data>* rotateWithLeftChild(BSTNode<Data>* node) {
			RSTNode<Data> *l = (RSTNode<Data>*)node->left;
			node->left = l->right;
			if (node->parent) {
				if (node->parent->data < node->data) {
					node->parent->right = l;
				} else {
					node->parent->left = l;
				}
			}
			l->right = node;
			return l;
		}

		RSTNode<Data>* rotateWithRightChild(BSTNode<Data>* node) {
			RSTNode<Data> *r = (RSTNode<Data>*)node->right;
			node->right = r->left;
			if (node->parent) {
				if (node->parent->data < node->data) {
					node->parent->right = r;
				} else {
					node->parent->left = r;
				}
			}
			r->left = node;

			// debugging output
			/*
			std::cout << "NEW NODE IS: " << r->data << std::endl;
			if (r->left) {
				std::cout << "LEFT IS: " << r->left->data << std::endl;
			} else if (r->right) {
				std::cout << "RIGHT IS: " << r->right->data << std::endl;
			}
			*/
			return r;
		}
};
#endif // RST_HPP
