// Name: Manh Luong and Kyle So
// Login: mcluong ksso
// Student ID: A10269322 A10233937
#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

/**
 * A simple test driver for the BST class template.
 * P1 CSE 100 2010
 * Author: P. Kube (c) 2010
 */
int main() {

  /* Create an STL vector of some ints */
  vector<int> v;
  map<int, bool> m;
  
  for (int i = 0; i < 50; ++i) {
	  int n = rand() % 1000;
	  if (!m[n]) {
		  m[n] = true;
		  v.push_back(n);
	  }
  }
  v.erase(unique(v.begin(), v.end()), v.end());
  
  std::cout << "v is size: " << v.size() << std::endl;
  for (size_t i = 0; i < v.size(); ++i) {
	  std::cout << v[i] << std::endl;
  }

  /* Create an instance of BST holding int */
  BST<int> b;

  /* Insert a few data items. */
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return true
    if(! b.insert(*vit) ) {
      cout << "Incorrect return value when inserting " << *vit << endl;
      return -1;
    }
  }

  for(; vit != ven; ++vit) {
    // all these inserts are duplicates, so should return false
    if( b.insert(*vit) ) {
      cout << "Incorrect return value when re-inserting " << *vit << endl;
      return -1;
    }
  }

  /* Test size. */
  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
    cout << "... which is incorrect." << endl;
    return -1;
  }

  /* Test find return value. */
  vit = v.begin();
  for(; vit != ven; ++vit) {
    if(*(b.find(*vit)) != *vit) {
      cout << "Incorrect return value when finding " << *vit << endl;
      return -1;
    }
  }

  

  /* Sort the vector, to compare with inorder iteration on the BST */
  sort(v.begin(),v.end());


  /* Test BST iterator; should iterate inorder */
  cout << "traversal using iterator:" << endl;
  vit = v.begin();
  BST<int>::iterator en = b.end();
  BST<int>::iterator it = b.begin();
  for(; it != en; ++it) {
    cout << *it << endl;
    if(*it != *vit) {
      cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
      return -1;
    }
    ++vit;
  }

}
