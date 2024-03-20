#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

std::vector<std::set<std::string>> tables;
std::unordered_map<std::string, std::vector<std::string>> declarations;

std::string find(std::string id) {
	auto it = declarations.find(id);
	if (it != declarations.end()) {
		if(!it->second.empty())
			return it->second.back();
	}
	return "";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	int lines;
	std::string statement, id, type;
	std::cin >> lines;
	tables.push_back({});

	for (int i = 0; i < lines; i++) {
		std::cin >> statement;
		if (statement == "TYPEOF") {
			std::cin >> id;
			type = find(id);
			if (type.empty()) {
				std::cout << "UNDECLARED\n";
			}
			else {
				std::cout << type << '\n';
			}
		}
		else if (statement == "DECLARE") {
			std::cin >> id >> type;

			if (tables[tables.size() - 1].find(id) != tables[tables.size() - 1].end()) {
				std::cout << "MULTIPLE DECLARATION\n";
				return 0;
			}
			tables[tables.size() - 1].insert(id);
			declarations[id].push_back(type);
		}
		else if (statement == "{") {
			tables.push_back({});
		}
		else if (statement == "}") {
			for (auto it = tables[tables.size() - 1].begin(); it != tables[tables.size() - 1].end(); it++) {
				declarations[*it].pop_back();
			}
			tables.pop_back();
		}
	}
	std::cout << std::endl;
	return 0;
}