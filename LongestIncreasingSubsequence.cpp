#include <vector>
#include <iostream>
using namespace std;

vector<long int> p;
void printSeq(int lis_end) {
	if (lis_end == -1)
		return;
	else
		printSeq(p[lis_end]);
		cout << lis_end << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases, n, x, k, lis_end;
	vector<int64_t> l, li, arr;
	
	while(cin >> n){
		k = 0;
		lis_end = 0;
		
		l.resize(n, 0);
		li.resize(n, 0);
		arr = {};
		p.assign(n, -1);
		for (int i = 0; i < n; ++i)  {
			cin >> x;
			arr.push_back(x);
		}
		for (int i = 0; i < n; ++i) {
			int pos = lower_bound(l.begin(), l.begin() + k, arr[i]) - l.begin();
			l[pos] = arr[i];
			li[pos] = i;
			p[i] = pos ? li[pos - 1] : -1;
			if (pos == k) {
				k = pos + 1;
				lis_end = i;
			}
		}

		cout << k << endl;
		printSeq(lis_end);
		cout << endl;

	}

}