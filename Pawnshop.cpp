#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int add_count(map<int, int>& count, int val, int adjust) {
	int mismatch = 0;

	if (count[val] == 0)
		mismatch++;
	count[val] += adjust;
	if (count[val] == 0)
		mismatch--;

	return mismatch;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int length = 0, ovalue, mvalue;

	stringstream original;
	stringstream moved;
	string o, m, to, tm;
	map<int, int> count;
	int mismatch = 0;

	cin >> length;
	cin.ignore(1);
	getline(cin, o);
	getline(cin, m);
	original << o;
	moved << m;

	for (int i = 0; i < length; i++) {
		original >> ovalue;
		moved >> mvalue;

		mismatch += add_count(count, ovalue, 1);
		mismatch += add_count(count, mvalue, -1);

		cout << mvalue;
		if (i + 1 != length) {
			cout << " ";
			if (mismatch == 0)
				cout << "# ";
		}
	}

}


