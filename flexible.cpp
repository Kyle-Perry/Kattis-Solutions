#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 101;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<int> sizes;
    vi walls(101);
    int w, p, l, t;
    cin >> w >> p;
    walls.push_back(0);
    for(int i = 0; i < p; i++){
        cin >> l;
        walls.push_back(l);
    }
    walls.push_back(w);
    
    for(int i = 0; i < walls.size() - 1; i++){
        for(int x = i +1; x < walls.size(); x++){
            t = walls[x] - walls[i];
            if(t != 0 && sizes.find(t) == sizes.end())
                sizes.insert(t);
        }
    }

    for(auto it = sizes.begin(); it != sizes.end(); ++it){
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}