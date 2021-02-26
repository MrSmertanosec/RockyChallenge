#include <iostream>
#include <string>

std::string compress(const std::string& str)
{
	std::string temp;
	int count = 1;
	
	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i] == str[i - 1])
		{
			++count;
			continue;
		}
		else
		{
			temp.push_back(str[i - 1]);
			std::string num = std::to_string(count);
			for (int i = 0; i < num.size(); ++i)
			{
				temp.push_back(num[i]);
			}
			count = 1;
		}
	}

	temp.push_back(str[str.size() - 1]);
	std::string num = std::to_string(count);
	for (int i = 0; i < num.size(); ++i)
	{
		temp.push_back(num[i]);
	}

	return temp;
}

int main()
{
	std::string str;
	std::cin >> str;

	std::string compressed = compress(str);
	std::cout << compressed;

	return 0;
}