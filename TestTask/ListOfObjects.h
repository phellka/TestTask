#pragma once

#include <iostream>
#include <vector>
#include <fstream>

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
};

