#include "graph.h"

Graph::Graph(int V) {
	this->V = V;
	this->adjList = new std::vector<std::pair<int, int>>(V);	
}

void Graph::addEdge(int u, int v, int w) {
	this->adjList[u].push_back(std::make_pair(v, w));
	this->adjList[v].push_back(std::make_pair(u, w));
}

void Graph::shortestPath(int src, int dest){
	return;
}

