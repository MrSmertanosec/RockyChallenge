#include <iostream>

int* merge(int* arr1, int* arr2, int n, int m)
{
	int* merged_arr = new int[n + m];

	int min;
	if (n < m)
	{
		min = n;
	}
	else
	{
		min = m;
	}

	int j = 0;
	int k = 0;
	int i = 0;
	for (; j < n && k < m; ++i)
	{
		if (arr1[j] <= arr2[k])
		{
			merged_arr[i] = arr1[j];
			++j;
			continue;
		}
		else
		{
			merged_arr[i] = arr2[k];
			++k;
			continue;
		}
	}

	if (n < m)
	{
		for (; i < n + m; ++i, ++k)
		{
			merged_arr[i] = arr2[k];
		}
	}

	if (n > m)
	{
		for (; i < n + m; ++i, ++j)
		{
			merged_arr[i] = arr1[j];
		}
	}

	if (n == m)
	{
		if (k != 0)
		{
			merged_arr[n + m - 1] = arr2[k];
		}

		if (k == 0)
		{
			for (; i < n + m; ++i, ++k)
			{
				merged_arr[i] = arr2[k];
			}
		}

		if (j == 0)
		{
			for (; i < n + m; ++i, ++j)
			{
				merged_arr[i] = arr1[j];
			}
		}

	}

	return merged_arr;
}

int main()
{
	int n;
	std::cin >> n;
	int* arr1 = new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr1[i];

		if (i > 0 && arr1[i] < arr1[i - 1])
		{
			std::cout << "Enter element greater than previous\n";
			--i;
			continue;
		}
	}

	int m;
	std::cin >> m;
	int* arr2 = new int[m];

	for (int i = 0; i < m; ++i)
	{
		std::cin >> arr2[i];

		if (i > 0 && arr2[i] < arr2[i - 1])
		{
			std::cout << "Enter element greater than previous\n";
			--i;
			continue;
		}
	}

	int* merged_arr = merge(arr1, arr2, n, m);
	
	for (int i = 0; i < n + m; ++i)
	{
		std::cout << merged_arr[i] << " ";
	}

	return 0;
}