#pragma once

#include <iostream>
#include <vector>

#define CORRECT_COMPARE_FUNCTION

class coord
{
	double* cr;    // coordinates of a point in the plane cr [0] = x; cr [1] = y
public:
	coord() : cr(NULL) {}
	coord(double x, double y);
	~coord() { if (cr) delete[] cr; }
	void set(double x, double y);
	double* get() { return cr; }

	//
	operator double() const;
	coord(const coord& ob);
	coord& operator = (const coord& ob);
	bool operator == (const coord& ob) const;

private:
	void alloc();
};


template<typename T>
void disp(std::vector<T> &v, const char* str, bool mode = 0)
{
	if (mode)
	{
		//use a new standard C++: range-based loop for
		for (auto& p : v)
		{
			std::cout << p << std::endl;
		}
	}
	else
	{
		//use a conventional loop for
		typename std::vector<T>::iterator It;
		std::cout << str << std::endl;
		// view the dynamic array using the iterator
		for (It = v.begin(); It != v.end(); It++)
		{
			std::cout << *(It) << std::endl;  // get the value of the object using the iterator
		}
	}

	std::cout << "-------------------\n";
}


