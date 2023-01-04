#ifndef PIZZA_H
#define PIZZA_H

#include<iostream>
#include "toping.h"
#include<vector>
#include<string>

class Pizza{
	private:
		std::vector<Toping*> _topings;
		float _price;
		std::string _name;
	public:
		Pizza(){};	
		Pizza(std::vector<Toping*> topings, std::string name, float price): _topings(topings), _name(name), _price(price) {};
		Pizza(std::string name, float price): _name(name), _price(price){};
		inline void setTopings(std::vector<Toping*>& topings){this->_topings = topings;};
		friend std::ostream & operator<<(std::ostream & _stream, const Pizza &pizza);
		inline std::string getName() const{
			return this->_name;
		};
};

inline std::ostream & operator<<(std::ostream & _stream, const Pizza &pizza) {
	return _stream << pizza.getName();
};

#endif
