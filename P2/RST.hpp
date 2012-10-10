#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "RSTNode.hpp"

template <typename Data>
class RST : public BST<Data> {
	public:
		virtual bool insert(const Data& item) {
			// TODO: implement this function!
			RSTNode<Data> *node = new RSTNode<Data>(item);
			if (BST<Data>::insert(node)) {
				std::cout << "Inserting: " << item << std::endl;
				restore(node);
				if (node->parent) {
					std::cout << "Parent: " << node->parent->data << std::endl;
				}
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

			if (parent->getPriority() < node->getPriority()) {
				if (parent->left == node) {
					std::cout << "ROTATING RIGHT" << std::endl;
					rotateWithLeftChild(node->parent);
				} else {
					std::cout << "ROTATING LEFT" << std::endl;
					rotateWithRightChild(node->parent);
				}
				fixParentPointers(this->root);
				this->inorder();
			}
		}

		void fixParentPointers(BSTNode<Data>* node) {
			if (node == 0) {
				return;
			}
			if (node->left) {
				node->left->parent = node;
			}
			fixParentPointers(node->left);
			if (node->right) {
				node->right->parent = node;
			}
			fixParentPointers(node->right);
		}

	private:
		RSTNode<Data>* rotateWithLeftChild(BSTNode<Data>* node) {
			RSTNode<Data> *l = (RSTNode<Data>*)node->left;
			node->left = l->right;
			l->right = node;
			return l;
		}

		RSTNode<Data>* rotateWithRightChild(BSTNode<Data>* node) {
			RSTNode<Data> *r = (RSTNode<Data>*)node->right;
			node->right = r->left;
			r->left = node;
			return r;
		}
};
#endif // RST_HPP
