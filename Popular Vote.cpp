#include <iostream>

int main() {
	int testcases = 0;
	int candidates = 0;
	int total_votes = 0;
	int winner = 0; 
	int winner_votes = 0;
	int candidate_votes = 0;

	std::cin >> testcases;

	for (int i = 0; i < testcases; i++) {
		std::cin >> candidates;
		total_votes = 0;
		winner_votes = 0;
		winner = 0;
		for (int n = 0; n < candidates; n++) {
			std::cin >> candidate_votes;
			if (candidate_votes > winner_votes) {
				winner = n + 1;
				winner_votes = candidate_votes;
			}
			else if (candidate_votes == winner_votes) {
				winner = -1;
			}
			total_votes += candidate_votes;
		}
		if (winner == -1)
			std::cout << "no winner" << std::endl;
		else if (winner_votes > total_votes / 2)
			std::cout << "majority winner " << winner << std::endl;
		else
			std::cout << "minority winner " << winner << std::endl;
	}
}