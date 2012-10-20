#include <algorithm>
#include <bitset>
#include "HCTree.hpp"

HCTree::~HCTree()
{
}

void preorder(HCNode* node)
{
	if (!node) {
		return;
	}
	if (!node->c0 && !node->c1) {
		std::cout << node->symbol << ": " << node->count << std::endl;
	}
	preorder(node->c0);
	preorder(node->c1);
}

std::string HCTree::getCode(char symbol) const
{
	std::string code = "";
	HCNode* node = leaves[symbol];
	while (node->p) {
		if (node == node->p->c0) {
			code = "0" + code;
		} else {
			code = "1" + code;
		}
		node = node->p;
	}
	return code;
}

char HCTree::getSymbol(char encoded) const
{
	std::bitset<8> code(encoded);

	// follow the bit sequence to get the leaf
	HCNode* current = root;
	for (size_t i = 0; i < code.size(); ++i) {
		if (code[i] == '0') {
			if (!current->c0) {
				return current->symbol;
			}
			current = current->c0;
		} else {
			if (!current->c1) {
				return current->symbol;
			}
			current = current->c1;
		}
	}
	return current->symbol;
}

void HCTree::build(const std::vector<int> &freqs)
{
	for (size_t i = 0; i < freqs.size(); ++i) {
		if (freqs[i]) {
			HCNode *node = new HCNode(freqs[i], i);
			leaves[i] = node;
			pq.push(node);
		}
	}
	std::cout << pq.size() << std::endl;

	HCNode *node;
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
	preorder(root);

	std::cout << "CODE FOR A IS: " << getCode('A') << std::endl;
	std::cout << "CODE FOR B IS: " << getCode('B') << std::endl;
	std::cout << "CODE FOR C IS: " << getCode('C') << std::endl;
	/*
	*/
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
	while (in.good()) {
		bool bit = in.next();
		if (bit) {
			if (current->c1) {
				current = current->c1;
			} else {
				break;
			}
		} else {
			if (current->c0) {
				current = current->c0;
			} else {
				break;
			}
		}
	}
	return current->symbol;
}
