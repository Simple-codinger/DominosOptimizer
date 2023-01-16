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
	int res = graph.calculateDistances(0);
	if(res != 1) {
		std::cerr << "Negative cycles occured" << std::endl;
	}

	for(int i = 0; i<pizzas.size(); ++i) {
		std::cout << i+1 << ": " << *(pizzas.at(i)) << std::endl;
	}

	std::cout << std::endl << "Enter pizza number: ";
	int n = 0;
	std::cin >> n;

	std::cout << std::endl << *(pizzas.at(n-1)) << " | Normal price: " << pizzas.at(n-1)->getPrice() << " | Best price: " << graph.Distances[n] << std::endl;

	std::cout << "Order process: ";
	std::stack<int> path = graph.getPath(n);
	while (!path.empty()) {
		std::cout << *(pizzas.at(path.top() - 1));
		path.pop();
		if (!path.empty()) {
			std::cout << "-->";
		}
	}
	std::cout<<std::endl;
}
