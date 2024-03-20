#include <iostream>

int main() {
	int animals;
	uint64_t tolls = 0;
	uint64_t flips = 1;
	uint64_t tollsAt = 1;
	char animal;

	std::cin >> animals;
	flips = flips << animals - 1;
	for (int i = 0; i < animals; i++) {
		std::cin >> animal;
		std::cin.ignore();

		if (animal == 'O')
		{
			tolls += flips;
		}
		flips = flips >> 1;
	}
	std::cout << tolls << std::endl;

	return 0;
}