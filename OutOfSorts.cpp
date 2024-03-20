#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<uint64_t> arr;

bool search(int first, int last, int target){
	int mid;
	if (first > last)
		return false;
	mid = (first + last) / 2;
	if (arr[mid] == target)
		return true;
	if (arr[mid] > target)
		return search(first, mid - 1, target);
	else
		return search(mid + 1, last, target);
}

int main() {
	uint64_t n, m, a, c, x;

	cin >> n >> m >> a >> c >> x;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			arr.push_back(((a * x) + c) % m);
		else
			arr.push_back(((a * arr[i - 1]) + c) % m);
	}

	int found = 0;
	for (int i : arr) {
		if (search(0, arr.size()-1, i))
			found++;
	}
	cout << found << endl;
	return 0;
}