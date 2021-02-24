#include <iostream>
#include "Table.cpp"

int main()
{
	srand(time(0));

	Table table;
	table.print();
	table.play();
}