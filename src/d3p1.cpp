#include <iostream>
#include <string>

int main()
{
	int total_score = 0;
	std::string s;

	while (std::getline(std::cin, s))
	{
		std::string sp1 = s.substr(0, s.length() / 2);
		std::string sp2 = s.substr(s.length() / 2, std::string::npos);
		for(std::string::size_type i = 0; i < sp1.length(); ++i)
		{
			if (sp2.find(sp1[i]) != std::string::npos)
			{
				total_score += (std::isupper(sp1[i]) ? sp1[i] - 'A' + 27 : sp1[i] - 'a' + 1);
				break;
			}
		}
	}
	std::cout << "total: " << total_score << std::endl;
}