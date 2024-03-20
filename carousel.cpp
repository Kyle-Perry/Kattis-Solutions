#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    priority_queue<pair<double, pair<int, int>>> deals;
    int n, m, a, b;
    double v;

    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            if(a <= m){
                v = (double)a/ (double)b;
                deals.push(make_pair(v, make_pair(a,b)));
            }
        }
        if(!deals.empty())
            cout << "Buy " << deals.top().second.first << " tickets for $" << deals.top().second.second << endl;
        else
            cout << "No suitable tickets offered" << endl;
        deals = {};
    }


    return 0;
}