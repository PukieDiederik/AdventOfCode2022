#include <iostream>
#include <string>

int whatPick(char a, char b)
{
	switch (b) {
		case 'X':
			return (((a - 'A' + 2) % 3) + 1);
		case 'Y':
			return (a - 'A' + 1);
		case 'Z':
			return (((a - 'A' + 1) % 3) + 1);
	}
	return (0);
}

int main()
{
	int total_score = 0;
	std::string s;
	while (std::getline(std::cin, s))
		total_score += ((s[2] - 'X') * 3) + whatPick(s[0], s[2]);
	std::cout << "total: " << total_score << std::endl;
}