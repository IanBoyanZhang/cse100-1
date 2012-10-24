#ifndef RSTNODE_HPP
#define RSTNODE_HPP
#include "BSTNode.hpp"

template <typename Data>
class RSTNode : public BSTNode<Data> {
	public:
		public RSTNode(Data const & d) : BSTNode<Data>(d) {
			// TODO: implement this constructor!
		}
	private:
		int priority;
};
#endif // RSTNODE_HPP
