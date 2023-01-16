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
		Graph generateGraph(std::vector<Pizza*>& pizzas);
};
#endif	
