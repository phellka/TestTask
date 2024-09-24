#include "ListOfObjects.h"

int ListOfObjects::length()
{
	return objects.size();
}

bool ListOfObjects::addObject(Object obj)
{
	objects.push_back(obj);
	return true;
}

bool ListOfObjects::loadObjectsFrmFile(std::string file)
{
	return ObjectFileManager::loadObjectsFrmFile(file, objects);
}

bool ListOfObjects::saveObjectsToFile(std::string file) {
	return ObjectFileManager::saveObjectsToFile(file, objects);
}

std::map<std::string, std::vector<Object>> ListOfObjects::groupByDistance() {
	return ObjectGrouper::groupByDistance(objects);
}

std::map<std::string, std::vector<Object>> ListOfObjects::groupByName() {
	return ObjectGrouper::groupByName(objects);
}

std::map<std::string, std::vector<Object>> ListOfObjects::groupByType(int n) {
	return ObjectGrouper::groupByType(n, objects);
}

void ListOfObjects::printGroupedObjects(std::map<std::string, std::vector<Object>>* groups)
{
	for (const auto& group : *groups) {
		std::cout << "Group: " << group.first << std::endl;
		for (const Object& obj : group.second) {
			std::cout << "  " << obj.toString() << std::endl;
		}
	}
}