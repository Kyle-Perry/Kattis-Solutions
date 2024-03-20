#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>> adj;

void DFS(int start) {
	if (start >= adj.size())
		return;
	
	stack<int> next = {};
	vector<bool> visited(adj.size());
	int cur;

	next.push(start);
	visited[start] = true;
	while (!next.empty()) {
		cur = next.top();
		next.pop();
		cout << cur << " ";
		for (auto it = adj[cur].rbegin(); it != adj[cur].rend(); ++it) {
			if (!visited[*it]) {
				visited[*it] = true;
				next.push(*it);
			}
		}

	}
	cout << endl;
}

void BFS(int start) {
	queue<int> next = {};
	vector<bool> visited(adj.size());
	int cur;

	next.push(start);
	visited[start] = true;
	while (!next.empty()) {
		cur = next.front();
		next.pop();
		cout << cur << " ";
		for (int i : adj[cur]) {
			if (!visited[i]) {
				visited[i] = true;
				next.push(i);
			}
		}

	}
	cout << endl;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, x; 
	cin >> n;

	adj.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			adj[i].push_back(x);
		}
	}
	
	BFS(1);
	DFS(0);

	for (int j = 0; j < n; j++) {
		cout << j << " = { ";
		for (int i : adj[j])
			cout << i << " ";
		cout << "}" << endl;

	}
	return 0;
}