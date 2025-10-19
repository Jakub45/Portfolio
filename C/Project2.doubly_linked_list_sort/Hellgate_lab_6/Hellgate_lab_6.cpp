


// Program do wpisywania studentow do listy. Mozliwosc sortowania w zaleznosci od kategorii (po imieniu, po nazwisku, po dacie urodzenia etc).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

typedef struct list {
	char name[50];
	char surname[50];
	int birth_year;
	char city[50];
	double stypendium;

	struct list* next;
	struct list* prev;
}list;



list* create_list(list* head, char value1[50], char value2[50],  int value3, char value4[50], double value5) {
	list* node = (list*)malloc(sizeof(list));
	if (node == NULL) {
		printf("memory allocation failure\n");
		exit(1);
	}
	strcpy(node->name, value1);
	strcpy(node->surname, value2);
	node->birth_year = value3;
	strcpy(node->city, value4);
	node->stypendium = value5;
	node->next = head;
	return node;
}

void swap_nodes(list* a, list* b) {
	char tmpname[50], tmpsurname[50], tmpcity[50];
	int tmpbirth_year;
	double tmpstypendium;

	strcpy(tmpname, a->name);
	strcpy(tmpsurname, a->surname);
	tmpbirth_year = a->birth_year;
	strcpy(tmpcity, a->city);
	tmpstypendium = a->stypendium;

	strcpy(a->name, b->name);
	strcpy(a->surname, b->surname);
	a->birth_year = b->birth_year;
	strcpy(a->city, b->city);
	a->stypendium = b->stypendium;

	strcpy(b->name, tmpname);
	strcpy(b->surname, tmpsurname);
	b->birth_year = tmpbirth_year;
	strcpy(b->city, tmpcity);
	b->stypendium = tmpstypendium;
}

void sort_list(list* head, int value) {
	list* current;
	int swapped;
	if (head == NULL) return;  // nic nie sortujemy, lista pusta
	do {
		swapped = 0;
		current = head;

		while (current->next != NULL) {
			int cmp = 0;
			if (value == 1) {
				cmp = strcmp(current->name, current->next->name);
			}
			else if (value == 2) {
				cmp = strcmp(current->surname, current->next->surname);
			}
			else if (value == 3) {
				cmp = current->birth_year - current->next->birth_year;
			}
			else if (value == 4) {
				cmp = strcmp(current->city, current->next->city);
			}
			else if (value == 5) {
				cmp = (current->stypendium > current->next->stypendium) ? 1 : -1;
			}

			if (cmp > 0) {
				swap_nodes(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
	} while (swapped);
}


void printlist(list* head) {
	printf("\n\n\n");
	while (head != NULL) {
		printf("%s %s %d %s %.2lf\n", head->name, head->surname, head->birth_year, head->city, head->stypendium);
		head = head->next;
	}
}

void savelist(list* head) {
	FILE* file = fopen("studenci.txt", "w");
	while (head != NULL) {
		fprintf(file,"%s %s %d %s %.2lf\n", head->name, head->surname, head->birth_year, head->city, head->stypendium);
		head = head->next;
	}
}

void freeList(list* head) {
	list* tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int main() {



	char word1[50];
	char word2[50];
	int word3;
	char word4[50];
	double word5;

	list* head = NULL;

	FILE* file = fopen("studenci.txt", "a+");
	if (file == NULL) {
		printf("File not found");
		return 0;
	}
	else {
		while (fscanf(file, "%49s %49s %d %49s %lf", word1, word2, &word3, word4, &word5) == 5){
			head = create_list(head, word1, word2, word3, word4, word5);
		}
		fclose(file);
	}


	//sorting
	int sort_type;
	char sort_type_scan;
	printf("select category of list sorting, by name(n), surname (s), birth_year(b), city(c), stypendium (t).");
	scanf("%c", &sort_type_scan);
	if (sort_type_scan == 'n') {
		sort_type = 1;
	}
	else if (sort_type_scan == 's') {
		sort_type = 2;
	}
	else if (sort_type_scan == 'b') {
		sort_type = 3;
	}
	else if (sort_type_scan == 'c') {
		sort_type = 4;
	}
	else if (sort_type_scan == 't') {
		sort_type = 5;
	}
	else {
		printf("Unknown option, defaulting to sort by name.");
		sort_type = 1;
	}

	sort_list(head, sort_type);

	//adding new object
	char new_student;
	printf("Do you want to add new student ? (y/n)\n");
	scanf(" %c",&new_student);
	if (new_student == 'y') {

		printf("enter name:");
		scanf("%49s", word1);
		printf("enter surname:");
		scanf("%49s", word2);
		printf("enter birth_year:");
		scanf("%d", &word3);
		printf("enter city:");
		scanf("%49s", word4);
		printf("enter stypendium:");
		scanf("%lf", &word5);

	}


	head = create_list(head, word1, word2, word3, word4, word5);
	sort_list(head, sort_type);

	printlist(head);
	savelist(head);

	freeList(head);

	return 0;
}
