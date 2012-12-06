#include <list>
#include <map>
#include <string>

typedef std::string Vertex;

struct Edge
{
	// initialize the edge
	Edge(Vertex from, Vertex dest, int cost, int time);

	// used to print the edge
	friend std::ostream &operator<<(std::ostream &os, const Edge &e);

	const Vertex from;	// where the edge comes from
	const Vertex dest;	// where the edge points to
	const int cost;	// the cost of the edge
	const int time;	// the time it takes to transfer through this edge
};

struct EdgeCostCompare
{
	bool operator()(const Edge &e1, const Edge &e2) {
		return e1.cost < e2.cost;
	}
};

struct EdgeTimeCompare
{
	bool operator()(const Edge &e1, const Edge &e2) {
		return e1.time < e2.time;
	}
};

typedef std::list<Edge> EdgeList;
typedef std::map<Vertex, EdgeList> AdjacencyMap;

class Graph
{
	public:
		Graph();

		// add an edge to the graph
		void add(Edge e);
		void add(Vertex from, Vertex dest, int cost, int time);

		// find the total cost of the edges in the graph
		unsigned long totalCost();

		// find the total time it takes to send a packet between all computers
		unsigned long time();

		// find the time it takes to send a packet to all computers strating from a specific computer
		unsigned long time(Vertex current);

		// find the minimum spanning tree of the graph
		Graph mst();


		AdjacencyMap graph;

	private:
		int cost;
};
