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
			if (this->empty()) {
				this->root = node;
				node->parent = 0;
				++(this->isize);
				return true;
			}

			// add node to the correct position
			BSTNode<Data> *current = this->root;
			while (current) {
				// node belongs in left subtree
				if (item < current->data) {
					// stop before a null node
					if (current->left) {
						current = current->left;
					} else {
						// add node to the left
						node->parent = current;
						current->left = node;
						++(this->isize);

						// check priority
						restore(node);

						return true;
					}
					// node belongs in right subtree
				} else if (current->data < item) {
					// stop before a null node
					if (current->right) {
						current = current->right;
					} else {
						// add node to the right
						node->parent = current;
						current->right = node;
						++(this->isize);

						// check priority
						restore(node);

						return true;
					}
				} else {
					break;
				}
			}

			// could not add node
			return false;
		}

	private:
		// check priority and perform necessary rotations
		void restore(RSTNode<Data>* node) {
			int priority = node->getPriority();
			if (priority > ((RSTNode<Data>*)(node->parent))->getPriority()) {
			}
		}

		void rotateL(RSTNode<Data>* node) {
			BSTNode*
		}
};
#endif // RST_HPP
