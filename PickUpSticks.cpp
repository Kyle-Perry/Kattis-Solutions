#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;


int main() {
	int n, m, a, b, x;
	cin >> n >> m;
	adj.resize(n, {});
	vector<int> inD(n, 0), sol;
	priority_queue<int> cur;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		inD[b - 1]++;
	}

	for (int i = 0; i < n; i++) {
		if (inD[i] == 0)
			cur.push(i);
	}

	while (!cur.empty()) {
		x = cur.top();
		cur.pop();
		sol.push_back(x);
		for (int i : adj[x]) {
			inD[i]--;
			if (inD[i] == 0)
				cur.push(i);
		}
	}

	if (sol.size() != n) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	for (int i : sol)
		cout << i + 1 << endl;

	return 0;
}