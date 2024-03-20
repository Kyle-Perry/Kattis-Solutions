#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> syllables;
int memo[101][8];

int countSyl(size_t pos, string target, int noSyls) {
	if (pos == target.size()) {
		if (noSyls == 0) {
			return 0;
		}
		else
			return INT_MIN;
	}
	if (pos > target.size())
		return INT_MIN;
	if (noSyls == 0)
		return INT_MIN;
	if (target[pos] == ' ')
		return countSyl(pos + 1, target, noSyls);

	if (memo[pos][noSyls] != -1)
		return memo[pos][noSyls];

	int counted = INT_MIN;
	for (string syl : syllables) {
		if (target.find(syl, pos) == pos) {
			counted = max(counted, 1 + countSyl(pos + syl.size(), target, noSyls - 1));
		}
	}

	memo[pos][noSyls] = counted;
	return counted;
}

int main() {
	int n;
	string l1, l2, l3, syl;
	cin >> n;
	cin.ignore(1);
	for (int i = 0; i < n; i++) {
		getline(cin, syl);
		syllables.push_back(syl);
	}

	memset(memo, -1, sizeof memo);
	getline(cin, l1);
	if (countSyl(0, l1, 5) != 5) {
		cout << "come back next year" << endl;
		return 0;
	}

	memset(memo, -1, sizeof memo);
	getline(cin, l2);
	if (countSyl(0, l2, 7) != 7) {
		cout << "come back next year" << endl;
		return 0;
	}
	memset(memo, -1, sizeof memo);
	getline(cin, l3);
	if (countSyl(0, l3, 5) != 5) {
		cout << "come back next year" << endl;
		return 0;
	}

	cout << "haiku" << endl;
	return 0;
}