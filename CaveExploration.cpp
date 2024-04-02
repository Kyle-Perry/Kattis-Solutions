#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> graph;
vector<int> dfs_num, dfs_low, dfs_par;
vector<bool> bridge_ver, visited;
int dfsCounter, dfsRoot, rootChildren;

void findBridges(int u) {
	dfs_low[u] = dfs_num[u] = dfsCounter++;
	for (int a :graph[u]) {
		if (dfs_num[a] == -1) {
			dfs_par[a] = u;
			if (u == dfsRoot) ++rootChildren;

			findBridges(a);

			if (dfs_low[a] >= dfs_num[u])
				bridge_ver[u] = 1;
			if (dfs_low[a] > dfs_num[u])
				cout << "Edge (" << u << ", " << a << ") is a bridge\n";
			dfs_low[u] = min(dfs_low[u], dfs_low[a]);
		}
		else if (a != dfs_par[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[a]);
	}
}

int countJunctions(int u) {
	//cout << "Vertex " << u << endl;
	visited[u] = true;
	int i = 1;
	for (int a : graph[u])
	{
		if (!visited[a]) {
			if (!(dfs_low[a] > dfs_num[u])){
				//cout << "checking (" << u << " , " << a << ")" << endl;

				i += countJunctions(a);
			}
		}
			
	}
	return i;
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	graph.assign(n, {});
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs_num.assign(n, -1); dfs_low.assign(n, 0);
	dfs_par.assign(n, -1); bridge_ver.assign(n, false);
	dfsCounter = 0;
	for (int x = 0; x < n; ++x)
		if (dfs_num[x] == -1) {
			dfsRoot = x; rootChildren = 0;
			findBridges(x);
			bridge_ver[dfsRoot] = (rootChildren > 1);

			visited.assign(n, false);
			cout << countJunctions(0) << endl;
		}


	return 0;
}