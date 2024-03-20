 #include <iostream>
#include <set>
#include <iterator>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	int a[100] = { 0 }, b[100] = { 0 };
	int lines = 0, sum, max, val, aVal, bVal, aCount, bCount;
	std::cin >> lines;

	for (int i = 0; i < lines; i++) {
		std::cin >> val;
		a[val - 1]++;
		std::cin >> val;
		b[val - 1]++;
		aCount = 0;
		bCount = 0;

		max = -1;
		aVal = 1;
		bVal = 100;

		while (true) {

			if (aCount == 0) {
				while (aVal < 101 && a[aVal - 1] == 0) {
					aVal++;
				}
				aCount = a[aVal - 1];
			}
			if (bCount == 0) {
				while (bVal > 0 && b[bVal - 1] == 0) {
					bVal--;
				}
				bCount = b[bVal - 1];
			}
			if (aVal > 100 || bVal < 1)
				break;


			sum = aVal + bVal;
			if (sum > max)
				max = sum;

			if (aCount > bCount) {
				aCount -= bCount;
				bCount = 0;
				bVal--;
			}
			else if (bCount > aCount) {
				bCount -= aCount;
				aCount = 0;
				aVal++;
			}
			else {
				aVal++;
				bVal--;
				aCount = 0;
				bCount = 0;
			}


		}

		std::cout << max << '\n';
	}
	std::cout << std::flush;
}
