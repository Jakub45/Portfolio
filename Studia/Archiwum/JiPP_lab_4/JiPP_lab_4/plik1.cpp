#include <iostream>
#include <memory.h>
#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define LL 200

extern void error(int, char*);
extern double* DajWekt(int);


void argumenty(int, const char**);

int main(int argc, const char* argv[])
{
	double x[LL], y[LL], z[LL], s, mx, my;
	FILE* fw, * fd;
	int n, k;
	argumenty(argc, argv);
	if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
	if (!(fw = fopen(argv[2], "w"))) error(2, "wyniki");
	fscanf(fd, "%d", &n);

	x = DajWekt(n);
	y = DajWekt(n);
	z = DajWekt(n);


	for (k = 0; k < n; k++)
		fscanf(fd, "%lf", &x[k]);
	for (k = 0; k < n; k++)
		fscanf(fd, "%lf", &y[k]);
	s = 0;
	mx = x[0];
	my = y[0];
	for (k = 0; k < n; k++)
	{
		z[k] = x[k] + y[k];
		mx = x[k] > mx ? x[k] : mx;
		my = y[k] > my ? y[k] : my;
		s += x[k] * y[k];
	}
	for (k = 0; k < n; k++)
	{
		fprintf(fw, "%lf ", z[k]);
		if (!((k + 1) % 5)) fprintf(fw, "\n");
	}
	fprintf(fw, "\nilocz.skal=%lf mx=%lf my=%lf\n", s, mx, my);
}
void argumenty(int argc, char* argv[])
{
	int len;
	char* usage;
	if (argc != 3)
	{
		len = strlen(argv[0]) + 19;
		if (!(usage = (char*)malloc((unsigned)len * sizeof(char))))
			error(3, "tablica usage");
		strcpy(usage, argv[0]);
		strcat(usage, " file_in file_out");
		error(4, usage);
	}
}