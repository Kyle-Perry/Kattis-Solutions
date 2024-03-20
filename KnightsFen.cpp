#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int cases, curMoves, x, y, i;
	char c;
	queue<vector<vector<char>>> boards;
	map <vector<vector<char>>, int> moves;

	cin >> cases;
	vector<vector<char>> cur, next, final = {
		{'1','1','1','1','1'},
		{'0','1','1','1','1'},
		{'0','0',' ','1','1'},
		{'0','0','0','0','1'},
		{'0','0','0','0','0'}};

	vector<vector<char>> initial = final;

	boards.push(final);
	moves[final] = 0;

	while (!boards.empty()) {
		cur = boards.front();
		boards.pop();

		curMoves = moves[cur];
		if (curMoves == 10)
			break;

		i = 0;
		while (cur[(i%5)][(i/5)] != ' ')
			i++;

		x = i % 5;
		y = i / 5;
		next = cur;
		if (x + 2 < 5 && y + 1 < 5) {
			swap(next[x][y], next[x + 2][y + 1]);
			if (moves.count(next) == 0) {
				moves[next] = curMoves + 1;
				boards.push(next);
			}
			next = cur;
		}
		if (x + 2 < 5 && y + -1 >= 0) {
			swap(next[x][y], next[x + 2][y + -1]);
			if (moves.count(next) == 0) {
				moves[next] = curMoves + 1;
				boards.push(next);
			}
			next = cur;
		}
		if (x + -2 >= 0 && y + 1 < 5) {
			swap(next[x][y], next[x + -2][y + 1]);
			if (moves.count(next) == 0) {
				moves[next] = curMoves + 1;
				boards.push(next);
			}
			next = cur;
		}
		if (x + -2 >= 0 && y + -1 >= 0) {
			swap(next[x][y], next[x + -2][y + -1]);
			if (moves.count(next) == 0) {
				moves[next] = curMoves + 1;
				boards.push(next);
			}
			next = cur;
		}
		if (x + 1 < 5 && y + 2 < 5) {
			swap(next[x][y], next[x + 1][y + 2]);
			if (moves.count(next) == 0) {
				moves[next] = curMoves + 1;
				boards.push(next);
			}
			next = cur;
		}
		if (x + 1 < 5 && y + -2 >= 0) {
			swap(next[x][y], next[x + 1][y + -2]);
			if (moves.count(next) == 0) {
				moves[next] = curMoves + 1;
				boards.push(next);
			}
			next = cur;
		}
		if (x + -1 >= 0 && y + 2 < 5) {
			swap(next[x][y], next[x + -1][y + 2]);
			if (moves.count(next) == 0) {
				moves[next] = curMoves + 1;
				boards.push(next);
			}
			next = cur;
		}
		if (x + -1 >= 0 && y + -2 >= 0) {
			swap(next[x][y], next[x + -1][y + -2]);
			if (moves.count(next) == 0) {
				moves[next] = curMoves + 1;
				boards.push(next);
			}
			next = cur;
		}
	}
	
	for (i = 0; i < cases; i++) {
		for (int n = 0; n < 5; n++) {
			cin.ignore();
			for (int m = 0; m < 5; m++) {
				c = cin.get();
				initial[n][m] = c;
			}
		}

		if (moves.count(initial) == 0)
			cout << "Unsolvable in less than 11 move(s)." << endl;
		else
			cout << "Solvable in " << moves[initial] << " move(s)." << endl;

	}


	return 0;
}