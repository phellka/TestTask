#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "Models\Object.h"
#include "Models\ObjectFactory.h"

class ObjectFileManager
{
public:
	static bool loadObjectsFrmFile(std::string file, std::vector<Object*>& objects);
	static bool saveObjectsToFile(std::string file, const std::vector<Object*>& objects);
};

