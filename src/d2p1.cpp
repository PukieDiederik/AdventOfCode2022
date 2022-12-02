#include <iostream>
#include <string>

// Returns 0 if loss, 1 if draw, 2 if win
int winRound(char a, char b)
{
	if (a - 'A' == b - 'X')
		return 1;
	else if ((a == 'A'  && b == 'Y') || (a == 'B'  && b == 'Z') || (a == 'C'  && b == 'X'))
		return (2);
	return (0);
}

int main()
{
	int total_score = 0;
	std::string s;
	while (std::getline(std::cin, s))
		total_score += s[2] - 'X' + 1 + (winRound(s[0], s[2]) * 3);
	std::cout << "total: " << total_score << std::endl;
}