#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <libpq-fe.h>


#include "Models\Object.h"
#include "Models\ObjectFactory.h"
#include "AbstractDBManager.h"

class PostgreDBManager : public AbstractDBManager
{
private:
    std::string dbhost = "localhost";
    int         dbport = 5433;
    std::string dbname = "postgres";
    std::string dbuser = "postgres";
    std::string dbpass = "postgres";

public:
	bool loadObjectsFrmDb(std::vector<Object*>& objects);
	bool addObjectToDB(Object* obj);
};

