#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {

  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */ // TODO
  virtual bool insert(const Data& item) {
	  BSTNode<Data> *node = new BSTNode<Data>(item);
	  if (this->empty()) {
		  root = node;
		  node->parent = 0;
		  ++isize;
		  return true;
	  }

	  BSTNode<Data> *current = this->root;
	  while (current) {
		  if (item < current->data) {
			  // stop before a null node
			  if (current->left) {
				  current = current->left;
			  } else {
				  ++isize;
				  node->parent = current;
				  current->left = node;
				  return true;
			  }
		  } else if (current->data < item) {
			  // stop before a null node
			  if (current->right) {
				  current = current->right;
			  } else {
				  ++isize;
				  node->parent = current;
				  current->right = node;
				  return true;
			  }
		  } else {
			  return false;
		  }
	  }
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */ // TODO
  iterator find(const Data& item) const {
	  if (this->empty()) {
		  return false;
	  }

	  BSTNode<Data> *current = this->root;
	  while (current) {
		  if (item < current->data) {
			  current = current->left;
		  } else if (current->data < item) {
			  current = current->right;
		  } else {
			  break;
		  }
	  }
	  return iterator(current);
  }


  /** Return the number of items currently in the BST.
  */ // TODO
  unsigned int size() const {
	  return isize;
  }

  /** Return true if the BST is empty, else false.
  */ // TODO
  bool empty() const {
	  return isize == 0;
  }

  /** Return an iterator pointing to the first item in the BST.
  */ // TODO
  iterator begin() const {
	  BSTNode<Data> *current = this->root;
	  while (current->left) {
		  current = current->left;
	  }
	  return current;
  }

  /** Return an iterator pointing past the last item in the BST.
  */
  iterator end() const {
	  return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
  */
  void inorder() const {
	  inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */
  void inorder(BSTNode<Data>* n) const {
	  if(n==0) return;
    inorder(n->left);
    std::cout << *n << std::endl;
    inorder(n->right);
  }

  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  // do a postorder traversal, deleting nodes
  static void deleteAll(BSTNode<Data>* n) {
    if (0 == n) return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }


 };


#endif //BST_HPP
