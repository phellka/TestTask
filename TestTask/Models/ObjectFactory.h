#pragma once

#include <iostream>

#include "Object.h"
#include "Cars.h"
#include "Human.h"
#include "GenericObject.h"

class ObjectFactory
{
public:
	static Object* createObject(const std::string& str) {
		Object* newObj = new GenericObject(str);
		if (newObj->type == "Car") {
			delete newObj;
			newObj = new Cars(str);
		}
		if (newObj->type == "Human") {
			delete newObj;
			newObj = new Human(str);
		}
		return newObj;
	}
};

