#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "Object.h"

class ObjectGrouper
{
public:
	static std::map <std::string, std::vector<Object>>groupByDistance(const std::vector<Object>& objects);
	static std::map <std::string, std::vector<Object>>groupByName(const std::vector<Object>& objects);
	static std::map <std::string, std::vector<Object>>groupByType(int n, const std::vector<Object>& objects);
};

