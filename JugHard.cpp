#include <numeric>
#include <iostream>

using namespace std;

int main() {
	int t, a, b, d, g;

	cin >> t;
	while (t--) {
		cin >> a >> b >> d;
		g = gcd(a, b);
		if (d % g != 0)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}