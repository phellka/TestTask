#include "ObjectFileManager.h"


bool ObjectFileManager::loadObjectsFrmFile(std::string file, std::vector<Object*>& objects)
{
	try {
		std::ifstream readFile(file);
		if (!readFile.is_open()) {
			throw std::runtime_error("File not open");
		}
		std::vector<Object*> newVec;
		std::string readLine;

		while (std::getline(readFile, readLine)) {
			Object* obj = ObjectFactory::createObject(readLine);
			newVec.push_back(obj);
		}
		for (auto p : objects)
		{
			delete p;
		}
		objects.clear();
		objects = newVec;
		return true;
	}
	catch (std::exception e) {
		std::cout << std::endl << e.what() << std::endl;
		return false;
	}
}

bool ObjectFileManager::saveObjectsToFile(std::string file, const std::vector<Object*>& objects) {
	try {
		std::ofstream writeFile(file);
		if (!writeFile.is_open()) {
			throw std::runtime_error("File not open");
		}
		for (int i = 0; i < objects.size(); ++i) {
			writeFile << objects.at(i)->toString() + "\n";
		}
		writeFile.close();
	}
	catch (std::exception e) {
		std::cout << std::endl << e.what() << std::endl;
		return false;
	}
	return true;
}