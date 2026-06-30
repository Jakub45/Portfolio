///////////////////////////////////////////////////////////////////
//    coord.h

#pragma once

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "my_mess.h"
using namespace std;

class coord
{
	double* pcoord;
public:
	
	coord(double xx, double yy);
	coord() : pcoord(NULL) { }
	coord(const coord& ob);
	coord(coord&& ob) noexcept;
	~coord();
	coord& operator = (const coord& ob);
	coord& operator = (coord&& ob) noexcept;
	
	bool operator == (const coord &ob) const
	{
		return (fabs(pcoord[0] - ob.pcoord[0]) < 1e-10 && fabs(pcoord[1] - ob.pcoord[1]) < 1e-10);
	}

	friend ostream& operator << (ostream& strm, const coord& ob);
	friend istream& operator >> (istream& strm, coord& ob);
	friend fstream& operator << (fstream& strm, const coord* ob);
	friend fstream& operator >> (fstream& strm, coord* ob);
	friend ofstream& operator << (ofstream& strm, const coord* ob);

private:
	void alloc();
};
