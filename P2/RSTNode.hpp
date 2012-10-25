#ifndef RSTNODE_HPP
#define RSTNODE_HPP
#include "BSTNode.hpp"
#include <cstdlib>

template <typename Data>
class RSTNode : public BSTNode<Data> {
	public:
		RSTNode(Data const & d) : BSTNode<Data>(d) {
			// TODO: implement this constructor!
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
