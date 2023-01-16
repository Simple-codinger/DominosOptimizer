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
		int* Predecessor;
		Graph(int V);
		void addEdge(int u, int v, float w);
		void shortestPath(int s, int d);
		int calculateDistances(int s);	
			
		static void printPredecessor(int* Predecessor, int source, int v);

		~Graph();
};
#endif
