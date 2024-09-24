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
	try {
		std::vector<Object> newVec;
		std::string readLine;
		std::ifstream readFile(file);
		if (!readFile.is_open()) {
			throw std::runtime_error("File not open");
		}
		while (std::getline(readFile, readLine)) {
			Object obj(readLine);
			newVec.push_back(obj);
		}
		objects = newVec;
		return true;
	}
	catch (std::exception e) {
		std::cout << std::endl << e.what() << std::endl;
		return false;
	}
}

bool ListOfObjects::saveObjectsToFile(std::string file) {
	try {
		std::ofstream writeFile(file);
		for (int i = 0; i < objects.size(); ++i) {
			writeFile << objects[i].toString() + "\n";
		}
		writeFile.close();
	}
	catch (std::exception e) {
		std::cout << std::endl << e.what() << std::endl;
		return false;
	}
	return true;
}