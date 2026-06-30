#include <iostream>
#include "Header.h"

using namespace std;

void coord::alloc()
{
	try
	{
		cr = new double[2];
		memset((void*)cr, 0, 2 * sizeof(double));
	}
	catch (bad_alloc xx)
	{
	}
}

coord::coord(double x, double y)
{
	alloc();
	cr[0] = x;
	cr[1] = y;
}

void coord::set(double x, double y)
{
	cr[0] = x;
	cr[1] = y;
}

coord::operator double() const
{
	double ro = cr[0] * cr[0] + cr[1] * cr[1];
	return sqrt(ro);
}

///////////////////////////////////////////////////////

coord::coord(const coord& ob)
{
	alloc();
	memcpy(cr, ob.cr, 2 * sizeof(double));
}

coord& coord::operator = (const coord& ob)
{
	if (cr)
		delete[] cr;
	cr = NULL;

	if (ob.cr)
	{
		alloc();
		memcpy(cr, ob.cr, 2 * sizeof(double));
	}

	return *this;
}

bool coord::operator == (const coord& ob) const
{
	double ro1 = *this, ro2 = ob;

#ifdef CORRECT_COMPARE_FUNCTION
	const double tol(1e-10);
	if (fabs(ro1 - ro2) < tol)
		return true;
	else
		return false;
#else
	return (ro1 == ro2);
#endif
}

