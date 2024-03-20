#include <iostream>

using namespace std;

uint64_t f(int d, int k) {
	double cur = 1;
	uint64_t a = 0;

	for (int i = 1; i <= k; i++) {
		cur = cur * (d - i + 1) / i;
		a += (uint64_t)cur;
	}
	return a;
}

int main() {
	uint64_t n;
	int t, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int i;
		for (i = 1; i <= 32; i++) {
			if (f(i, k) >= n) {
				cout << i << endl;
				break;
			}
		}
		if(i == 33)
			cout << "Impossible" << endl;
	}
}