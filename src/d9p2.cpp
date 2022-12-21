#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

typedef std::tuple<int, int> position;

void moveHead(char dir, position& head)
{
	switch(dir)
	{
		case 'U':
			++std::get<1>(head);
			break;
		case 'D':
			--std::get<1>(head);
			break;
		case 'L':
			--std::get<0>(head);
			break;
		case 'R':
			++std::get<0>(head);
			break;
	}
}

void updateTail(position& tail, const position& head)
{
	int hx = std::get<0>(head) , hy = std::get<1>(head);
	int tx = std::get<0>(tail) , ty = std::get<1>(tail);

	if (hx >= tx - 1 && hx <= tx + 1
		&& hy >= ty - 1 && hy <= ty + 1)
		return;
	// straight
	if (tx == hx)
		std::get<1>(tail) += (ty < hy) ? 1 : -1;
	else if (ty == hy)
		std::get<0>(tail) += (tx < hx) ? 1 : -1;
	// diagonal
	else
	{
		std::get<0>(tail) += (tx < hx) ? 1 : -1;
		std::get<1>(tail) += (ty < hy) ? 1 : -1;
	}
}

int main()
{
	char dir;
	position h(0,0);
	position t[10];
	std::vector<position> v;

	std::fill_n(t, 10, position(0,0));
	v.push_back(position(0,0));
	while (std::cin >> dir)
	{
		//apply input
		int amount;
		std::cin >> amount;
		for (; amount > 0; --amount)
		{
			moveHead(dir, h);
			//update the tail
			t[0] = h;
			for(int i = 1; i < 10; ++i)
			{
				updateTail(t[i], t[i - 1]);
			}
			if(std::find_if(v.begin(), v.end(),
			[t](const position &p) -> bool
				{
					return (std::get<0>(t[9]) == std::get<0>(p) && std::get<1>(t[9]) == std::get<1>(p));
				}) == v.end())
				v.push_back(t[9]);
		}
	}
	std::cout << v.size() << std::endl;
}