#include <deque>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int lake[1001][1001], dist[1001][1001];
pair<int, int> moves[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int l, w, qs, rs, cs, rd, cd, r, c, nr, nc, nd;
	bool cmp;
	string row;
	deque<pair<int, int>> cur;

	cin >> l >> w;

	for (int y = 0; y < l; y++) {
		cin >> row;
		for (int x = 0; x < w; x++) {
			lake[y][x] = row[x] - '0';
		}
	}
	
	cin >> qs;
	for (int q = 0; q < qs; q++) {
		cin >> rs >> cs >> rd >> cd;
		rs--;
		cs--;
		rd--;
		cd--;

		cur.clear();
		memset(dist, -1, sizeof(dist));
		dist[rs][cs] = 0;
		cur.push_back(make_pair(rs, cs));

		while (!cur.empty()) {
			r = cur.front().first;
			c = cur.front().second;
			cur.pop_front();

			if (r == rd && c == cd)
				break;

			for (int i = 0; i < 8; i++) {
				nr = r + moves[i].first;
				nc = c + moves[i].second;
				
				if (nc >= 0 && nc < w && nr >= 0 && nr < l) {
					nd = dist[nr][nc];
					cmp = i == lake[r][c];
					if (nd == -1) {
						dist[nr][nc] = dist[r][c] + (!cmp);
						if (cmp)
							cur.push_front(make_pair(nr, nc));
						else
							cur.push_back(make_pair(nr, nc));
					}
					else if (nd > dist[r][c] + !cmp) {
						dist[nr][nc] = dist[r][c] + (!cmp);
						if (cmp)
							cur.push_front(make_pair(nr, nc));
						else
							cur.push_back(make_pair(nr, nc));
					}
				}
			}

		}


		cout << dist[rd][cd] << endl;
	}


	return 0;
}