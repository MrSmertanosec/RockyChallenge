#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

//https://www.browserling.com/tools/random-ip

class IP
{
private:
	int first;
	int second;
	int third;
	int fourth;

public:
	IP(const std::string& line)
	{
		int j = 0;
		int count = 0;
		std::string sub;
		for (int i = 0; i < line.size(); ++i)
		{
			if (line[i] == '.')
			{
				sub = line.substr(j, i - j);
				j = i + 1;
				++count;
			}

			if (i == line.size() - 1)
			{
				sub = line.substr(j);
				fourth = std::stoi(sub);
			}

			if (count == 1)
			{
				first = std::stoi(sub);
				continue;
			}

			if (count == 2)
			{
				second = std::stoi(sub);
				continue;
			}

			if (count == 3)
			{
				third = std::stoi(sub);
				continue;
			}

		}
	}

	int get_first()
	{
		return first;
	}
	int get_second()
	{
		return second;
	}
	int get_third()
	{
		return third;
	}
	int get_fourth()
	{
		return fourth;
	}

	bool operator==(const IP& ip)
	{
		return (this->first == ip.first &&
			this->second == ip.second &&
			this->third == ip.third &&
			this->fourth == ip.fourth);
	}

	bool operator!=(const IP& ip)
	{
		return !(*this == ip);
	}

	bool operator<(const IP& ip)
	{
		if (this->first < ip.first)
		{
			return true;
		}
		if (this->first > ip.first)
		{
			return false;
		}
		if (this->second < ip.second)
		{
			return true;
		}
		if (this->second > ip.second)
		{
			return false;
		}
		if (this->third < ip.third)
		{
			return true;
		}
		if (this->third > ip.third)
		{
			return false;
		}
		if (this->first < ip.first)
		{
			return true;
		}
		if (this->first < ip.first)
		{
			return false;
		}

		return false;
	}

	bool operator>(const IP& ip)
	{
		return !(*this < ip);
	}

	friend std::ostream& operator<<(std::ostream& os, const IP& ip);
};

std::ostream& operator<<(std::ostream& os, const IP& ip)
{
	os << ip.first << '.' << ip.second << '.' << ip.third << '.' << ip.fourth;
	return os;
}

int main()
{
	std::fstream file("IP.txt", std::ios::in);

	std::vector<IP> vec;
	std::string line;

	while (std::getline(file, line))
	{
		vec.push_back(IP(line));
	}

	file.close();
	
	std::sort(vec.begin(), vec.end());

	file.open("result.txt", std::ios::out);
	
	for (int i = 0; i < vec.size(); ++i)
	{
		file << std::to_string(vec[i].get_first()) << '.' << std::to_string(vec[i].get_second()) << '.' <<
			std::to_string(vec[i].get_third()) << '.' << std::to_string(vec[i].get_fourth()) << '\n';
		std::cout << vec[i] << "\n";
	}

	return 0;
}