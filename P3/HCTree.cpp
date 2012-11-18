#include <algorithm>
#include <bitset>
#include "HCTree.hpp"

HCTree::~HCTree()
{
	delete root;
}

void HCTree::preorder(HCNode* node)
{
	if (!node) {
		return;
	}
	if (!node->c0 && !node->c1) {
		std::cout << node->symbol << ": " << getCode(node->symbol) << std::endl;
	}
	preorder(node->c0);
	preorder(node->c1);
}

std::string HCTree::getCode(byte symbol) const {
	// used the cached bit sequence
	if (codes[symbol].size()) {
		return codes[symbol];
	}

	std::string code;
	HCNode* node = leaves[symbol];

	// follow the leaf up to the root
	while (node->p) {
		if (node->p->c0 && node == node->p->c0) {
			code = "0" + code;
		} else {
			code = "1" + code;
		}
		node = node->p;
	}
	return code;
}

void HCTree::build(const std::vector<int> &freqs)
{
	// add the leaves to the priority_queue
	for (size_t i = 0; i < freqs.size(); ++i) {
		if (freqs[i]) {
			HCNode *node = new HCNode(freqs[i], i);
			leaves[i] = node;
			pq.push(node);
		}
	}

	HCNode *node;
	// add a dummy node if we only have a single node
	if (pq.size() == 1) {
		pq.push(new HCNode(0, 0));
	}

	// construct internal nodes
	while (pq.size() > 1) {
		node = new HCNode(0, 0);

		node->c0 = pq.top();
		node->c0->p = node;
		pq.pop();
		
		node->c1 = pq.top();
		node->c1->p = node;
		pq.pop();

		node->count += node->c0->count;
		node->count += node->c1->count;

		pq.push(node);
	}

	root = pq.top();
	//preorder(root);
}

void HCTree::encode(byte symbol, BitOutputStream& out) const
{
	std::string code = getCode(symbol);
	for (size_t i = 0; i < code.size(); ++i) {
		if (code[i] == '1') {
			out.writeBit(true);
		} else {
			out.writeBit(false);
		}
	}
}

int HCTree::decode(BitInputStream &in) const
{
	HCNode *current = root;
	int bit;

	// traverse the tree until we run out of bits or get a leaf
	while (current->c0 || current->c1) {
		bit = in.next();
		if (bit < 0) {
			return -1;
		}
		if (bit) {
			current = current->c1;
		} else {
			current = current->c0;
		}
	}
	return current->symbol;
}
