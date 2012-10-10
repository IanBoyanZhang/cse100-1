# A simple makefile for CSE 100 P1

#use g++ for everything
CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -g -Wall

#include debugging symbols in executable
LDFLAGS= -g	

rst: test_RST.o countint.o
	g++ -o rst test_RST.o countint.o

benchtree: benchtree.o countint.o
	g++ -o benchtree benchtree.o countint.o

bst: test_BST.o
	g++ -o bst test_BST.o

clean:
	rm *.o bst rst benchtree

test_RST.o: RSTNode.hpp RST.hpp countint.hpp BSTNode.hpp BST.hpp BSTIterator.hpp
test_BST.o: BST.hpp BSTNode.hpp BSTIterator.hpp 
benchtree.o: BST.hpp countint.hpp RST.hpp

