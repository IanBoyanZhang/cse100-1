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

test_RST.o: test_BST.o RSTNode.hpp RST.hpp countint.hpp
test_BST.o: BST.hpp BSTNode.hpp BSTIterator.hpp 

