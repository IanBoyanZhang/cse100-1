#include <iostream>
#include <limits>
#include "graph.hpp"

Edge::Edge(std::string dest, int cost) : dest(dest), cost(cost)
{

}

Graph::Graph() : cost(0)
{

}

void Graph::add(std::string from, std::string dest, int cost)
{
	graph[from].push_back(Edge(dest, cost));
	this->cost += cost;
}

int Graph::totalCost()
{
	return cost;
}

int Graph::minimumCost()
{
	Graph result;
	std::map<std::string, int> distances;

	// Dijkstra's algorithm

	// set initial distances to infinity
	AdjacencyMap::iterator amit;
	for (amit = graph.begin(); amit != graph.end(); ++amit) {
		distances[(*amit).first] = std::numeric_limits<int>::max();
	}

	// the first vertex has a distance of 0
	std::string current = (*(graph.begin())).first;
	distances[current] = 0;
	
	// find the lowest cost edge
	EdgeList edges = graph[current];
	int minCost = std::numeric_limits<int>::max();	// the lowest cost edge
	std::string dest;	// where the lowest cost edge points to
	EdgeList::iterator it;
	for (it = edges.begin(); it != edges.end(); ++it) {
		Edge e = *it;

		// store the shorter distance in distances
		if (e.cost < distances[e.dest]) {
			distances[e.dest] = e.cost;
		}

		if (e.cost < minCost) {
			minCost = e.cost;
			dest = e.dest;
		}
	}
	std::cout << dest << " " << minCost <<  std::endl;

	return result.totalCost();
}

void Graph::print()
{
	std::map<std::string, EdgeList>::iterator it;
	for (it = graph.begin(); it != graph.end(); ++it) {
		EdgeList::iterator elit;
		for (elit = (*it).second.begin(); elit != (*it).second.end(); ++elit) {
			std::cout << "Edge::" << (*it).first << std::endl;
			std::cout << "\tTo: " << (*elit).dest << std::endl;
			std::cout << "\tCost: " << (*elit).cost << std::endl;
		}
	}
}
