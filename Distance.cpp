//#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    uint64_t x, y, xs = 0, ys = 0, xr = 0, yr = 0;
    vector<uint64_t> xcoords, ycoords;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        xcoords.push_back(x);
        ycoords.push_back(y);
    }
    sort(xcoords.begin(), xcoords.end());
    sort(ycoords.begin(), ycoords.end());

    for (int i = 0; i < n; i++) {
        xr += i * xcoords[i] - xs;
        xs += xcoords[i];
        yr += i * ycoords[i] - ys;
        ys += ycoords[i];
    }
    cout << xr + yr << endl;
    return 0;
}