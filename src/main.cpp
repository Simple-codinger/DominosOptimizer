#include <iostream>
#include <sqlite3.h>
#include "toping.h"
#include "pizza.h"
#include "dataLoader.h"
#include <vector>

static int callback(void *data, int argc, char **argv, char **azColName) {
	for (int i = 0; i < argc; ++i){
		std::cout << azColName[i] << (argv[i] ? argv[i] : "NULL") << std::endl;
	}
	return 0;
}

int main() {
	std::cout << "Hello World" << std::endl;
	Toping testToping = Toping("Salami", 2.10);
	std::cout << "TestToping: " << testToping << std::endl;
	Pizza pizza = Pizza("Luca", 10.99);
	std::cout << "TestPizza: " << pizza << std::endl;
	std::vector<Toping> topings;
	std::vector<Pizza> pizzas;
	
	DataLoader dl("database.db");	

	char *errMsg = 0;
	const char* data = "Callback function called";

	// rc = sqlite3_exec(db, "SELECT * FROM pizzas", callback, (void*) data, &errMsg);
	// sqlite3_close(db);
}
