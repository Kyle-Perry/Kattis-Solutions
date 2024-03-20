#include <iostream>

int main()
{
	int time;
	char problem;
	std::string result;
	int penalties[26] = { 0 };
	int score = 0;
	int solved = 0;

	while (true) {
		std::cin >> time;
		if (time == -1)
			break;
			
		std::cin >> problem >> result;

		if (result == "right")
		{
			solved++;
			score += (time + penalties[problem - 'A']);
		}
		else
		{
			penalties[problem - 'A'] += 20;
		}

	}
	
	std::cout << solved << ' ' << score << std::endl;

	return 0;
}