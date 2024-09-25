#include "ListOfObjects.h"

ListOfObjects::~ListOfObjects()
{
	for (auto p : objects)
	{
		delete p;
	}
	objects.clear();
	delete dbManager;
}

ListOfObjects::ListOfObjects()
{
	dbManager = new PostgreDBManager();
}

int ListOfObjects::length()
{
	return objects.size();
}

bool ListOfObjects::addObject(Object* obj)
{
	bool res = dbManager->addObjectToDB(obj);
	if (res) {
		objects.push_back(obj);
	}
	return res;
}

bool ListOfObjects::loadObjectsFrmDB()
{
	return dbManager->loadObjectsFrmDb(objects);;
}


std::map<std::string, std::vector<Object*>> ListOfObjects::groupByDistance() {
	return ObjectGrouper::groupByDistance(objects);
}

std::map<std::string, std::vector<Object*>> ListOfObjects::groupByName() {
	return ObjectGrouper::groupByName(objects);
}

std::map<std::string, std::vector<Object*>> ListOfObjects::groupByType(int n) {
	return ObjectGrouper::groupByType(n, objects);
}

void ListOfObjects::printGroupedObjects(std::map<std::string, std::vector<Object*>>* groups)
{
	for (const auto& group : *groups) {
		std::cout << "Group: " << group.first << std::endl;
		for (const Object* obj : group.second) {
			std::cout << "  " << obj->toString() << std::endl;
		}
	}
}