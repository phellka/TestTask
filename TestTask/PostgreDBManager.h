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
    int         dbport = 5432;
    std::string dbname = "postgres";
    std::string dbuser = "postgres";
    std::string dbpass = "12345678";

public:
	bool loadObjectsFrmDb(std::vector<Object*>& objects);
	bool addObjectToDB(Object* obj);
};

