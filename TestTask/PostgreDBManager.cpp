#include "PostgreDBManager.h"

bool PostgreDBManager::loadObjectsFrmDb(std::vector<Object*>& objects)
{
	std::string conninfo = std::format("dbname={} user={} password={} host={} port={}", 
		dbname, dbuser, dbpass, dbhost, dbport);
    PGconn* conn = PQconnectdb(conninfo.data());
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cout << "Error while connecting to the database server: %s\n" << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);

        return false;
    }

    std::string query = "select obj.name, obj.coordinate_x, obj.coordinate_y, obj.type, obj.creationtime, car.maxspeed, hum.surname from object obj Left Join car on obj.id = car.obj_id Left Join human hum on obj.id = hum.obj_id";
    PGresult* res = PQexec(conn, query.data());
    ExecStatusType resStatus = PQresultStatus(res);
    if (resStatus != PGRES_TUPLES_OK) {
        std::cout << "Error while executing the query: %s\n" << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return false;
    }

    std::vector<Object*> newVec;
    int rows = PQntuples(res);
    int cols = PQnfields(res);
    for (int i = 0; i < rows; i++) {
        std::string row;
        for (int j = 0; j < cols; j++) {
            std::string cell = PQgetvalue(res, i, j);
            row += cell;
            if ((j < cols - 1) && (cell != "")) {
                row += " ";
            }
        }
        try {
            Object* obj = ObjectFactory::createObject(row);
            newVec.push_back(obj);
        }
        catch (std::exception& e) {
            for (auto p : newVec)
            {
                delete p;
            }
            PQclear(res);
            PQfinish(conn);
            std::cout << std::endl << e.what() << std::endl;
            return false;
        }
    }
    for (auto p : objects)
    {
        delete p;
    }
    objects.clear();
    objects = newVec;

    PQfinish(conn);
	return true;
}

bool PostgreDBManager::addObjectToDB(Object* obj)
{
    std::string conninfo = std::format("dbname={} user={} password={} host={} port={}",
        dbname, dbuser, dbpass, dbhost, dbport);
    PGconn* conn = PQconnectdb(conninfo.data());
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cout << "Error while connecting to the database server: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return false;
    }

    std::string objectQuery = std::format("INSERT INTO Object (name, coordinate_x, coordinate_y, type, creationTime) VALUES ('{}', {}, {}, '{}', {}) RETURNING id",
        obj->name, obj->coordinate_X, obj->coordinate_Y,
        obj->type, obj->creationTime);

    PGresult* res = PQexec(conn, objectQuery.data());
    ExecStatusType resStatus = PQresultStatus(res);

    if (resStatus != PGRES_TUPLES_OK) {
        std::cout << "Error while executing the insert into Object: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return false;
    }

    int objectId = std::stoi(PQgetvalue(res, 0, 0));
    PQclear(res);
    if (auto* car = dynamic_cast<Cars*>(obj)) {
        std::string carQuery = std::format("INSERT INTO Car (obj_id, maxSpeed) VALUES ({}, {})",
            objectId, car->maxSpeed);
        res = PQexec(conn, carQuery.data());
        resStatus = PQresultStatus(res);

        if (resStatus != PGRES_COMMAND_OK) {
            std::cout << "Error while executing the insert into Car: " << PQerrorMessage(conn) << std::endl;
            PQclear(res);
            PQfinish(conn);
            return false;
        }
        PQclear(res);
    }
    else if (auto* human = dynamic_cast<Human*>(obj)) {
        std::string humanQuery = std::format("INSERT INTO Human (obj_id, surname) VALUES ({}, '{}')",
            objectId, human->surname);
        res = PQexec(conn, humanQuery.data());
        resStatus = PQresultStatus(res);

        if (resStatus != PGRES_COMMAND_OK) {
            std::cout << "Error while executing the insert into Human: " << PQerrorMessage(conn) << std::endl;
            PQclear(res);
            PQfinish(conn);
            return false;
        }
        PQclear(res);
    }
    else if (auto* genericObject = dynamic_cast<GenericObject*>(obj)) {
    }
    else {
        std::cout << "Unknown object type" << std::endl;
        PQfinish(conn);
        return false;
    }
    PQfinish(conn);
	return true;
}
