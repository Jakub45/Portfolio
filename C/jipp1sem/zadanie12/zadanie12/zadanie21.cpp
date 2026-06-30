# include <stdio.h>
# pragma warning (disable:4996)

int main() {
	int la, lb, lc, l;
	char z;
	la = lb = lc = l = 0;
	while (true) {
		scanf("%c", &z);
		getchar();
		if (z == 'e') break;
		if (z == 'a'){
			la++;
			continue;
		}
		if (z == 'b') {
			lb++;
			continue;
		}
		if (z == 'c') {
			lc++;
			continue;
		}
		l++;
}

}