#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	// Read input
	std::vector<std::string> v;
	for (std::string line; std::getline(std::cin, line); v.push_back(line));

	bool *foundTree = new bool[v.size() * v[0].length()] { false };

	// check left-right and right-left
	int total = 0;
	for (int y = 0; y < static_cast<int>(v.size()); ++y)
	{
		int biggest = 0;
		for (int x = 0; x < static_cast<int>(v[y].length()); ++x) {
			if (v[y][x] > biggest)
			{
//				std::cout << "biggest: " << biggest << " new: " << v[y][x] << std::endl;
			  	biggest = v[y][x];
				if (!foundTree[y * v[y].length() + x])
				{
					foundTree[y * v[y].length() + x] = true;
					++total;
				}
			}
		}
		biggest = 0;
		for (int x = v[y].length() - 1; x >= 0; --x) {
			if (v[y][x] > biggest)
			{
				biggest = v[y][x];
				if (!foundTree[y * v[y].length() + x])
				{
					foundTree[y * v[y].length() + x] = true;
					++total;
				}
			}
		}
	}
	// check up-down down-up
	for (int x = 0; x < static_cast<int>(v[0].size()); ++x)
	{
		int biggest = 0;
		for (int y = 0; y < static_cast<int>(v.size()); ++y) {
			if (v[y][x] > biggest)
			{
				biggest = v[y][x];
				if (!foundTree[y * v[y].length() + x])
				{
					foundTree[y * v[y].length() + x] = true;
					++total;
				}
			}
		}
		biggest = 0;
		for (int y = v.size() - 1; y >= 0; --y) {
			if (v[y][x] > biggest)
			{
				biggest = v[y][x];
				if (!foundTree[y * v[y].length() + x])
				{
					foundTree[y * v[y].length() + x] = true;
					++total;
				}
			}
		}
	}
	delete[] foundTree;
	std::cout << total << std::endl;
}