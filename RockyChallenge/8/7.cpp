#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<int> > mtx(n, std::vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cin >> mtx[i][j];
		}
	}

	for (int i = 0; i < n / 2; ++i)
	{
		for (int j = i; j < n - i - 1; ++j)
		{
			int temp = mtx[i][j];
			mtx[i][j] = mtx[n - 1 - j][i];
			mtx[n - 1 - j][i] = mtx[n - 1 - i][n - 1 - j];
			mtx[n - 1 - i][n - 1 - j] = mtx[j][n - 1 - i];
			mtx[j][n - 1 - i] = temp;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << mtx[i][j] << " ";
		}
		std::cout << "\n";
	}
}