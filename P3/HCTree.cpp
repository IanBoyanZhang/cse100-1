#include <algorithm>
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

void HCTree::build(const std::vector<int> &freqs)
{
	for (size_t i = 0; i < freqs.size(); ++i) {
		if (freqs[i] > 0) {
			HCNode *node = new HCNode(freqs[i], i);
			leaves[i] = node;
			pq.push(node);
		}
	}
	std::cout << pq.size() << std::endl;

	HCNode *node;
	while (pq.size() > 1) {
		node = new HCNode(0, 0);;

		node->c0 = pq.top();
		pq.pop();
		node->c1 = pq.top();
		pq.pop();

		if (node->c0) {
			node->count += node->c0->count;
		}

		if (node->c1) {
			node->count += node->c1->count;
		}

		pq.push(node);
	};

	if (!node) {
		std::cout << "AMERICA" << std::endl;
		root = pq.top();
	}

	root = pq.top();
	preorder(root);
}
