#include <iostream>
#include <string>

int main()
{
	int total_score = 0;
	std::string e1;
	std::string e2;
	std::string e3;

	while (std::getline(std::cin, e1) && std::getline(std::cin, e2) && std::getline(std::cin, e3))
	{
		for(std::string::size_type i = 0; i < e1.length(); ++i)
		{
			if (e2.find(e1[i]) != std::string::npos && e3.find(e1[i]) != std::string::npos)
			{
				total_score += (std::isupper(e1[i]) ? e1[i] - 'A' + 27 : e1[i] - 'a' + 1);
				break;
			}
		}
	}
	std::cout << "total: " << total_score << std::endl;
}