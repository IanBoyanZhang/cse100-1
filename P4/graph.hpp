#include <list>
#include <map>
#include <string>
#include <vector>

struct Edge
{
	Edge(std::string dest, int cost);

	const std::string dest;
	const int cost;
};

typedef std::list<Edge> EdgeList;
typedef std::map<std::string, EdgeList> AdjacencyMap;

class Graph
{
	public:
		Graph();

		// add an edge to the graph
		void add(std::string from, std::string dest, int cost);

		// find the total cost of the edges in the graph
		int totalCost();

		// find the minimum cost that connects the graph
		int minimumCost();

		// for debugging, prints the edges in the graph
		void print();

		 AdjacencyMap graph;

	private:
		int cost;
};
