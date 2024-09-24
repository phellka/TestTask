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

	Object(std::string name, double coordinate_X, double coordinate_Y, std::string type, double creationTime) {
		this->name = name;
		this->coordinate_X = coordinate_X;
		this->coordinate_Y = coordinate_Y;
		this->type = type;
		this->creationTime = creationTime;
	}

	Object(const std::string& str) {
		std::istringstream iss(str);
		if (!(iss >> name >> coordinate_X >> coordinate_Y >> type >> creationTime)) {
			throw std::invalid_argument("Invalid format for Object initialization");
		}

		if (creationTime < 0) {
			throw std::invalid_argument("Time must be non-negative");
		}
	}

	operator std::string() const {
		return std::format("{} {} {} {} {}", name, coordinate_X, coordinate_Y, type, creationTime);
	}

	std::string toString() const{
		return *this;
	}
};

