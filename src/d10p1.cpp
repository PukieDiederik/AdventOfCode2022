#include <iostream>
#include <string>

void checkCycle(int& total, int reg, int cycle)
{
	static int next_record = 20;
	if (cycle == next_record)
	{
//		std::cout << "cycle: " << cycle << ", strengh: " << (cycle * reg) << std::endl;
		total += cycle * reg;
		next_record += 40;
	}
}

int main()
{
	std::string command;
	int total = 0;
	int value;
	int reg = 1;
	int cycle = 0;

	while (std::cin >> command)
	{
		if(command == "addx")
		{
			++cycle;
			checkCycle(total, reg, cycle);
			++cycle;
			checkCycle(total, reg, cycle);
			std::cin >> value;
			reg += value;
		}
		else
		{
			++cycle;
			checkCycle(total, reg, cycle);
		}
	}
	std::cout << total << std::endl;
}