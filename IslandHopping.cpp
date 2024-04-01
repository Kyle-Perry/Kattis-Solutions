#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <iostream>

using namespace std;

double dist(pair <double, double> n1, pair <double, double> n2) {
	double dx = n1.first - n2.first;
	dx *= dx;
	double dy = n1.second - n2.second;
	dy *= dy;
	return sqrt(dx + dy);
}


vector<pair<double, double>> nodes;
vector<vector<pair<double, int>>> neighbours;
vector<bool> visited;
priority_queue<pair<double, int>> edges;

void process(int u) {
	visited[u] = true;
	for (auto a : neighbours[u])
		if (!visited[a.second])
			edges.push(make_pair(-a.first, -a.second));
}

int main() {
	int n, m, n1, taken;
	double x, y, total, d;
	pair<double, int> e;
	cin >> n;

	while (n--) {
		cin >> m;

		nodes.assign(m, { 0.0, 0.0 });
		neighbours.assign(m, {});
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			nodes[i].first = x;
			nodes[i].second = y;
		}

		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				d = dist(nodes[i], nodes[j]);
				//cout << "(" << i << ", " << j << " ) = " << d << endl;
				neighbours[i].emplace_back(d, j);
				neighbours[j].emplace_back(d, i);
			}
		}

		edges = {};
		visited.assign(m, false);
		total = 0.0;
		taken = 0;
		process(0);
		while (!edges.empty()) {
			e = edges.top();
			d = -get<0>(e);
			n1 = -get<1>(e);
			edges.pop();

			if (visited[n1]) continue;
			process(n1);
			//cout << total << " + " << d << " = " << total + d << endl;
			total += d;
			++taken;
			if (taken == m - 1) break;
		}

		cout.precision(3);
		cout << fixed << total << endl;
	}
	
	return 0;
}