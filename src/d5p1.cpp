#include <iostream>
#include <stack>
#include <string>

bool get_input(int& amount, int& from, int& to)
{
	std::cin.ignore(10, ' ') ;
	std::cin >> amount;
	std::cin.ignore(10, ' ') ;
	std::cin.ignore(10, ' ') ;
	std::cin >> from;
	std::cin.ignore(10, ' ');
	std::cin.ignore(10, ' ') ;
	std::cin >> to;
	return (std::cin.fail() || std::cin.eof());
}

int main()
{
	std::stack<char> towers[9];
	std::stack<std::string> inputs;
	std::string in;
	// get the input
	while (std::getline(std::cin, in) && !in.empty())
		inputs.push(in);
	// process input
	inputs.pop();
	while (!inputs.empty())
	{
		std::string::size_type i = 0;
		const std::string& s = inputs.top();
		while (i < s.length())
		{
			if (s[i] == '[')
				towers[i / 4].push(s[i + 1]);
			i += 4;
		}
		inputs.pop();
	}

	//start solving
	int amount, from, to;
	while (!get_input(amount, from, to))
	{
		for (; amount > 0; --amount)
		{
			towers[to - 1].push(towers[from - 1].top());
			towers[from - 1].pop();
		}
	}
	std::cout << towers[0].top() << towers[1].top() << towers[2].top() << towers[3].top() << towers[4].top()
			  << towers[5].top() << towers[6].top() << towers[7].top() << towers[8].top() << std::endl;
}