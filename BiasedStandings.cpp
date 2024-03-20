#include <iostream>
#include <set>
//#include <math.h>

int main() {
	int cases;
	int teams;
	std::multiset<int> preferred;
	int preference;
	std::string name;
	uint64_t badness;
	int place;

	std::cin >> cases;
	
	for (int i = 0; i < cases; i++) {
		preferred = {};

		std::cin >> teams;
		for (int n = 0; n < teams; n++) {
			std::cin >> name >> preference;

			preferred.insert(preference);
		}

		badness = 0;
		place = 1;
		for (int p : preferred)
		{
			badness += abs(place - p);
			place++;
		}
		std::cout << badness << std::endl;
	}
}