#include <iostream>
#include <string>
#include <vector>

void rabin_karp(const std::string& str, const std::string& sub_str)
{
	int size_str = str.size();
	int size_sub_str = sub_str.size();

	int pow = 31;
	std::vector<long long> p(size_str);
	p[0] = 1;
	for (int i = 1; i < size_str; ++i)
	{
		p[i] = p[i - 1] * pow;
	}

	long long hash_sub_str = 0;
	for (int i = 0; i < size_sub_str; ++i)
	{
		hash_sub_str += (sub_str[i] - 'a' + 1) * p[i];
	}

	std::vector<long long> hash_str(size_str);
	for (int i = 0; i < size_str; ++i)
	{
		hash_str[i] = (str[i] - 'a' + 1) * p[i];

		if (i)
		{
			hash_str[i] += hash_str[i - 1];
		}
	}

	long long pattern;
	for (int i = 0; i <= size_str - size_sub_str; ++i)
	{
		pattern = hash_str[i + size_sub_str - 1];

		if (i)
		{
			pattern -= hash_str[i - 1];
		}

		if (pattern == hash_sub_str * p[i])
		{
			std::cout << i << " ";
		}
	}
}

int main()
{
	std::string str;
	std::string sub_str;

	std::cin >> str;
	std::cin >> sub_str;

	rabin_karp(str, sub_str);
}