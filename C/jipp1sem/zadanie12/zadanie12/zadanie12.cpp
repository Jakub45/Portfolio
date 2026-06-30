/*

# include<stdio.h>
# pragma warning (disable:4996)

//12. Napisz program, który przy pomocy rekurencji wyznaczy sumę n kolejnych liczb naturalnych
//(liczba n podawana przez użytkownika; suma obliczana w dedykowanej funkcji).Korzystając z
//dokumentacji MSDN zapoznaj się z pojęciem rekurencji :
// https://docs.microsoft.com/en-us/cpp/c-language/recursive-functions?view=vs-201

double n=1;
double sum;
bool is_on = true;


double f();

int main() {
	f();
}


double f() {
	n += 1;
	sum += n;
	printf("%f", &sum);

	if (is_on) {
		void f();
	}
	return 0;
}


*/

#include <stdio.h>
#include <iostream>
using namespace std;

long long suma(int n)
{
	if (n < 1)
		return 0;

	return n + suma(n - 1);
}

int main()
{
	int n;

	cout << "Podaj liczbe: ";
	cin >> n;

	cout << "Suma " << n << " kolejnych liczb naturalnych wynosi "
		<< suma(n) << endl;

	return 0;
}