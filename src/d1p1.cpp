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

	std::cout << *std::max_element(elves.begin(), elves.end()) << std::endl;
}
