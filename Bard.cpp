#include <vector>
#include <iostream>
#include <unordered_set>
//#include <bits/stdc++.h>

using namespace std;
vector<unordered_set<int>> villagers;
vector<int> attending;

int main() {
	int n, e, a, p;
	bool bPresent;
	cin >> n >> e;

	villagers.assign(n, {});
	for (int i = 0; i < e; i++) {
		cin >> a;
		bPresent = false;
		attending = {};

		while (a--) {
			cin >> p;
			p--;
			attending.push_back(p);
			if (p == 0)
				bPresent = true;
		}

		if (bPresent) {
			for (int j : attending) {
				villagers[j].insert(i);
			}
		}
		else {
			for (int j = 0; j < attending.size(); j++) {
				villagers[attending[0]].merge(villagers[attending[j]]);
			}
			for (int j = 0; j < attending.size(); j++) {
				villagers[attending[j]] = villagers[attending[0]];
			}
		}

	}


	/*for (unordered_set<int> v : villagers) {
		for (int i : v)
			cout << i << " ";
		cout << "\n";
	}*/

	for (int i = 0; i < n; i++) {
		if (villagers[i] == villagers[0])
			cout << i+1 << "\n";
	}


	return 0;
}