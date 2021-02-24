#include <iostream>
#include <string>
#include <vector>

bool edit(const std::string& str1, const std::string& str2)
{
	std::vector<int> vec1(256, 0);
	std::vector<int> vec2(256, 0);

	for (int i = 0; i < str1.size(); ++i)
	{
		++vec1[(int)str1[i]];
	}

	for (int i = 0; i < str2.size(); ++i)
	{
		++vec2[(int)str2[i]];
	}

	int no_edit = 0;

	if (str1.size() == str2.size())
	{
		for (int i = 0; i < vec1.size(); ++i)
		{
			if (vec1[i] + 1 == vec2[i] || vec1[i] - 1 == vec2[i])
			{
				++no_edit;

				if (no_edit > 2)
				{
					return false;
				}

				continue;
			}

			if (vec1[i] != vec2[i])
			{
				return false;
			}
		}

		return true;
	}

	no_edit = 0;

	for (int i = 0; i < vec1.size(); ++i)
	{
		if (vec1[i] + 1 == vec2[i] || vec1[i] - 1 == vec2[i])
		{
			++no_edit;

			if (no_edit > 1)
			{
				return false;
			}

			continue;
		}

		if (vec1[i] != vec2[i])
		{
			return false;
		}
		
	}

	return true;
}

int main()
{
	std::string str1;
	std::string str2;
	std::cin >> str1 >> str2;

	if (edit(str1, str2))
	{
		std::cout << "true\n";
	}
	else
	{
		std::cout << "false\n";
	}

	return 0;
}