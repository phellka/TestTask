#pragma once

#include <iostream>
#include <vector>


#include "Models\Object.h"
#include "Models\ObjectFactory.h"

class AbstractDBManager
{
public:
	virtual bool loadObjectsFrmDb(std::vector<Object*>& objects) = 0;
	virtual bool addObjectToDB(Object* obj) = 0;
};

