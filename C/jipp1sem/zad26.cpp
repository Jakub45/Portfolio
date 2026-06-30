#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]) {
	FILE* fp = NULL;
	fp = fopen("lab2.txt", "w");
	if (fp == NULL) {
		printf("Nie mogæ otworzyã pliku lab2.txt do zapisu!\n");
		getchar();
		exit(1);
	}
	char tekst[] = "Hello world w pliku :)";
	fprintf(fp, "%s", tekst);
	fclose(fp);
	fp = NULL;
	getchar();
	return 0;
}