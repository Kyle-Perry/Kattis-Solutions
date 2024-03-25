#include <vector>
#include <deque>
#include <iostream>
#include <utility>

using namespace std;
char b[1001][1001];
deque<pair<bool, pair<int, int>>> cur;
deque<pair<bool, pair<int, int>>> spread;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int cases, l, w, r, c, nr, nc, seconds;
    char t;
	bool isPerson, isSafe;
	pair<int, int> moves[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };


	cin >> cases;

	while (cases--) {
		cin >> w >> l;
		memset(b, '.', sizeof b);
		cur.clear(); spread.clear();
		seconds = 1;
		isSafe = false;

		for (r = 0; r < l; r++)
			for (c = 0; c < w; c++) {
				cin >> t;
				b[r][c] = t;
				if (t == '@')
					cur.push_back(make_pair(true, make_pair(r, c)));
				if (t == '*')
					cur.push_front(make_pair(false, make_pair(r, c)));
			}

		while (!cur.empty()) {

			while (!cur.empty()) {
				isPerson = cur.front().first;
				r = cur.front().second.first;
				c = cur.front().second.second;
				cur.pop_front();

				for (pair<int, int> m : moves) {
					nr = r + m.first;
					nc = c + m.second;

					if (nc >= 0 && nc < w && nr >= 0 && nr < l) {

						if (b[nr][nc] != '#' && b[nr][nc] != '*') {
							if (!(isPerson && b[nr][nc] == '@')) {

								//cout << "cur{" << r << ", " << c << "} = " << b[r][c] << "\tnext{" << nr << ", " << nc << "} = " << b[nr][nc] << endl;

								b[nr][nc] = b[r][c];
								if (isPerson) {
									spread.push_back(make_pair(isPerson, make_pair(nr, nc)));
								}
								else {
									spread.push_front(make_pair(isPerson, make_pair(nr, nc)));
								}
							}
						}
					}
					else
						if (isPerson) {
							isSafe = true;
							goto DONE_SIM;
						}

				}
			}
			seconds++;
			cur.insert(cur.end(), spread.begin(), spread.end());
			spread.assign({});
			//cout << cur.size() << " " << spread.size() << endl;
		}
		DONE_SIM:
			/*for (r = 0; r < l; r++) {
				for (c = 0; c < w; c++)
					cout << b[r][c];
				cout << endl;
			}*/

		
			if (isSafe)
				cout << seconds << endl;
			else
				cout << "IMPOSSIBLE" << endl;

		
	}
	return 0;
}