#include <string>
#include <iostream>
#include <numeric>
using namespace std;

int64_t getVal(string s, int base) {
	int64_t r = 0;

	for (char c : s) {
		r *= base;
		if (c >= 'A' && c <= 'F')
			r += c - 'A' + 10;
		else
			r += c - '0';
	}
	return r;
}

bool isPrime(int64_t n) {
	if (n <= 1)
		return false;

	for (size_t i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;

	return true;
}

bool isBase(string s, string base) {
	for (char c : s) {
		if (base.find(c) == string::npos)
			return false;
	}
	return true;
}

int main() {
	int64_t g, t;
	int num, den;
	string input;

	cin >> t;

	while (t--) {
		num = 0;
		den = 0;
		cin >> input;

		if (isBase(input, "01")) {
			den++;
			if (isPrime(getVal(input, 2)))
				num++;
		}
		if (isBase(input, "01234567")) {
			den++;
			if (isPrime(getVal(input, 8)))
				num++;
		}
		if (isBase(input, "0123456789")) {
			den++;
			if (isPrime(getVal(input, 10)))
				num++;
		}
		if (isBase(input, "0123456789ABCDEF")) {
			den++;
			if (isPrime(getVal(input, 16)))
				num++;
		}

		g = gcd(num, den);
		cout << num / g << '/' << den / g << endl;

	}
}