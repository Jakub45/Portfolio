#include "node_coord.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <cmath>

#define PI 3.14159265359
using namespace std;
#pragma warning(disable:4996)

NODE_COORD::NODE_COORD(double x, double y) {
	cout << "parametrized contructor" << endl;
	pcoord = new double[2]; //alokacja dla konstruktora
	pcoord[0] = x;
	pcoord[1] = y;
}
NODE_COORD::~NODE_COORD() {
	cout << "destructor" << endl;
	delete[] pcoord;
	pcoord = NULL;
}

void NODE_COORD::set(double x, double y) {

	if (pcoord != NULL) {
		this->pcoord[0] = x;
		this->pcoord[1] = y;
	}
	else {
		pcoord = new double[2]; //alokacja dla konstruktora
		pcoord[0] = x;
		pcoord[1] = y;
	}
}

void NODE_COORD::disp() {
	cout << "x = " << pcoord[0] << "\n" << "y = " << pcoord[1] << endl;
}

class MyCircle {
public:
	NODE_COORD* ptr;
	int npt;
	int radius;
	MyCircle(int npt,int radius);
	~MyCircle();

	void Prepare();
	void disp();
};

MyCircle::MyCircle(int npt,int radius) {
	ptr = new NODE_COORD[npt];
	this->npt = npt;
	this->radius = radius;
}

MyCircle::~MyCircle() {
	delete[] ptr;
	ptr = NULL;
}

void MyCircle::Prepare(){
	double x_axis;
	double y_axis;
	double temp;
	for (int i = 0; i < npt; i++) {
		temp = (2 * PI * i) / npt;
		x_axis = radius * cos(temp);
		y_axis = radius * sin(temp);
		ptr[i].set(x_axis, y_axis);
	}
}

void MyCircle::disp(){
	for (int i = 0; i < npt; i++) {
		ptr[i].disp();
	}
}




void crash_memory();

int main()
	{
	try {
		int npt, r;
		cout << "Enter number of points and radius r: ";
		cin >> npt >> r;
		MyCircle circle(npt, r);
		circle.Prepare(); //stworz punkty rownomiernie umieszczone na okregu
		circle.disp(); //wyswietli te punkty
	}
	catch (std::bad_alloc) {
		crash_memory();
	}
		
	if (_CrtDumpMemoryLeaks()) {
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Memory leaks detected! \ n";
	}
	else {
		cout << "No memory leaks detected. \ n";
	}

	return 0;
}

void crash_memory()
{
cout << "mem_alloc_err \ n";
system("pause");
//exit(1);
}