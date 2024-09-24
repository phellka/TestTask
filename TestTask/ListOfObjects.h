#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

#include "Models\Object.h"
#include "ObjectFileManager.h"
#include "ObjectGrouper.h"


class ListOfObjects
{
private:
	std::vector<Object*> objects;

public:
	int length();
	bool addObject(Object* obj);
	bool loadObjectsFrmFile(std::string file);
	bool saveObjectsToFile(std::string file);

	static void printGroupedObjects(std::map <std::string, std::vector<Object*>>* groups);
	std::map<std::string, std::vector<Object*>> groupByDistance();
	std::map<std::string, std::vector<Object*>> groupByName();
	std::map<std::string, std::vector<Object*>> groupByType(int n);

	std::vector<Object*> getObjects() const {
		return objects;
	}

	~ListOfObjects();
};

