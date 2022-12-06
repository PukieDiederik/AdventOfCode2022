#include <iostream>

bool isUnique(std::string s, int i)
{
	int j = 0;
	std::string tmp = s.substr(i, 14);
	while (j < 14)
	{
		if (tmp.find(tmp[j], j + 1) != std::string::npos)
			return false;
		++j;
	}
	return true;
}

int main()
{
	std::string s;
	std::cin >> s;
	int i = 0;
	while (!isUnique(s, i))
		++i;
	std::cout << i + 14 << std::endl;
}