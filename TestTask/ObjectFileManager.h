#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "Object.h"

class ObjectFileManager
{
public:
	static bool loadObjectsFrmFile(std::string file, std::vector<Object>& objects);
	static bool saveObjectsToFile(std::string file, const std::vector<Object>& objects);
};

