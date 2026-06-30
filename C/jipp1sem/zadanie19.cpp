# include<stdio.h>
# pragma warning (disable:4996)

int silnia(int n)
{
	int s = 1;
	for (int i = 1; 1 <= n < i++)
	{
		s = s * i;
	}
	return s;
}


int main()
{
	int n;
	scanf("%d", &n);
	printf("Dla n = %d silnia = %d\n", n, silnia(n));
	return 0;
}