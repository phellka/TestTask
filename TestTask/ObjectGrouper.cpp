#include "ObjectGrouper.h"


std::map<std::string, std::vector<Object>> ObjectGrouper::groupByDistance(const std::vector<Object>& objects)
{
	std::map<std::string, std::vector<Object>> groups = std::map<std::string, std::vector<Object>>();
	for (int i = 0; i < objects.size(); ++i) {
		double distance = std::abs(objects[i].coordinate_X) + std::abs(objects[i].coordinate_Y);
		std::string key;
		if (distance < 100) {
			key = "before 100";
		}
		else if (distance < 500) {
			key = "before 500";
		}
		else if (distance < 1000) {
			key = "before 1000";
		}
		else {
			key = "too far away";
		}
		groups[key].push_back(objects[i]);
	}

	for (auto& group : groups) {
		std::sort(group.second.begin(), group.second.end(), [](const Object& lhs, const Object& rhs) {
			int ldst = std::abs(lhs.coordinate_X) + std::abs(lhs.coordinate_Y);
			int rdst = std::abs(rhs.coordinate_X) + std::abs(rhs.coordinate_Y);
			return ldst < rdst;
			});
	}


	return groups;
}

std::map<std::string, std::vector<Object>> ObjectGrouper::groupByName(const std::vector<Object>& objects)
{
	std::map<std::string, std::vector<Object>> groups = std::map<std::string, std::vector<Object>>();
	for (int i = 0; i < objects.size(); ++i) {
		char firstChar = objects[i].name[0];
		if (!std::isalpha(firstChar)) {
			firstChar = '#';
		}
		else {
			firstChar = std::toupper(firstChar);
		}
		groups[std::string(1, firstChar)].push_back(objects[i]);
	}

	for (auto& group : groups) {
		std::sort(group.second.begin(), group.second.end(), [](const Object& lhs, const Object& rhs) {
			return lhs.name < rhs.name;
			});
	}

	return groups;
}

std::map<std::string, std::vector<Object>> ObjectGrouper::groupByType(int n, const std::vector<Object>& objects)
{
	std::map<std::string, std::vector<Object>> groups = std::map<std::string, std::vector<Object>>();
	std::map<std::string, int> buf;
	for (int i = 0; i < objects.size(); ++i) {
		buf[objects[i].type] += 1;
	}
	for (int i = 0; i < objects.size(); ++i) {
		std::string key = (buf[objects[i].type] <= n) ? "different" : objects[i].type;
		groups[key].push_back(objects[i]);
	}

	for (auto& group : groups) {
		std::sort(group.second.begin(), group.second.end(), [](const Object& lhs, const Object& rhs) {
			return lhs.name < rhs.name;
			});
	}

	return groups;
}