#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <format>

class Object
{
public:
	std::string name;
	double coordinate_X;
	double coordinate_Y;
	std::string type;
	double creationTime;

	Object() {}

	virtual operator std::string() const = 0;

	std::string toString() const{
		return *this;
	}
};

