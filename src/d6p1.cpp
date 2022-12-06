#include <iostream>

int main()
{
	char a, b, c ,d;

	std::cin >> d >> c >> b >> a;
	int i = 4;
	while (a == b || a == c || a == d || b == c || b == d || c == d)
	{
		++i;
		d = c;
		c = b;
		b = a;

		std::cin >> a;
	}
	std::cout << i << std::endl;
}