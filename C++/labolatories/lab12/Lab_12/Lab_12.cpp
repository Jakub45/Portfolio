// Lab_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Header.h"

using namespace std;

bool CoordCompare(coord elem1, coord elem2)
{
	return elem1 == elem2;
}

bool SortDescending(coord elem1, coord elem2)
// the function-predicate SortDescending is a binary predicate
// returns bool and has two arguments
// for sorting in descending order by vector length, 
// SortDescending should return true if the length of r1 of element1 is 
// greater than the length of ro2 of element2, where element1 and element2 are 
// two consecutive elements of a dynamic array represented by container-class 
// vector
{
	double ro1 = elem1, ro2 = elem2;
	// The expression double ro1 = elem1 makes sense only when we introduce a 
	//function that converts the operator double () {return (we're taking the length of the vector)}
	return ro1 > ro2;
}

int main()
{
	//numb – number of points onto plaine
	size_t numb = 20, ind, fract, it;
	const double PI = 3.14159236;
	double x, y, ro, fi, dfi = 2.0 * PI / numb;
	coord tmp(0, 0);    // Auxilary object
	
	vector<coord> vec;  // dynamic array for the coord data type
	vector<coord>::iterator It_end;   //introduce the iterator to the
									  // container class vector , datatype – coord
	srand(static_cast<unsigned int>(time(NULL)));

	//preparation of an array of objects of coord type presenting a points 
	//with the polar coordinates {ro, fi}. 
	//Then, we calculate cartesian coordinates and push this point to vector vec.
	for (it = 0; it < numb; it++)
	{
		//radius is randomly calculated
		ind = rand() % 5;
		fract = rand() % 10;
		fi = dfi * it;
		ro = ind + 0.1 * fract + 1.0;
		x = ro * cos(fi);
		y = ro * sin(fi);
		// create a coord type object with x, y coordinates
		tmp.set(x, y);
		// put at the end of the vec array
		vec.push_back(tmp);
	}

	// we display the set of points on the monitor with the disp 
	//template function
	disp(vec, "initial vec", true);

	// sort array of coord
	// in descending order (vector length)
	// ob.ro[i] > ob.ro[i+1]
	// algoritm sort uses a predicate-functions SortDescending
	sort(vec.begin(), vec.end(), SortDescending);
	disp(vec, "sorted in descending order vec", true);

	// deletion of vectors with the same length
	//algorithm unique uses a predicate-functions CoordCompare
	It_end = unique(vec.begin(), vec.end(), CoordCompare);
	cout << " ind = " << It_end - vec.begin() << endl;
	disp(vec, "after unique vec");

	// truncate vec after unique call
	vec.erase(It_end, vec.end());
	disp(vec, "after erase vec");

	vec.clear();
	system("pause");
	return 0;
}