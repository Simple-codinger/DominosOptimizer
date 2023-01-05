#ifndef DATALOADER_H
#define DATALOADER_H

#include<vector>
#include<string>
#include "pizza.h"
#include "toping.h"
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>

class DataLoader {
	private:
		std::vector<Toping*> _topings;
		std::vector<Pizza*> _pizzas;
		std::string _databaseLocation;
		sqlite3* _db;
		int _callback(void *data, int argc, char **argv, char **azColName); 
	public:
		DataLoader(std::string db);
		~DataLoader();
};
#endif
