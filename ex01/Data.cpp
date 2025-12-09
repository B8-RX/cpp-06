#include <iostream>
#include "Data.hpp"

Data::Data(void){
	_name = "unamed";
}

Data::Data(const std::string& name) {
	_name = name;
}

Data::~Data(void) {}

Data::Data(const Data& other) {
	*this = other;
}

Data&	Data::operator=(const Data& other) {
	if (this != &other)
		_name = other._name;
	return (*this);
}

const std::string&	Data::getName(void) const {
	return (_name);
}
