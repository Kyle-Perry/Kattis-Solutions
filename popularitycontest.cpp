#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1000;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, p, a, b;
    int f[MAX_N] = {0};

    cin >> n >> m;
    for(int x = 0; x < m; x++){
        cin >> a >> b;
        f[a - 1]++;
        f[b - 1]++;
    }
    for(int x = 0; x < n; x++){
        f[x] -= (x+1);
        cout << f[x] << ' ';
    }
    cout << endl;

    return 0;
}