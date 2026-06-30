#include <iostream>

template<typename T>
T my_add (T a, T b,	T c){
	return c = a + b;
}




int _tmain(int argc, _TCHAR* argv[])
{
	// type NODE_COORD
	NODE_COORD ob1(2, 3), ob2(3, 4), ob;
	ob1.disp("ob1");
	ob2.disp("ob2");
	ob = my_add(ob1, ob2);
	ob.disp("ob");
	// type int
	int a = 2, b = 3, c;
	c = my_add(a, b);
	system("pause");
	return 0;
}
