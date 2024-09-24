#pragma once

#include <iostream>

#include "Object.h"


class Cars : public Object 
{
public:
	int maxSpeed;

	Cars(const std::string& str) {
		std::istringstream iss(str);
		if (!(iss >> name >> coordinate_X >> coordinate_Y >> type >> creationTime >> maxSpeed)) {
			throw std::invalid_argument("Invalid format for Object initialization");
		}

		if (creationTime < 0) {
			throw std::invalid_argument("Time must be non-negative");
		}
	}

	operator std::string() const {
		return std::format("{} {} {} {} {} {}", name, coordinate_X, coordinate_Y, type, creationTime, maxSpeed);
	}

};

