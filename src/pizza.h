#ifndef PIZZA_H
#define PIZZA_H

#include<iostream>
#include "toping.h"
#include<vector>
#include<string>

class Pizza{
	private:
		std::vector<Toping*> _toppings;
		int _id;
		float _price;
		std::string _name;
	public:
		Pizza(){};	
		Pizza(std::vector<Toping*> topings, std::string name, float price): _toppings(topings), _name(name), _price(price) {};
		Pizza(int id, std::string name, float price): _id(id), _name(name), _price(price){};
		Pizza(std::string name, float price): _name(name), _price(price){};
		inline void setToppings(std::vector<Toping*>& toppings){this->_toppings = toppings;};
		inline std::vector<Toping*> getToppings(){return this->_toppings;};
		inline void addToping(Toping* toping){this->_toppings.push_back(toping);};
		inline int getId(){return this->_id;};
		inline float getPrice(){return this->_price;};
		friend std::ostream & operator<<(std::ostream & _stream, const Pizza &pizza);
		inline std::string getName() const{
			return this->_name;
		};
};

inline std::ostream & operator<<(std::ostream & _stream, const Pizza &pizza) {
	return _stream << pizza.getName();
};

#endif
