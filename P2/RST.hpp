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
				restore(node);
				return true;
			}

			return false;
		}

		// check priority and perform necessary rotations
		void restore(RSTNode<Data>* node) {
			RSTNode<Data> *parent = (RSTNode<Data>*)node->parent;
			if (!parent) {
				return;
			}

			int priority = node->getPriority();
			if (parent && priority > parent->getPriority()) {
				if (parent->left == node) {
					std::cout << "ROTATING RIGHT" << std::endl;
					std::cout << node->data << std::endl;
					std::cout << "Priority: " << node->getPriority() << std::endl;
					std::cout << "Parent Priority: " << parent->getPriority() << std::endl;
					/*
					*/
					node = rotateWithLeftChild(node);
				} else {
					std::cout << "ROTATING LEFT" << std::endl;
					std::cout << node->data << std::endl;
					std::cout << "Priority: " << node->getPriority() << std::endl;
					std::cout << "Parent Priority: " << parent->getPriority() << std::endl;
					/*
					*/
					node = rotateWithRightChild(node);
				}
				priority = node->getPriority();
				parent = (RSTNode<Data>*)node->parent;
			}
		}

	private:
		RSTNode<Data>* rotateWithLeftChild(RSTNode<Data>* node) {
			RSTNode<Data> *l = (RSTNode<Data>*)node->left;
			node->left = l->right;
			l->right = node;
			return l;
		}

		RSTNode<Data>* rotateWithRightChild(RSTNode<Data>* node) {
			RSTNode<Data> *r = (RSTNode<Data>*)node->right;
			
			node->right = r->left;
			r->left = node;
			return r;
		}
};
#endif // RST_HPP
