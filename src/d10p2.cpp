#include <iostream>
#include <string>

void doCycle(int &cycle, int reg)
{
	if (cycle % 40 == 0 && cycle != 0)
		std::cout << std::endl;
	++cycle;
	std::cout << ((((cycle - 1) % 40) + 1 >= reg % 40 && ((cycle - 1) % 40) + 1 <= reg % 40 + 2) ? '#' : ' ');
}

int main()
{
	std::string command;
	int reg = 1;
	int value;


	std::cin >> command;
	for(int cycle = 0; cycle < 6 * 40; std::cin >> command)
	{
		doCycle(cycle, reg);
		if (command == "addx")
		{
			doCycle(cycle, reg);
			std::cin >> value;
			reg += value;
		}
	}
	std::cout << std::endl;
}