#include <vector>
#include <iostream>
#include <queue>
//#include <bits/stdc++.h>

using namespace std;

int64_t nodes[2500][2500];
bool visited[2500];
priority_queue<tuple<int64_t, int, int>, vector<tuple<int64_t, int, int>>, greater<tuple<int64_t, int, int>>> edges;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, y, taken;
    tuple<int64_t, int, int> e;
    int64_t a;
    cin >> n;

    edges = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nodes[i][j];
        }
    }
    visited[0] = true;
    for (int i = 1; i < n; i++)
        edges.emplace(nodes[0][i], 0, i);

    taken = 0;
    while (!edges.empty()) {
        e = edges.top();
        a = get<0>(e);
        x = get<1>(e);
        y = get<2>(e);
        edges.pop();

        if (visited[y]) continue;
        visited[y] = true;
        cout << x + 1 << ' ' << y + 1 << '\n';
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;
            edges.emplace(nodes[y][i], y, i);
        }
        ++taken;
        if (taken == n - 1) break;
    }

    return 0;
}