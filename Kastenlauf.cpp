#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int main() {
	int32_t t, n, x, y, d;
	vector<pair<int, int>> graph;
	vector<vector<int>> distances;
	cin >> t;

	while (t--) {
		cin >> n;
		n += 2;
		graph.assign(n, { 0, 0 });
		distances.assign(n, {});

		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			graph[i] = make_pair(x, y);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d = abs(graph[i].first - graph[j].first) + abs(graph[i].second - graph[j].second);
				if (d <= 1000)
					distances[i].push_back(1);
				else
					distances[i].push_back(0);
				
			}
		}

		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					distances[i][j] |= (distances[i][k] & distances[k][j]);
				}

		if (distances[0][n - 1])
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}

	return 0;
}