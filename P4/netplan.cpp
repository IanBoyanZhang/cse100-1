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
		g.add(m1, m2, cost);
	}

	std::cout << g.totalCost() << std::endl;
	g.print();
	std::cout << g.minimumCost() << std::endl;

	return 0;
}
