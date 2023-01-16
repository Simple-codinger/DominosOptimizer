#include "dataLoader.h"

void DataLoader::loadData() {
	// load topings
	SQLite::Statement query(this->_database, "SELECT * FROM toppings");
	while (query.executeStep()) {
		int id = query.getColumn(query.getColumnIndex("id"));
		std::string name = query.getColumn(query.getColumnIndex("name"));
		double price = query.getColumn(query.getColumnIndex("price"));
		Toping* toping = new Toping(id, name, price);
		this->_topings.push_back(toping);
	}
	
	// load pizzas
	SQLite::Statement pizzaQuery(this->_database, "SELECT * FROM pizzas");
	while (pizzaQuery.executeStep()) {
		int id = pizzaQuery.getColumn(pizzaQuery.getColumnIndex("id"));
		std::string name = pizzaQuery.getColumn(pizzaQuery.getColumnIndex("name"));
		double price = pizzaQuery.getColumn(pizzaQuery.getColumnIndex("price"));
		Pizza* pizza = new Pizza(id, name, price);
		this->_pizzas.push_back(pizza);
	}	
	// add topings to pizza
	SQLite::Statement ptQuery(this->_database, "SELECT * FROM pizzaToppings");
	while (ptQuery.executeStep()) {
		int topingId = ptQuery.getColumn(ptQuery.getColumnIndex("topingId"));
		int pizzaId = ptQuery.getColumn(ptQuery.getColumnIndex("pizzaId"));
		// load toping
		Toping* toping = this->_getTopingById(topingId);
		if (toping == nullptr) {
			std::cerr << "Foreign key is broken. TopingId: " << topingId << std::endl;
			break;
		}
		Pizza* pizza = this->_getPizzaById(pizzaId);
		if (pizza == nullptr) {
			std::cerr << "Foreign key is broken. PizzaId: " << pizzaId << std::endl;
			break;
		}
		pizza->addToping(toping);
	}
	/*
	for (int i = 0; i < this->_pizzas.size(); ++i){
		std::cout << "Pizza: " << *this->_pizzas.at(i) << " | Toppings: ";
		for (int j = 0; j < this->_pizzas.at(i)->getToppings().size(); ++j) {
			std::cout << " " << *this->_pizzas.at(i)->getToppings().at(j);
		}
		std::cout << std::endl;
	}
	*/
}

Pizza* DataLoader::_getPizzaById(int id) {
	Pizza* pizza = nullptr;
	for(int i = 0; i < this->_pizzas.size(); ++i) {
		if(this->_pizzas.at(i)->getId() == id) {
			pizza = this->_pizzas.at(i);
			break;
		}	
	}
	return pizza;
}

Toping* DataLoader::_getTopingById(int id) {
	Toping* toping = nullptr;
	for(int i = 0; i < this->_topings.size(); ++i) {
		if(this->_topings.at(i)->getId() == id) {
			toping = this->_topings.at(i);
			break;
		}	
	}
	return toping;
}

DataLoader::~DataLoader() {
	for(int i = 0; i < this->_topings.size(); ++i) {
		free(this->_topings.at(i));
	}
	for(int i = 0; i < this->_pizzas.size(); ++i) {
		free(this->_pizzas.at(i));
	}
}
