#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> elves;
	int cur_elf = 0;
	std::string s;

	while (std::getline(std::cin, s, '\n')) {
		if (s.empty()) {
			elves.push_back(cur_elf);
			cur_elf = 0;
		} else
			cur_elf += std::stoi(s);
	}
	elves.push_back(cur_elf);

	int total = 0;
	auto temp = std::max_element(elves.begin(), elves.end());
	total += *temp;
	elves.erase(temp);
	temp = std::max_element(elves.begin(), elves.end());
	total += *temp;
	elves.erase(temp);
	total += *std::max_element(elves.begin(), elves.end());

	std::cout << total << std::endl;
}
