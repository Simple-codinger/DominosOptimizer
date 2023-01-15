#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>

class Graph {
	private:
		int V;
		std::vector<std::pair<int, float>>* adjList;
	public:
		Graph(int V);
		void addEdge(int u, int v, float w);
		void shortestPath(int s, int d);
		~Graph();
};
#endif
