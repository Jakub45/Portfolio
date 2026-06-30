#pragma once
# include <stdio.h>
#pragma warning(disable:4996)




double max_quantity_of_values;
char changes;
bool antything_else;
char param_change;

int if_changes() {
	printf("You want to make aonther changes of values ? y/n");
	scanf("%c", &changes);

	if (changes == 'y') {
		printf("What parameter you want to change ? 1 is interval, 2 max_quantity_of_values, 3 accuracy.");
		scanf("%c", &param_change);
		if (param_change == '1') {
			//BUDOWA, BUDOWA, AUUUUUU
		}
		if (param_change == '2') {
			//BUDOWA, BUDOWA, AUUUUUU
		}
		if (param_change == '3') {
			//BUDOWA, BUDOWA, AUUUUUU
		}
		//BUDOWA, BUDOWA, AUUUUUU
	}

	return 0;
}


//int declarations() {
	//scanf("%e%e", &interval, &max_quantity_of_values);
	//return 0;
	//BUDOWA, BUDOWA, AUUUUUU
//}

