#include <fstream>
#include <iostream>
#include <string>
#include "graph.hpp"

int main(int argc, char* argv[])
{
	std::ifstream ifs(argv[1]);
	Graph g;
	while (true) {
		std::string m1, m2;
		int cost, time;
		ifs >> m1 >> m2 >> cost >> time;
		if (!ifs.good()) {
			break;
		}
		g.add(m1, m2, cost, time);
	}

	Graph mst = g.mst();
	unsigned long gCost = g.totalCost(), mstCost = mst.totalCost();
	unsigned long gTime = g.time(), mstTime = mst.time();

	std::cout << gCost << std::endl;
	std::cout << mstCost << std::endl;
	std::cout << gCost - mstCost << std::endl;

	std::cout << gTime << std::endl;
	std::cout << mstTime << std::endl;
	std::cout << mstTime - gTime << std::endl;

	return 0;
}
