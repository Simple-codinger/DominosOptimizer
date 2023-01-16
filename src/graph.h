#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
#include <limits>

class Graph {
	private:
		std::vector<std::pair<int, float>>* adjList;
	public:
		int V;
		float* Distances;
		Graph(int V);
		void addEdge(int u, int v, float w);
		void shortestPath(int s, int d);
		int calculateDistances(int s);	
		~Graph();
};
#endif
