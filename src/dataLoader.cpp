#include "dataLoader.h"


DataLoader::DataLoader(std::string db) {
	this->_databaseLocation = db;
	std::cout << db << std::endl;
	SQLite::Database testDb(db, SQLite::OPEN_READONLY);	
	// sqlite3_exec(db, "SELECT * FROM pizzas", this->_callback, (void*) data, &errMsg);
}

int DataLoader::_callback(void *data, int argc, char **argv, char **azColName) {
	for (int i = 0; i < argc; ++i){
		std::cout << azColName[i] << (argv[i] ? argv[i] : "NULL") << std::endl;
	}
	return 0;
}

DataLoader::~DataLoader() {
	sqlite3_close(this->_db);
}
