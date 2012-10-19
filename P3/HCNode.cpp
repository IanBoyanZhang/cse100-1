#include "HCNode.hpp"

bool HCNode::operator<(const HCNode& other)
{
	return other.count <= this->count;
}
