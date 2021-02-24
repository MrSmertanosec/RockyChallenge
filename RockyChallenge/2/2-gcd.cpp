#include <iostream>
#include <cmath>

int gcd(int a, int b)
{
	int min;
	int max;

	if (a < b)
	{
		min = a;
		max = b;
	}
	else
	{
		min = b;
		max = a;
	}

	int div = 1;

	for (int i = 2; i <= min / 2; ++i)
	{
		if (a % i == 0 && b % i == 0)
		{
			div = i;
		}
	}

	if (max % min == 0)
	{
		div = min;
	}

	return div;
}

int main()
{
	int a;
	int b;
	std::cin >> a >> b;

	std::cout << gcd(a, b);
}