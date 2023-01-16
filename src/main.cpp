#include <iostream>
#include "toping.h"
#include "pizza.h"
#include "dataLoader.h"
#include "graph.h"
#include <vector>
#include "graphGenerator.h"
#include <stack>

int main() {
	DataLoader dl("database.db");	
	dl.loadData();
	std::vector<Pizza*> pizzas = dl.getPizzas();

	GraphGenerator gg;
	Graph graph = gg.generateGraph(pizzas);
	int res = graph.calculateDistances(gg.SourceVertex);
	if(res != 1) {
		std::cerr << "Negative cycles occured" << std::endl;
	}

	for(int i = 0; i<pizzas.size(); ++i) {
		std::cout << i+1 << ": " << *(pizzas.at(i)) << std::endl;
	}

	std::cout << std::endl << "Enter pizza number: ";
	int n = 0;
	std::cin >> n;
	
	// bounce check
	if (n < 1 || n > pizzas.size()) {
		std::cerr << "Index out of range" << std::endl;
		return 1;
	}
	
	Pizza* pizza = GraphGenerator::getPizzaFromVertex(pizzas, n);	

	std::cout << std::endl << *(pizza) << " | Normal price: " << pizza->getPrice() << " | Best price: " << graph.Distances[n] << std::endl;

	std::cout << "Order process: ";
	std::stack<int> path = graph.getPath(n);
	while (!path.empty()) {
		std::cout << *(GraphGenerator::getPizzaFromVertex(pizzas, path.top()));
		path.pop();
		if (!path.empty()) {
			std::cout << "-->";
		}
	}
	std::cout<<std::endl;
}
