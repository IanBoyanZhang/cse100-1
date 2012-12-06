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

	std::cout << g.totalCost() << std::endl;
	Graph mst = g.mst();
	std::cout << mst.totalCost() << std::endl;
	std::cout << g.totalCost() - mst.totalCost() << std::endl;

	std::cout << g.time() << std::endl;
	std::cout << mst.time() << std::endl;
	std::cout << mst.time() - g.time() << std::endl;

	return 0;
}
