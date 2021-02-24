#include <iostream>
#include <string>
#include <algorithm>

bool check_permutation(const std::string& str1, const std::string& str2, int index)
{
	if (!str1.compare(str2))
	{
		return true;
	}

	for (int i = index; i < str1.size(); ++i)
	{
		std::string temp = str1;

		std::swap(temp[index], temp[i]);

		if (check_permutation(temp, str2, index + 1))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	std::string str1;
	std::string str2;

	std::cin >> str1 >> str2;
	if (check_permutation(str1, str2, 0))
	{
		std::cout << "true";
	}
	else
	{
		std::cout << "false";
	}
}