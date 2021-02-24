#include <iostream>
#include <string>
#include <vector>

bool palindrome_permutation(const std::string& str)
{
	std::vector<int> vec(256, 0);

	for (int i = 0; i < str.size(); ++i)
	{
		if ((int)str[i] == 32)
		{
			continue;
		}

		++vec[(int)str[i]];
	}

	short odds = 0;

	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] % 2 != 0)
		{
			++odds;

			if (odds == 2)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	std::string str;
	std::getline(std::cin, str);

	if (palindrome_permutation(str))
	{
		std::cout << "true\n";
	}
	else
	{
		std::cout << "false\n";
	}
}	