#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::getline(std::cin, str);

	std::string new_str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (isspace(str[i]))
		{
			bool end = true;

			for (int j = i; j < str.size(); ++j)
			{
				if (!isspace(str[j]))
				{
					end = false;
				}
			}

			if (!end)
			{
				new_str.push_back('%');
				new_str.push_back('2');
				new_str.push_back('0');
			}
		}
		else
		{
			new_str.push_back(str[i]);
		}
	}

	str = new_str;
	std::cout << str;
}