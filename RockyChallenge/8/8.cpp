#include <iostream>
#include <vector>

void set_to_zero(std::vector<std::vector<int> >& mtx, int i, const std::vector<std::pair<int, int>>& pairs)
{
	bool column = false;
	bool row = false;

	for (int j = 0; j < i; ++j)
	{
		if (pairs[j].first == pairs[i].first)
		{
			row = true;
		}

		if (pairs[j].second == pairs[i].second)
		{
			column = true;
		}
	}

	if (!column)
	{
		for (int y = 0; y < mtx.size(); ++y)
		{
			mtx[y][pairs[i].second] = 0;
		}
	}

	if (!row)
	{
		for (int y = 0; y < mtx[0].size(); ++y)
		{
			mtx[pairs[i].first][y] = 0;
		}
	}
}

int main()
{
	int n;
	int m;
	std::cin >> n >> m;
	std::vector<std::vector<int> > mtx(n, std::vector<int>(m));
	std::vector<std::pair<int, int>> pairs;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> mtx[i][j];
		}
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mtx[i][j] == 0)
			{
				pairs.push_back(std::pair<int, int> (i, j));
			}
		}
	}

	for (int i = 0; i < pairs.size(); ++i)
	{
		set_to_zero(mtx, i, pairs);
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << mtx[i][j] << " ";
		}
		
		std::cout << "\n";
	}

	return 0;
}