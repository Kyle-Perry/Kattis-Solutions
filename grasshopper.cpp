#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef int64_t li;
typedef uint64_t ul;

int grid[101][101];

int main(){
    queue<pair<int, int>> next;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int r, c, gr, gc, lr, lc, curR, curC;

    while(cin >> r >> c >> gr >> gc >> lr >> lc){
        memset(grid, -1, sizeof grid);
        grid[gr][gc] = 0;
        next.push(make_pair(gr, gc));
        while(!next.empty()){
            curR = next.front().first;
            curC = next.front().second;
            next.pop();
            if(curR + 2 <= r){
                if(curC + 1 <= c){
                    if(grid[curR +2][curC + 1] == -1){
                        next.push(make_pair(curR +2, curC +1));
                        grid[curR+2][curC+1] = grid[curR][curC] + 1;
                    }
                }
                if(curC - 1 >= 1){
                    if(grid[curR +2][curC - 1] == -1){
                        next.push(make_pair(curR +2, curC -1));
                        grid[curR+2][curC-1] = grid[curR][curC] + 1;
                    }
                }
            }
            if(curR + 1 <= r){
                if(curC + 2 <= c){
                    if(grid[curR + 1][curC + 2] == -1){
                        next.push(make_pair(curR + 1, curC +2));
                        grid[curR + 1][curC+ 2] = grid[curR][curC] + 1;
                    }
                }
                if(curC - 2 >= 1){
                    if(grid[curR + 1][curC - 2] == -1){
                        next.push(make_pair(curR + 1, curC - 2));
                        grid[curR + 1][curC -2 ] = grid[curR][curC] + 1;
                    }
                }
            }
            if(curR - 2 >= 1){
                if(curC + 1 <= c){
                    if(grid[curR -2][curC + 1] == -1){
                        next.push(make_pair(curR -2, curC +1));
                        grid[curR-2][curC+1] = grid[curR][curC] + 1;
                    }
                }
                if(curC - 1 >= 1){
                    if(grid[curR -2][curC - 1] == -1){
                        next.push(make_pair(curR -2, curC -1));
                        grid[curR-2][curC-1] = grid[curR][curC] + 1;
                    }
                }
            }
            if(curR - 1 >= 1){
                if(curC + 2 <= c){
                    if(grid[curR - 1][curC + 2] == -1){
                        next.push(make_pair(curR - 1, curC +2));
                        grid[curR - 1][curC+2] = grid[curR][curC] + 1;
                    }
                }
                if(curC - 2 >= 1){
                    if(grid[curR - 1][curC - 2] == -1){
                        next.push(make_pair(curR - 1, curC - 2));
                        grid[curR - 1][curC -2 ] = grid[curR][curC] + 1;
                    }
                }
            }
            
        }
        if(grid[lr][lc] == -1)
            cout << "impossible" << endl;
        else
            cout << grid[lr][lc] << endl;
    }

    return 0;
}