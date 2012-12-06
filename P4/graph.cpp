#include <iostream>
#include <limits>
#include <set>
#include <utility>
#include "graph.hpp"
#include "disjointsets.hpp"

Edge::Edge(Vertex from, Vertex dest, int cost, int time) : from(from), dest(dest), cost(cost), time(time)
{

}

std::ostream &operator<<(std::ostream &os, const Edge &e)
{
	os << "(dest: " << e.dest << ", cost: " << e.cost << ")" << std::endl;
	return os;
}

Graph::Graph() : cost(0)
{

}

void Graph::add(Edge e)
{
	add(e.from, e.dest, e.cost, e.time);
}

void Graph::add(Vertex from, Vertex dest, int cost, int time)
{
	Edge out(from, dest, cost, time);	// the outgoing edge
	Edge in(dest, from, cost, time);	// the incoming edge

	graph[from].push_back(out);
	graph[out.dest].push_back(in);

	this->cost += cost;
}

unsigned long Graph::totalCost()
{
	return cost;
}

Graph Graph::mst()
{
	Graph result;
	std::set<Edge, EdgeCostCompare> edges;	// keeps the edges sorted
	DisjointSets<Vertex> vertices;

	// Kruskal's Algorithm

	// populate the sets of edges and vertices
	AdjacencyMap::iterator amit;
	for (amit = graph.begin(); amit != graph.end(); ++amit) {
		vertices.insert(amit->first);

		const EdgeList &el = amit->second;
		EdgeList::const_iterator elit;
		for (elit = el.begin(); elit != el.end(); ++elit) {
			edges.insert(*elit);
		}
	}

	while (!edges.empty()) {
		// get the edge with the lowest cost
		Edge e = *(edges.begin());
		edges.erase(edges.begin());

		int s1 = vertices.find(e.from);
		int s2 = vertices.find(e.dest);
		if (s1 != s2) {

			// add the edge to the graph
			result.add(e);

			// combine the two sets
			vertices.setUnion(s1, s2);
		}
	}

	return result;
}

unsigned long Graph::time()
{
	int result = 0;
	
	AdjacencyMap::iterator amit;
	for (amit = graph.begin(); amit != graph.end(); ++amit) {
		result += time(amit->first);
	}

	return result;
}

unsigned long Graph::time(Vertex current)
{
	typedef std::map<Vertex, int> DistanceMap;
	DistanceMap distances;	// keeps track of the minimum distances
	std::set<std::pair<int, Vertex> > queue;	// a set keeps the distances sorted

	// Dijkstra's algorithm

	// set initial distances to infinity
	AdjacencyMap::iterator amit;
	for (amit = graph.begin(); amit != graph.end(); ++amit) {
		distances[amit->first] = std::numeric_limits<int>::max();
	}

	// set the distane of the first vertex to 0
	distances[current] = 0;

	// add an edge to itself to the queue
	queue.insert(std::make_pair(distances[current], current));

	while (!queue.empty()) {
		// dequeue the lowest cost edge
		Vertex v = queue.begin()->second;
		queue.erase(queue.begin());

		const EdgeList &edges = graph.find(v)->second;
		EdgeList::const_iterator elit;
		for (elit = edges.begin(); elit != edges.end(); ++elit) {
			Vertex dest = elit->dest;
			int time = elit->time + distances[v];	// the total cost of going to this new vertex

			// store the shortest distance and queue the vertex
			if (time < distances[dest]) {
				distances[dest] = time;
				queue.insert(std::make_pair(time, dest));
			}
		}
	}

	int result = 0;
	DistanceMap::iterator dmit;
	for (dmit = distances.begin(); dmit != distances.end(); ++dmit) {
		result += dmit->second;
	}

	return result;
}
