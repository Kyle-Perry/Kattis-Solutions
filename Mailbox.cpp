//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int memo[11][101][101];

int findMin(int lo, int hi, int remain) {
    if (remain == 1)
        return (hi * (hi + 1)) / 2 - (lo * (lo + 1)) / 2;
    if (lo == hi)
        return 0;

    if (memo[remain][lo][hi] != -1)
        return memo[remain][lo][hi];

    int minCrackers = INT_MAX;
    for (int i = lo + 1; i <= hi; i++) {
        minCrackers = min(minCrackers, i + max(findMin(lo, i - 1, remain - 1), findMin(i, hi, remain)));
    }
    memo[remain][lo][hi] = minCrackers;

    return minCrackers;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> m;
        memset(memo, -1, sizeof(memo));
        cout << findMin(0, m, k) << endl;
    }

    return 0;
}