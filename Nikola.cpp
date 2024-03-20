#include <queue>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

typedef pair<int64_t, pair<int64_t, int64_t>> state;

int main() {
	int n;
	int64_t pos, last_jump, back, forward;
	cin >> n;
	vector<int64_t> fees(n);

	for (int i = 0; i < n; i++) {
		cin >> fees[i];
	}

	vector<vector<int64_t>> costs(n, vector<int64_t>(n, -1));
	priority_queue <state, vector<state>, greater<state>> states;

	states.push({0, {1,1}});
	costs[1][1] = fees[1];

	while (!states.empty()) {
		pos = states.top().second.first;
		last_jump = states.top().second.second;
		states.pop();

		if (pos == n - 1) {
			cout << costs[pos][last_jump] << endl;
			return 0;
		}
		back = pos - last_jump;
		forward = pos + last_jump + 1;
		if (back >= 0) {
			if (costs[back][last_jump] == -1) {
				costs[back][last_jump] = costs[pos][last_jump] + fees[back];
				states.push({ costs[back][last_jump], {back, last_jump} });
			}
		}
		if (forward < n) {
			if (costs[forward][last_jump + 1] == -1) {
				costs[forward][last_jump + 1] = costs[pos][last_jump] + fees[forward];
				states.push({ costs[forward][last_jump + 1], {forward, last_jump + 1} });
			}
		}
		
	}
}