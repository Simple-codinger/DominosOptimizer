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
}
