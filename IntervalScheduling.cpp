#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue <pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> t = {};

	int n, s, f, l = 0, c = 0;
	cin >> n;

	while (n--) {
		cin >> s >> f;
		t.push(make_pair(f, s));
	}

	while (!t.empty()) {
		if (c <= t.top().second) {
			l++;
			c = t.top().first;
		}
		
		t.pop();
	}
	cout << l << endl;
 }