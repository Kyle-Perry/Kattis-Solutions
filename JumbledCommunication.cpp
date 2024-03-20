#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int n;
	uint16_t b, cur, x;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b;
		for (x = 0; x < 256; x++) {
			cur = x ^ (x << 1);

			cur &= 0b11111111;
			if (cur == b) {
				break;
			}
		}
		cout << x << ' ';
	}

	return 0;

}