//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;
const long double PI = 3.1415926535897932384626433832795;
vector<long double> pies;

bool can(int f, long double v) {
    int count = 0;

    for (long double pie : pies) {
        count += pie / v;
    }
    return count >= f;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int c, f, n, r;
    long double a, largest = 0;
    cin >> c;
    while (c--) {
        cin >> n >> f;
        f++;
        for (int i = 0; i < n; i++) {
            cin >> r;
            a = r * r * PI;
            if (a > largest)
                largest = a;
            pies.push_back(a);
        }

        long double high = largest, low = 0.0;
        while(fabs(high - low) > 1.0e-9) {
            long double mid = (low + high) / 2.0;
            if (can(f, mid))
                low = mid;
            else
                high = mid;
        }
        cout << fixed << setprecision(9) << low << endl;
        pies = {};
    }
    return 0;
}