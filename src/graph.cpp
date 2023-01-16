#include "graph.h"

Graph::Graph(int V) {
	this->V = V;
	this->adjList = new std::vector<std::pair<int, float>>[V];
	this->Distances = new float[V];
	this->Predecessor = new int[V];
}

void Graph::addEdge(int u, int v, float w) {
	// std::cout << "addEdge: " << u << " --> " << v << " | weight: " << w << std::endl;
	this->adjList[u].push_back(std::make_pair(v, w));
	//this->adjList[v].push_back(std::make_pair(u, w));
}

int Graph::calculateDistances(int s){
	// Step 1: Initialize distances with infinte
	for(int i=0; i<this->V; ++i){
		this->Distances[i] = std::numeric_limits<float>::max();
	}
	this->Distances[s] = 0;
	// Step 2: Relax all edges |V| - 1 times
	for(int i=1; i<=this->V-1; i++){
		// iterate through adjList
		for (int j=0; j<this->V; ++j){
			for(std::pair<int, float>& edge : this->adjList[j]) {
				int u = j;
				int v = std::get<0>(edge);
				float weight = std::get<1>(edge);
				if(this->Distances[u] != std::numeric_limits<float>::max() && this->Distances[u] + weight < this->Distances[v]){
					this->Distances[v] = this->Distances[u] + weight;
					this->Predecessor[v] = u;
				}
			}
		}
	}
	
	// Step 3: Check for negative cycles
	for (int j=0; j<this->V; ++j){
		for(std::pair<int, float>& edge : this->adjList[j]) {
			int u = j;
			int v = std::get<0>(edge);
			float weight = std::get<1>(edge);
			if(this->Distances[u] != std::numeric_limits<float>::max() && this->Distances[u] + weight < this->Distances[v]){
				return -1;
			}
		}
	}
	return 1;
}

Graph::~Graph(){
	delete[] this->adjList;
	delete[] this->Distances;
	delete[] this->Predecessor;
}

void Graph::printPredecessor(int* pre, int source, int v) {
	std::cout << v << "-->";
	int u = pre[v];
	while(u != source) {
		std::cout << u << "-->";
		u = pre[u];
	}
	std::cout << source << std::endl;
}

std::stack<int> Graph::getPath(int v) {
	std::stack<int> stack;
	while (v != 0) {
		stack.push(v);
		v = this->Predecessor[v];
	}
	return stack;
}
