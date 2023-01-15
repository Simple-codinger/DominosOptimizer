#ifndef TOPING_H	
#define TOPING_H

#include<string>
#include<iostream>

class Toping{
	private:
		int _id;
		float _price;
		std::string _name;
	public:
		Toping(){};
		Toping(int id, std::string name, float price): _id(id), _price(price), _name(name){};
		Toping(std::string name, float price): _price(price), _name(name){};
		inline void setPrice(float price){this->_price = price;};	
		inline float getPrice() {return this->_price;};
		inline void setName(std::string name){this->_name = name;};
		inline std::string getName() const{return this->_name;};
		inline int getId(){return this->_id;};
		friend std::ostream & operator<<(std::ostream & _stream, const Toping &tp);
};
inline std::ostream & operator<<(std::ostream & _stream, const Toping &tp) {
	return _stream << tp.getName();
};
#endif
