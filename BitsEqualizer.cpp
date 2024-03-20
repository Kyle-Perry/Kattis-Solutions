#include <iostream>

int main() {
	std::string s, t = "";
	int cases = 0;
	std::cin >> cases;

	int pair01, pair10, s1, sQ, t1, moves;

	for (int i = 0; i < cases; i++) {
		std::cin >> s >> t;

		pair01 = 0;
		pair10 = 0;
		s1 = 0;
		sQ = 0;
		t1 = 0;
		moves = 0;

		for (int x = 0; x < s.length(); x++)
		{
			if (s[x] == '1')
				s1++;
			if (s[x] == '?')
				sQ++;
			if (t[x] == '1')
				t1++;
			if (s[x] == '1' && t[x] == '0')
				pair10++;
			if (s[x] == '0' && t[x] == '1')
				pair01++;
		}

		if (s1 > t1)
			moves = -1;
		else
		{
			moves = pair10 + sQ;
			if (pair01 - pair10 > 0)
				moves += pair01 - pair10;	
		}
			 
		std::cout << "Case " << i + 1 << ": " << moves << std::endl;

	}

	return 0;
}