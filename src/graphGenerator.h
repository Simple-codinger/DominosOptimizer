#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include "graph.h"
#include "pizza.h"
#include "toping.h"

#include<vector>
#include <algorithm>

class GraphGenerator {
	private:
		bool hasToping(Pizza& pizza, Toping& toping);
	public:
		int SourceVertex;
		GraphGenerator(): SourceVertex(0) {};
		Graph generateGraph(std::vector<Pizza*>& pizzas);
		inline static Pizza* getPizzaFromVertex(std::vector<Pizza*>& pizzas, int v) {
			return pizzas.at(v-1);
		}
};
#endif	
