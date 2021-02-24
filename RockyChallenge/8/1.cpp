#include <iostream>
#include <string>
#include <algorithm>

bool is_unique(std::string str)
{
	std::sort(str.begin(), str.end());

	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i] == str[i - 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	std::string str;
	std::cin >> str;

	std::cout << is_unique(str);

	return 0;
}