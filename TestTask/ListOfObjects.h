#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

#include "Models\Object.h"
#include "ObjectGrouper.h"
#include "PostgreDBManager.h"
#include "AbstractDBManager.h"


class ListOfObjects
{
private:
	std::vector<Object*> objects;
	AbstractDBManager* dbManager;

public:
	ListOfObjects();
	~ListOfObjects();

	int length();
	bool addObject(Object* obj);
	bool loadObjectsFrmDB();

	static void printGroupedObjects(std::map <std::string, std::vector<Object*>>* groups);
	std::map<std::string, std::vector<Object*>> groupByDistance();
	std::map<std::string, std::vector<Object*>> groupByName();
	std::map<std::string, std::vector<Object*>> groupByType(int n);

	std::vector<Object*> getObjects() const {
		return objects;
	}
};

