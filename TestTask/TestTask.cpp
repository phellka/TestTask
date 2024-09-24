#include <iostream>

#include "Object.h"
#include "ListOfObjects.h"

ListOfObjects listOfObjects;

int main()
{
    std::cout << "App for processing list of obects" << std::endl;
    while(true) {
        std::cout << std::endl << std::endl;
        std::cout << "Write:\n 0 for info,\n 1 for read list from file,\n 2 for add object,\n" 
            << " 3 for group objects,\n 4 for save list in file,\n 5 for list length,\n 8 for exit" << std::endl << "answer:";
        int ans;
        std::cin >> ans;
        std::cout << std::endl;
        switch (ans)
            {
            case 0: {
                std::cout << "The program is a simple application for managing a list of objects, where users can add, upload and save objects. The main focus is on grouping objects and working with files and processing user input." << std::endl;
                break;
            }
            case 1: {
                std::cout << "wrtie file name:";
                std::string file;
                std::cin >> file;
                std::cout << std::endl;
                bool result = listOfObjects.loadObjectsFrmFile(file);
                if (result) {
                    std::cout << "load successfully" << std::endl;
                }
                else {
                    std::cout << "load saved" << std::endl;
                }
                break;
                break;
            }
            case 2: {
                std::cout << "enter the name of the object separated by a space:\n Name\n Coordinate X\n Coordinate Y\n Type of object\n Creation time:" << std::endl;
                std::string stringObj;
                std::getline(std::cin, stringObj);
                while (stringObj.length() == 0)
                    std::getline(std::cin, stringObj);
                std::cout << std::endl;
                try {
                    Object obj(stringObj);
                    listOfObjects.addObject(obj);
                    std::cout << "Successfully added" << std::endl;
                }
                catch (std::exception e) {
                    std::cout << e.what() << std::endl;
                    std::cout << "Not added" << std::endl;
                }
                break;
            }
            case 3: {
                std::map<std::string, std::vector<Object>> groups;
                std::cout << "What type of group? 1 for distance, 2 for name, 3 for type" << std::endl;
                int grAns;
                std::cin >> grAns;
                switch (grAns)
                {
                    case 1: {
                        groups = listOfObjects.groupByDistance();
                        break;
                    }
                    case 2: {
                        groups = listOfObjects.groupByName();
                        break;
                    }
                    case 3: {
                        std::cout << "grouping more than n objects, n:";
                        int n;
                        std::cin >> n;
                        std::cout << std::endl;
                        groups = listOfObjects.groupByType(n);
                        break;
                    }
                }
                ListOfObjects::printGroupedObjects(&groups);

                break;
            }
            case 4: {
                std::cout << "wrtie file name:";
                std::string file;
                std::cin >> file;
                std::cout << std::endl;
                bool result = listOfObjects.saveObjectsToFile(file);
                if (result) {
                    std::cout << "saved successfully" << std::endl;
                }
                else {
                    std::cout << "not saved" << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "List length: " << listOfObjects.length() << std::endl;
                break;
            }
            case 8: {
                std::cout << "Are you sure, save file before close: Yes(y), No(n)" << std::endl;
                std::string ans;
                std::cin >> ans;
                if (std::tolower(ans[0]) == 'y') {
                    return 0;
                }
                break;
            }
            default:
                break;
        }
    }
}

