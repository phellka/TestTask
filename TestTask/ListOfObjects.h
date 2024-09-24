#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

#include "Object.h"


class ListOfObjects
{
private:
	std::vector<Object> objects;


public:
	int length();
	bool addObject(Object obj);
	bool loadObjectsFrmFile(std::string file);
	bool saveObjectsToFile(std::string file);

	std::map <std::string, std::vector<Object>>groupByDistance();
	std::map <std::string, std::vector<Object>>groupByName();
	std::map <std::string, std::vector<Object>>groupByType(int n);
	static void printGroupedObjects(std::map <std::string, std::vector<Object>>* groups);
};

