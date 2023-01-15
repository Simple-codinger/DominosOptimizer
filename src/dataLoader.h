#ifndef DATALOADER_H
#define DATALOADER_H

#include<vector>
#include<string>
#include "pizza.h"
#include "toping.h"
#include <SQLiteCpp/SQLiteCpp.h>

class DataLoader {
	private:
		std::vector<Toping*> _topings;
		std::vector<Pizza*> _pizzas;
		std::string _databaseLocation;
		SQLite::Database _database;
		
		Pizza* _getPizzaById(int id);
		Toping* _getTopingById(int id);
	public:
		DataLoader(std::string dbName) : _databaseLocation(dbName), _database(dbName){};
		void loadData();
		inline std::vector<Pizza*> getPizzas() {return this->_pizzas;};
		~DataLoader();
};
#endif
