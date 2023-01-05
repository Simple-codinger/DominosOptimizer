#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

class Graph {
	private:
		int V;
		std::vector<std::pair<int, int>>* adjList;
	public:
		Graph(int V);
		void addEdge(int u, int v, int w);
		void shortestPath(int s, int d);
};
#endif
