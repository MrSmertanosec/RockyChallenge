#include <iostream>
#include <vector>
#include <ctime>

class Table
{
private:
	std::vector<std::vector<int> > table;

	void player()
	{
		int cell;

		while (1)
		{
			std::cin >> cell;

			if (cell < 1 || cell > 9)
			{
				std::cout << "Please enter number 1 - 9\n";
				continue;
			}

			--cell;

			if (table[cell / 3][cell % 3] != -1)
			{
				std::cout << "This cell is already used\n";
				continue;
			}

			break;
		}
		
		table[cell / 3][cell % 3] = 1;
		
		com();
	}

	std::pair<int, int> check_win()
	{
		int o = 0;
		int x = 0;
		int o2 = 0;
		int x2 = 0;
		int o3 = 0;
		int x3 = 0;
		int o4 = 0;
		int x4 = 0;
		std::pair<int, int> pair;
		std::pair<int, int> pair2;
		std::pair<int, int> pair3;
		std::pair<int, int> pair4;
		
		for (int i = 0; i < 3; ++i)
		{
			if (table[0][i] == 1)
			{
				++x;
			}
		
			if (table[0][i] == 0)
			{
				++o;
			}
			
			if (table[0][i] == -1)
			{
				pair.first = 0;
				pair.second = i;
			}
		
			if (table[i][0] == 1)
			{
				++x2;
			}
		
			if (table[i][0] == 0)
			{
				++o2;
			}
		
			if (table[i][0] == -1)
			{
				pair2.first = i;
				pair2.second = 0;
			}
		
			if (table[2][i] == 1)
			{
				++x3;
			}
		
			if (table[2][i] == 0)
			{
				++o3;
			}
		
			if (table[2][i] == -1)
			{
				pair3.first = 2;
				pair3.second = i;
			}
		
			if (table[i][2] == 1)
			{
				++x4;
			}
		
			if (table[i][2] == 0)
			{
				++o4;
			}
		
			if (table[i][2] == -1)
			{
				pair4.first = i;
				pair4.second = 2;
			}
		
		}
		
		int x5 = 0;
		int o5 = 0;
		int x1 = 0;
		int o1 = 0;
		int x6 = 0;
		int o6 = 0;
		int x7 = 0;
		int o7 = 0;
		std::pair<int, int> pair1;
		std::pair<int, int> pair5;
		std::pair<int, int> pair6;
		std::pair<int, int> pair7;
		
		for (int i = 0; i < 3; ++i)
		{
			if (table[i][i] == 1)
			{
				++x5;
			}

			if (table[i][i] == 0)
			{
				++o5;
			}

			if (table[i][i] == -1)
			{
				pair5.first = i;
				pair5.second = i;
			}
		
			if (table[2 - i][i] == 1)
			{
				++x1;
			}
		
		
			if (table[2 - i][i] == 0)
			{
				++o1;
			}

			if (table[2 - i][i] == -1)
			{
				pair1.first = 2 - i;
				pair1.second = i;
			}

			if (table[1][i] == 1)
			{
				++x6;
			}

			if (table[1][i] == 0)
			{
				++o6;
			}

			if (table[1][i] == -1)
			{
				pair6.first = 1;
				pair6.second = i;
			}

			if (table[i][1] == 1)
			{
				++x7;
			}

			if (table[i][1] == 0)
			{
				++o7;
			}

			if (table[i][1] == -1)
			{
				pair7.first = i;
				pair7.second = 1;
			}
		
		}

		if (o == 3 || o2 == 3 || o3 == 3 || o4 == 3)
		{
			return std::pair<int, int>(0, 3);
		}
		if (o5 == 3 || o1 == 3 || o6 == 3 || o7 == 3)
		{
			return std::pair<int, int>(0, 3);
		}
		if (x == 3 || x2 == 3 || x3 == 3 || x4 == 3)
		{
			return std::pair<int, int>(3, 0);
		}
		if (x5 == 3 || x1 == 3 || x6 == 3 || x7 == 3)
		{
			return std::pair<int, int>(3, 0);
		}

		if ((x == 0 && o == 2))
		{
			return pair;
		}

		if ((x2 == 0 && o2 == 2))
		{
			return pair2;
		}

		if ((x3 == 0 && o3 == 2))
		{
			return pair3;
		}

		if ((x4 == 0 && o4 == 2))
		{
			return pair4;
		}

		if ((x5 == 0 && o5 == 2))
		{
			return pair5;
		}

		if ((x1 == 0 && o1 == 2))
		{
			return pair1;
		}

		if ((x6 == 0 && o6 == 2))
		{
			return pair6;
		}

		if ((x7 == 0 && o7 == 2))
		{
			return pair7;
		}

		if ((x == 2 && o == 0))
		{
			return pair;
		}

		if ((x2 == 2 && o2 == 0))
		{
			return pair2;
		}

		if ((x3 == 2 && o3 == 0))
		{
			return pair3;
		}

		if ((x4 == 2 && o4 == 0))
		{
			return pair4;
		}

		if ((x5 == 2 && o5 == 0))
		{
			return pair5;
		}
		
		if ((x1 == 2 && o1 == 0))
		{
			return pair1;
		}

		if ((x6 == 2 && o6 == 0))
		{
			return pair6;
		}

		if ((x7 == 2 && o7 == 0))
		{
			return pair7;
		}

		return std::pair<int, int>(-1, -1);
	}

	std::pair<int, int> check_danger()
	{

		std::pair<int, int> pair = check_win();

		if (pair.first != -1)
		{
			return pair;
		}

		int i = -1;
		int j = -1;

		while (!check_draw())
		{
			i = ((rand() % 10) + 1) % 3;
			j = ((rand() % 10) + 1) % 3;
			
			if (table[i][j] == -1)
			{
				break;
			}
		}

		return std::pair<int, int>(i, j);
		

	}

	bool check_draw()
	{

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (table[i][j] == -1)
				{
					return false;
				}
			}
		}

		return true;
	}

	void com()
	{
		std::pair<int, int> pair = check_danger();

		if (pair.first == 3)
		{
			std::cout << "Player wIns\n";
			return;
		}

		if (pair.second == 3)
		{
			std::cout << "Com wIns\n";
			return;
		}

		if (check_draw())
		{
			std::cout << "Draw\n";
			return;
		}

		table[pair.first][pair.second] = 0;

		pair = check_win();
		print();

		if (pair.first == 3)
		{
			std::cout << "Player wIns\n";
			return;
		}

		if (pair.second == 3)
		{
			std::cout << "Com wIns\n";
			return;
		}

		
		player();
	}

public:
	Table()
	{
		table = {
			{-1, -1, -1},
			{-1, -1, -1},
			{-1, -1, -1}
		};
	}

	void print()
	{
		for (int i = 2; i >= 0; --i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (table[i][j] == 1)
				{
					std::cout << " X ";
				}

				if (table[i][j] == 0)
				{
					std::cout << " O ";
				}

				if (table[i][j] == -1)
				{
					std::cout << "   ";
				}

				if (j != 2)
				{
					std::cout << "|";
				}
			}

			std::cout << "\n";
			if (i != 0)
			std::cout << "===========\n";
		}
	}

	void reset()
	{
		table = {
			{-1, -1, -1},
			{-1, -1, -1},
			{-1, -1, -1}
		};
	}

	void play()
	{
		reset();
		player();
	}

	

};