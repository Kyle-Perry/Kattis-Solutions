//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define LSOne(S) ((S) & -(S))                    // the key operation

typedef long long ll;                            // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {                              // index 0 is not used
private:
    vll ft;                                        // internal FT is an array
public:
    FenwickTree(int m) { ft.assign(m + 1, 0); }      // create an empty FT

    void build(const vll& f) {
        int m = (int)f.size() - 1;                     // note f[0] is always 0
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i) {               // O(m)
            ft[i] += f[i];                             // add this value
            if (i + LSOne(i) <= m)                       // i has parent
                ft[i + LSOne(i)] += ft[i];                 // add to that parent
        }
    }

    FenwickTree(const vll& f) { build(f); }        // create FT based on f

    FenwickTree(int m, const vi& s) {              // create FT based on s
        vll f(m + 1, 0);
        for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
            ++f[s[i]];                                 // in O(n)
        build(f);                                    // in O(m)
    }

    ll rsq(int j) {                                // returns RSQ(1, j)
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, ll v) {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    int select(ll k) {                             // O(log m)
        int p = 1;
        while (p * 2 < (int)ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

int main() {
    int n, q, k, p, l, r, t, x;
    string types = "";
    char c;
    cin >> n >> q;

    uint64_t v[6], vn, total;
    vector<FenwickTree> gems;
    for (int i = 0; i < 6; i++) {
        gems.push_back(FenwickTree(n));
        cin >> vn;
        v[i] = vn;
    }
    cin.ignore(1);
    for (int i = 0; i < n; i++) {
        cin >> c;
        types.push_back(c);
        t = c - '1';
        gems[t].update(i + 1, 1);
    }
    cin.ignore(1);
    for (int i = 0; i < q; i++) {
        cin >> t;
        switch (t) {
        case 1:
            cin >> k >> p;
            x = types[k - 1] - '1';
            gems[x].update(k, -1);
            gems[p - 1].update(k, 1);
            types[k - 1] = '0' + p;
            break;
        case 2:
            cin >> p >> vn;
            v[p - 1] = vn;
            break;
        case 3:
            cin >> l >> r;
            total = 0;
            for (int i = 0; i < 6; i++) {
                vn = gems[i].rsq(l, r) * v[i];
                total += vn;
            }
            cout << total << endl;
            break;
        }
    }

	return 0;
}