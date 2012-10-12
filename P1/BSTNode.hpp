// Name: Manh Luong and Kyle So
// Login: mcluong ksso
// Student ID: A10269322 A10233937
#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class BSTNode {

	public:

		/** Constructor.  Initialize a BSTNode with the given Data item,
		 *  no parent, and no children.
		 */
		BSTNode(const Data & d) : data(d) {
			left = right = parent = 0;
		}

		BSTNode<Data>* left;
		BSTNode<Data>* right;
		BSTNode<Data>* parent;
		Data const data;   // the const Data in this node.

		/** Return the successor of this BSTNode in a BST, or 0 if none.
		 ** PRECONDITION: this BSTNode is a node in a BST.
		 ** POSTCONDITION:  the BST is unchanged.
		 ** RETURNS: the BSTNode that is the successor of this BSTNode,
		 ** or 0 if there is none.
		 */
		BSTNode<Data>* successor() {
			BSTNode<Data> *current = this;
			// continue down the tree until we get the leftmost leaf
			if (current->right) {
				current = current->right;
				while (current->left) {
					current = current->left;
				}
				return current;
			}

			// go back up the tree
			current = current->parent;
			while (current) {
				if (current->left == this) {
					return current;
				}
				current = current->parent;
			}

			// no succesor was found
			return 0;
		}

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
	stm << '[';
	stm << std::setw(10) << &n;                 // address of the BSTNode
	stm << "; p:" << std::setw(10) << n.parent; // address of its parent
	stm << "; l:" << std::setw(10) << n.left;   // address of its left child
	stm << "; r:" << std::setw(10) << n.right;  // address of its right child
	stm << "; d:" << n.data;                    // its data field
	stm << ']';
	return stm;
}

#endif // BSTNODE_HPP
