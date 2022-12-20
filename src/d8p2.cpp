#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int calc_scenic(std::vector<std::string>& v, int x, int y)
{
	if (x == 0 || y == 0 || x == static_cast<int>(v[0].length()) - 1 || y == static_cast<int>(v.size()) - 1)
		return (0);

	int total;
	int tmp_total = 1;
	// left
	for(int i = x - 1; i > 0 && v[y][i] < v[y][x]; --i)
		++tmp_total;
	total = tmp_total;
	tmp_total = 1;
	// right
	for(int i = x + 1; i < static_cast<int>(v[y].length() - 1) && v[y][i] < v[y][x]; ++i)
		++tmp_total;
	total *= tmp_total;
	tmp_total = 1;
	// up
	for(int i = y - 1; i > 0 && v[i][x] < v[y][x]; --i)
		++tmp_total;
	total *= tmp_total;
	tmp_total = 1;
	// down
	for(int i = y + 1; i < static_cast<int>(v.size() - 1) && v[i][x] < v[y][x]; ++i)
		++tmp_total;
	total *= tmp_total;
	return total;
}

int main()
{
	// Read input
	std::vector<std::string> v;
	for (std::string line; std::getline(std::cin, line); v.push_back(line));

	int biggest = 0;
	for (int y = 0; y < static_cast<int>(v.size()); ++y) {
		for (int x = 0; x < static_cast<int>(v[y].length()); ++x) {
			int tmp = calc_scenic(v, x, y);
			if (tmp > biggest)
				biggest = tmp;
		}
	}
	std::cout << biggest << std::endl;
}