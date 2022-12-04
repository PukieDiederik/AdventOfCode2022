#include <iostream>

bool getInput(int &a1, int &a2, int &b1, int &b2)
{
	std::cin >> a1;
	std::cin.ignore(1, '-');
	std::cin >> a2;
	std::cin.ignore(1, ',');
	std::cin >> b1;
	std::cin.ignore(1, '-');
	std::cin >> b2;
	return !(std::cin.fail() || std::cin.eof());
}

int main()
{
	int a1, a2, b1, b2;
	int score = 0;

	while (getInput(a1, a2, b1, b2))
	{
		if ((a1 <= b1 && a2 >= b2) || (b1 <= a1 && b2 >= a2))
			score++;
	}
	if ((a1 <= b1 && a2 >= b2) || (b1 <= a1 && b2 >= a2))
		score++;
	std::cout << "score: " << score << std::endl;
}