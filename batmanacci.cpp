#include <bits/stdc++.h>

using namespace std;
int64_t fib[100001];
char findChar(int n, int64_t k){
    if(n == 0)
        return 'N';
    if(n == 1)
        return 'A';

    int64_t len = fib[n-2];
    if(k <= len)
        return findChar(n - 2, k);
    return findChar(n - 1, k - len);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    int64_t k;

    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < 100001; i++){
        fib[i] = fib[i-2] + fib[i-1];
        if(fib[i] < fib[i-1])
            fib[i] = INT64_MAX;
    }
    cin >> n >> k;

    cout << findChar(n - 1, k) << endl;

    return 0;
}