#include "graphGenerator.h"

Graph GraphGenerator::generateGraph(std::vector<Pizza*>& pizzas){
	Graph graph(pizzas.size()+1);
	// add start edges
	for(int i = 0; i<pizzas.size(); ++i) {
		graph.addEdge(0, i+1, pizzas.at(i)->getPrice());
	}

	// for each pizza, check which toppings must be removed and which have to be add to generate every other pizza
	// add negative price of most valueable topping (which is to removed) as edge weight
	for(int i = 0; i<pizzas.size(); ++i) {
		for(int j = 0; j<pizzas.size(); ++j) {
			if (i != j) {
				// remove all toppings from pizza i that are not needed in pizza j
				// remember highest price
				float highestPrice = 0;
				for(Toping* t : pizzas.at(i)->getToppings()) {
					if (!this->hasToping(*pizzas.at(j), *t)) {
						if (t->getPrice() > highestPrice) {
							highestPrice = t->getPrice();
						}
					}
				} 
				std::cout << "HighestPrice: " << highestPrice << std::endl;	
				// add toppings to pizza i to create pizza j
				// accumulate all prices
				float total = 0;
				for(Toping* t : pizzas.at(j)->getToppings()) {
					if (!this->hasToping(*pizzas.at(i), *t)) {
						total += t->getPrice();	
					}
				}
				std::cout << "Total: " << total << std::endl;	
				// addEdge(i+1, j+1, accumulatePrice-highestPrice)
				graph.addEdge(i+1, j+1, total-highestPrice);
			}
		}
	}
	return graph;
}


bool GraphGenerator::hasToping(Pizza& pizza, Toping& toping) {
	bool doesExist = false;
	for(Toping* t : pizza.getToppings()){
		if (t == &toping) {
			doesExist = true;
			break;
		}
	}
	return doesExist;
}
