#include <vector>
#include <iostream>

using namespace std;

vector<int64_t> profits, costs;

int64_t profit(int day) {
    int64_t profit = 0;
    int64_t cur = 0;

    for (int i = 0; i < profits.size(); i++) {
        cur = (profits[i] * day);
        if (cur > costs[i])
        {
            profit += cur - costs[i];
        }
    }
    return profit;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    uint64_t d, m, t, p, c, low = 0, high = UINT64_MAX;
    cin >> n >> m;

    for (int x = 0; x < n; x++)
    {
        cin >> p >> c;
        profits.push_back(p);
        costs.push_back(c);
        d = c + m;
        t = d / p;
        if (d % p != 0)
            t++;
        d = t;
        if (d < high)
            high = d;
    }

    for(int x =0; x < 1000; x++) {
        d = (low + high) >> 1;
        (profit(d) >= m) ? high = d : low = d;
    }

    if (profit(low) >= m)
        high = low;
    cout << high << endl;

    return 0;
}