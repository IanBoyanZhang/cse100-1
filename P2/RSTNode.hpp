// Name: Manh Luong and Kyle So
// Login: mcluong ksso
// Student ID: A10269322 A10233937
#ifndef RSTNODE_HPP
#define RSTNODE_HPP
#include "BSTNode.hpp"
#include <cstdlib>

template <typename Data>
class RSTNode : public BSTNode<Data> {
	public:
		RSTNode(Data const & d) : BSTNode<Data>(d) {
			priority = rand();
		}

		// return the priority
		int getPriority() {
			return priority;
		}
	private:
		int priority;
};
#endif // RSTNODE_HPP
