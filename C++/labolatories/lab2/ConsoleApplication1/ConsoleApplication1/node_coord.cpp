#include <iostream>
#include "node_coord.h"

using namespace std;

NODE_COORD::NODE_COORD(double x, double y)
{
	try
	{
		pcoord = new double[2];
		pcoord[0] = x;
		pcoord[1] = y;
	}
	catch (bad_alloc)
	{
		crash();
	}
}
void NODE_COORD::crash()
{
	cout << "memory allocation error\n";
	system("pause");
	exit(1);
}
NODE_COORD::~NODE_COORD()
{
	if (pcoord)
	{
		pcoord = NULL;
		delete[] pcoord;

	}
}