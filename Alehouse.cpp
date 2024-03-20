#include <set>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	priority_queue<pair<int64_t, bool>> events = {};

	int32_t n, x, y;
	int64_t a, b, k; 

	cin >> n >> k;

	for (int i = 0; i < n; i++) {

		cin >> a >> b;
		a -= k;
		events.push(make_pair(a, false));
		events.push(make_pair(b, true));
	}
	x = 0;
	y = 0;
	while (!events.empty()) {
		if (events.top().second) {
			y++;
		}
		else {
			y--;
		}
		cout << "<" << events.top().first << ", " << events.top().second << "> " << y << endl;
		events.pop();
		x = (y > x) ? y : x;
	}
	cout << x << endl;

	return 0;
}