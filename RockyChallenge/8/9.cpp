#include <iostream>
#include <string>

int main()
{
	std::string s1;
	std::string s2;

	std::cin >> s1 >> s2;
	bool rotation = false;

	for (int i = 0; i < s2.size(); ++i)
	{
		if (s1.size() != s2.size())
		{
			break;
		}

		for (int j = 0, x = i; j < s1.size(); ++j, ++x)
		{
			if (x == s2.size())
			{
				x = 0;
			}

			if (s1[j] != s2[x])
			{
				break;
			}

			if (j == s1.size() - 1)
			{
				rotation = true;
			}
		}
	}

	std::cout << rotation;

	return 0;
}