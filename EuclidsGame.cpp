#include <iostream>

using namespace std;

int play(int64_t n, int64_t m) {	
	if (n % m == 0 || n > 2 * m)
		return 0;
	return 1 - play(m, n - m);
}

int main() {
	int64_t n, m;
	cin >> n >> m;

	while (n || m)
	{
		if (m > n) 
			swap(n, m);
		
		if (play(n, m) == 0)
			cout << "Stan wins" << endl;
		else
			cout << "Ollie wins" << endl;
		cin >> n >> m;

	}

	return 0;
}