#include "dataLoader.h"


DataLoader::DataLoader(std::string db) {
	this->_databaseLocation = db;
	int rc = sqlite3_open(this->_databaseLocation.c_str(), &(this->_db));
	
	// check if database connection was successfull
	if (rc) {
		std::cerr << "Failed to open database" << std::endl;
		return;
	}	
}

DataLoader::~DataLoader() {
	sqlite3_close(this->_db);
	// sqlite3_close(db);
}
