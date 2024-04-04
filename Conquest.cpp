#include <iostream>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nodes;
vector<int64_t> army;
vector<bool> visited;
priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> edges;

int main() {
	int n, m, x, y;
	int64_t size, a;
	pair<int64_t, int> e;
	cin >> n;

	nodes.assign(n, {});
	army.assign(n, 0);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--; y--;
		nodes[x].push_back(y);
		nodes[y].push_back(x);
	}

	for (int i = 0; i < n; i++) 
		cin >> army[i];
	
	edges = {};
	visited.assign(n, false);
	visited[0] = true;
	size = army[0];

	for (int i : nodes[0])
		edges.emplace(army[i], i);

	while (!edges.empty()) {
		e = edges.top();
		a = e.first;
		x = e.second;
		edges.pop();

		if (visited[x]) continue;
		if (size <= a) continue;
		visited[x] = true;
		//cout << size << " + " << a << " = " << size + a << endl;

		for (int i : nodes[x])
			edges.emplace(army[i], i);
		size += a;
	}

	cout << size << endl;


	return 0;
}