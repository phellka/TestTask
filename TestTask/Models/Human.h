#pragma once

#include <iostream>

#include "Object.h"

class Human : public Object
{
public:
	std::string surname;

	Human(const std::string& str) {
		std::istringstream iss(str);
		if (!(iss >> name >> coordinate_X >> coordinate_Y >> type >> creationTime >> surname)) {
			throw std::invalid_argument("Invalid format for Object initialization");
		}

		if (creationTime < 0) {
			throw std::invalid_argument("Time must be non-negative");
		}
	}

	operator std::string() const {
		return std::format("{} {} {} {} {} {}", name, coordinate_X, coordinate_Y, type, creationTime, surname);
	}
};

