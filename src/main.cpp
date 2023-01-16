#include <iostream>
#include "toping.h"
#include "pizza.h"
#include "dataLoader.h"
#include "graph.h"
#include <vector>
#include "graphGenerator.h"

int main() {
	DataLoader dl("database.db");	
	dl.loadData();
	std::vector<Pizza*> pizzas = dl.getPizzas();

	GraphGenerator gg;
	Graph graph = gg.generateGraph(pizzas);
	int res = graph.calculateDistances(0);
	if(res != 1) {
		std::cerr << "Negative cycles occured" << std::endl;
	}
	std::cout << "Print distances:" << std::endl;
	for(int i=0; i<graph.V; ++i) {
		std::cout << "V: " << i << " | Distance: " << graph.Distances[i] << std::endl;
	}
}
