

#include "stdafx.h"
#include <iostream>
#include "my_mess.h"
#include "coord.h"

using namespace std;

void coord::alloc()
{
	try
	{
		pcoord = new double[2];
	}
	catch (bad_alloc)
	{
		my_mess exc(ERR_ALLOC_MEM);
	}
}

coord::coord(double xx, double yy)
{
	alloc();
	pcoord[0] = xx; pcoord[1] = yy;
}

coord::coord(const coord &ob)
{
	alloc();
	memcpy(pcoord, ob.pcoord, 2 * sizeof(double));
}

coord::coord(coord&& ob) noexcept
{
	pcoord = ob.pcoord;
	ob.pcoord = nullptr;
}

coord& coord::operator = (const coord& ob)
{
	if (pcoord)
		delete[] pcoord;
	pcoord = NULL;

	if (ob.pcoord)
	{
		alloc();
		memcpy(pcoord, ob.pcoord, 2 * sizeof(double));
	}

	return *this;
}

coord& coord::operator = (coord&& ob) noexcept
{
	if (this != &ob)
	{
		if (pcoord)
			delete[] pcoord;
		
		pcoord = ob.pcoord;
		ob.pcoord = nullptr;
	}

	return *this;
}

coord::~coord()
{
	if (pcoord)
		delete[] pcoord;
	pcoord = NULL;
}

ostream& operator << (ostream& strm, const coord& ob)
{
	if (ob.pcoord)
	{
		strm << "x = " << ob.pcoord[0] << " y = " << ob.pcoord[1] << endl;
	}
	
	return strm;
}

istream& operator >> (istream& strm, coord& ob)
{
	if (!ob.pcoord)
		ob.alloc();
	
	cout << "input x, y\n";
	strm >> ob.pcoord[0] >> ob.pcoord[1];
	
	return strm;
}

fstream& operator << (fstream& strm, const coord* ob)
{
	streamsize numbytestowrite = static_cast<streamsize>(_msize(ob->pcoord));
	strm.write(reinterpret_cast<const char*>(ob->pcoord), numbytestowrite);
	return strm; 
}

fstream& operator >> (fstream& strm, coord* ob)
{
	if (!ob->pcoord)
		ob->alloc();

	streamsize numbytestoread = static_cast<streamsize>(_msize(ob->pcoord));
	strm.read(reinterpret_cast<char*>(ob->pcoord), numbytestoread);

	return strm;
}

ofstream& operator << (ofstream& strm, const coord* ob)
{
	//Excel cvs format
	strm << ob->pcoord[0] << "; " << ob->pcoord[1] << ";\n";
	return strm;
}
