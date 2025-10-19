/* ==============================(zadanie2)=====================================
€

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)

double test(double j, double (*f)(double));

int main() {
	double x, y;
	x = 1;
	
	y = test(x, sin);
	printf("%f\n", y);

	y = test(x, cos);
	printf("%f\n", y);


	return 0;
}


double test(double j, double (*f)(double)){
	return pow(j, 2) + (*f)(j);
}


// ==============================(zadanie3)=====================================*/

/*


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)


double pochodna_funkcji(double k);
double funkcja(double k);


int main() {
	srand(time(NULL));



	double x = 900;
	int i = 0;
	while(1){


		if (x == 0) { // anti Newton to_zero fuckup.
			x = rand() % 5;
		}
		double y = funkcja(x);
		double z = pochodna_funkcji(x);



		if (y == 0){
			printf("dla x = %f, funkcja f(x) = sin(x) - 1/2x = 0. To jest oczywiscie wartosc przyblizona, z dokladnoscia do kilkunastu miejsc po przecinku.", x);
			return 0;
		}

		x = x - y / z; // jeden kierunek, kontrolowany krok

		printf("Iteracja %d: x = %f, y = %f\n", i++, x, y);

		//if (i > 1000) {
		//	printf("Za dużo iteracji – brak zbieżności\n");
		//	break;
		//}
	}

	return 0;
}


double funkcja(double k) {
	return sin(k) - (0.5 * k);
}

double pochodna_funkcji(double k) {
	return cos(k) - 0.5;
}



*/






// ==============================(zadanie10)=====================================*/





/*


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#pragma warning(disable:4996)

#define MAX_CALCULATIONS 100


typedef struct CO {
	double re;
	double im;
} COMPLEX;

typedef struct {
	COMPLEX x1;
	COMPLEX x2;
} ROOTS;

typedef struct quadr_func {
	double a;
	double b;
	double c;
	double delta;
	double t1;
	double t2;

} func;

typedef struct {
	double a, b, c;
	double delta;
	int isComplex;
	double x1, x2;           // dla rzeczywistych
	COMPLEX z1, z2;          // dla zespolonych
} Calc_res;


COMPLEX add(COMPLEX z1, COMPLEX z2) {
	COMPLEX result;

	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return result;
}

ROOTS solve(func f, Calc_res* res);


func delta(func f, Calc_res* res) {
	func result;
	double delta = f.b * f.b - 4 * f.a * f.c;

	res->a = f.a;       // tablica
	res->b = f.b;       // tablica
	res->c = f.c;       // tablica
	res->delta = delta; // tablica

	if (delta == 0) {
		printf("One solution.\n");
		result.t1 = -f.b / (2 * f.a);
		printf("t1 = %f\n", result.t1);
		res->x1 = result.t1;  // tablica
		res->x2 = result.t1;  // tablica
		res->isComplex = 0;   // tablica
		res->z1.re = 0; // tablica
		res->z2.re = 0; // tablica
		res->z1.im = 0; // tablica
		res->z2.im = 0; // tablica
		return result;
	}
	if (delta > 0) {
		printf("Two real solutions.\n");
		result.t1 = (-f.b - sqrt(delta)) / (2 * f.a);
		result.t2 = (-f.b + sqrt(delta)) / (2 * f.a);
		printf("t1 = %f, t2 = %f\n", result.t1, result.t2);
		res->x1 = result.t1;  // tablica
		res->x2 = result.t2;  // tablica
		res->isComplex = 0;   // tablica
		res->z1.re = 0; // tablica
		res->z2.re = 0; // tablica
		res->z1.im = 0; // tablica
		res->z2.im = 0; // tablica
		return result;
	}
	if (delta < 0) {
		printf("Two complex solutions.\n");
		solve(f, res);  // tablica
		res->isComplex = 1;
		res->x1 = 0;    // tablica
		res->x2 = 0;    // tablica
		return result;
	}

	return result;  // zabezpieczenie
}



ROOTS solve(func f, Calc_res* res) {
	ROOTS roots;
	double delta = f.b * f.b - 4 * f.a * f.c;
	roots.x1.re = roots.x2.re = -f.b / (2 * f.a);
	roots.x1.im = -sqrt(-delta) / (2 * f.a);
	roots.x2.im = +sqrt(-delta) / (2 * f.a);

	res->z1.re = roots.x1.re; // tablica
	res->z2.re = roots.x2.re; // tablica
	res->z1.im = roots.x1.im; // tablica
	res->z2.im = roots.x2.im; // tablica

	printf("Pierwsza liczba: %.4f + %.4fi\n", roots.x1.re, roots.x1.im);
	printf("Druga liczba: %.4f + %.4fi\n", roots.x2.re, roots.x2.im);

	return roots;
}



int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);


	COMPLEX liczba1, liczba2;
	COMPLEX liczba3;
	func funkcja1;

	Calc_res results[MAX_CALCULATIONS];
	int i = 0;



	liczba1.re = 5;
	liczba1.im = 1;

	liczba2.re = 9;
	liczba2.im = 2;

	liczba3 = add(liczba1, liczba2);
	printf("\nczesc rzeczywista sumy liczby1 i liczby2 = %.f\n", liczba3.re);
	printf("czesc urojona sumy liczby1 i liczby2 = %.fi\n", liczba3.im);



	//obliczenia funkcji 

	while (1) {
		if (i >= MAX_CALCULATIONS) {
			printf("Osiągnięto maksymalną liczbę obliczeń.\n");
			break;
		}

		printf("\nDla funkcji f(x) = ax^2 + bx + c, podaj wartosci a, b, c:\n");
		if (scanf("%lf %lf %lf", &funkcja1.a, &funkcja1.b, &funkcja1.c) != 3) {
			printf("Błąd wczytywania danych.\n");
			continue;
		}

		delta(funkcja1, &results[i]);
		i++;

		char wybor;
		printf("Kontynuować? (t/n): ");
		scanf(" %c", &wybor);
		if (wybor != 't' && wybor != 'T') {
			printf("+--------+--------+--------+----------+------------+--------+--------+------------------+------------------+\n");
			printf("|   a    |   b    |   c    |  delta   | is complex |   x1   |   x2   |      im1         |      im2         |\n");
			printf("+--------+--------+--------+----------+------------+--------+--------+------------------+------------------+\n");

			for (int k = 0; k < i; k++) {
				printf("| %6.2f | %6.2f | %6.2f | %8.2f |    %6.2f  | %6.2f |  %6.2f|%8.2f + %6.2fi|%8.2f + %6.2fi|\n",
					results[k].a, results[k].b, results[k].c, results[k].delta, results[k].isComplex,
					results[k].x1, results[k].x2,
					results[k].z1.re, results[k].z1.im,
					results[k].z2.re, results[k].z2.im);
				printf("+--------+--------+--------+----------+------------+--------+--------+------------------+------------------+\n");
			}

			return 0;
		}

	}
	return 0;
}



*/






// ==============================(zadanie (lista jednokiernowa)=====================================*/

/*

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#pragma warning(disable:4996)

typedef struct list {

	int data;
	struct list* next ;
} list;

list* addToFront(list* head, int value) {
	list* node = (list*)malloc(sizeof(list));
	node->data = value;
	node->next = head;
	return node;
}

void printlist(list* head) {
	while (head) {
		printf("%d -> ", head->data);
		head = head->next;
	}
}



int main() {
	list* head = NULL;  // Lista początkowo pusta

	head = addToFront(head, 10);  // 10
	head = addToFront(head, 20);  // 20 -> 10
	head = addToFront(head, 30);  // 30 -> 20 -> 10
	head = addToFront(head, 40);


	printlist(head);  // wypisze: 30 -> 20 -> 10 -> NULL

	return 0;


}


*/

// ==============================(zadanie (lista dwukierunkowa)=====================================*/

/*


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
	int data;                // wartość
	struct Node* prev;       // wskaźnik na poprzedni węzeł
	struct Node* next;       // wskaźnik na następny węzeł
} Node;

Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

Node addToFront() {
	list* node = (list*)malloc(sizeof(list));
	node->data = value;
	node->next = head;
	return node;
}


Node printListForward() {

}

int main() {

	return 0;
}

*/



//================================(lesson13)===========================//



#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS


int i = 0;

typedef struct list {
	char name[50];
	char forname[50];
	int birth_year;
	char adress[50];
	double scholarship_amount;

	struct list* prev;
	struct list* next;
} list;



void add_student() {
	i++;
}
void remove_student() {
	i--;
}



list* addToEnd(list* head, char name[50], char forname[50], int birth_year, char adress[50], double scholarship_amount) {
	list* node = (list*)malloc(sizeof(list));
	add_student();

	strcpy(node->name, name);
	strcpy(node->forname, forname);
	node->birth_year = birth_year;
	strcpy(node->adress, adress);
	node->scholarship_amount = scholarship_amount;
	node->next = NULL;
	node->prev = NULL;

	if (head == NULL)
		return node;

	list* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = node;
	node->prev = temp;
	return head;
}



list* addToFront(list* head, char value1[50], char value2[50], int value3, char value4[50], double value5) {
	list* node = (list*)malloc(sizeof(list));
	add_student();

	strcpy(node->name, value1);
	strcpy(node->forname, value2);
	node->birth_year = value3;
	strcpy(node->adress, value4);
	node->scholarship_amount = value5;

	node->next = head;
	node->prev = NULL;
	if (head != NULL)
		head->prev = node;
	return node;
}



list* remFromEnd(list* head){
	list* node = head;
	if (head == NULL) {
		return NULL;
	}

	list* temp = head;

	// Traverse to the last node
	while (temp->next != NULL) {
		temp = temp->next;
	}

	// If the last node has a previous node
	if (temp->prev != NULL) {
		temp->prev->next = NULL;
	}
	else {
		// The list had only one node, now empty
		head = NULL;
	}


	free(temp);
	remove_student();
	return head;
}
 


list* remFromFront(list* head) {
	list* node = head;
	if (head == NULL) {
		return NULL;
	}

	list* temp = head;

	head = head->next;
	if (head != NULL) {
		head->prev = NULL;
	}

	free(temp);
	remove_student();
	return head;
}


void printlist(list* head) {
	while (head != NULL) {
		printf("%s %s %d %s %.2lf\n", head->name, head->forname, head->birth_year, head->adress, head->scholarship_amount);
		head = head->next;
	}
}



void highest_stypendium(list* head) {
	list* maxNode = NULL;
	double buffer = 0;
	while (head != NULL) {
		if (head->scholarship_amount > buffer) {
			maxNode = head;
			buffer = head->scholarship_amount;
		}
		head = head->next;
	}
	printf("\n\n Highest stypendium (%.2lf) have: %s %s\n\n", maxNode->scholarship_amount, maxNode->name, maxNode->forname);
	return;
}


void freeList(list * head) {
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
	bool new_student;

	list* head = NULL;

	FILE* plik = fopen("studenci.txt", "r+");
	if (plik == NULL) {
		printf("txt file not found.\n");
	}
	else {
		while (fscanf(plik, "%49s %49s %d %49s %lf", word1, word2, &word3, word4, &word5) == 5) {
			head = addToFront(head, word1, word2, word3, word4, word5);
		}
		fclose(plik);
	}

	char odpowiedz;
	do {
		printf("New student? y/n: ");
		scanf(" %c", &odpowiedz);

		if (odpowiedz == 'y' || odpowiedz == 'Y') {
			new_student = true;

			printf("Enter your name: ");
			scanf("%s", word1);
			printf("Enter your forname: ");
			scanf("%s", word2);
			printf("enter your birth year: ");
			scanf("%d", &word3);
			printf("enter your adress: ");
			scanf("%s", word4);
			printf("enter your stypendium: ");
			scanf("%lf", &word5);

			char x;
			printf("Add to the front (f), or end (e)? ");
			scanf(" %c", &x);

			if (x == 'f') {
				head = addToFront(head, word1, word2, word3, word4, word5);
			}
			else if (x == 'e') {
				head = addToEnd(head, word1, word2, word3, word4, word5);
			}
			else {
				printf("Unknown option.\n");
			}
		}
		else if (odpowiedz == 'n' || odpowiedz == 'N') {
			new_student = false;
		}
		else {
			printf("Unknown option.\n");
		}
	} while (new_student == true);


	//removing object.
	char answer2;
	char answer3;
	printf("you want to remove something? y/n.");
	scanf(" %c", &answer2);
	if (answer2 == 'y') {
		printf("First object (f), or last object (l) ?");
		scanf(" %c", &answer3);
		if (answer3 == 'f') {
			head = remFromFront(head);
		}
		if (answer3 == 'l') {
			head = remFromEnd(head);
		}
		else {
			printf("Unknown option.\n");
		}
	}



	printlist(head);
	
	highest_stypendium(head);
	printf("\nNumber of students = %d\n\n", i);

	freeList(head);
	return 0;
}





//========================//\\ -----++===[{==(lessonXX)==}]===++---- //\\==========================//



/*

#define _CRT_SECURE_NO_WARNINGS


#include <string.h> 
#include <stdio.h>
#include <stdlib.h>




struct node {
	int value;
	char name[50];
	struct node* next;
};

node* addToFront(node* head, int value, const char* name) {
	node* newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}
	newnode->value = value;
	strncpy(newnode->name, name, sizeof(newnode->name) - 1);
	newnode->name[sizeof(newnode->name) - 1] = '\0';  // ensure null-terminated
	newnode->next = head;
	return newnode;
}

int main() {
	node* head = NULL;

	int k = 5;

	head = addToFront(head, 10, "Alice");
	head = addToFront(head, 20, "Bob");
	head = addToFront(head, 30, "Charlie");

	// Print list
	node* current = head;
	while (current != NULL) {
		printf("%d %s-> ", current->value,current->name);
		current = current->next;
	}
	printf("NULL\n");

	return 0;
}



*/


//========================//\\ -----++==[{==(lesson15)==}]===++---- //\\==========================//

/*

#define _CRT_SECURE_NO_WARNINGS


#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
	__int8 a;
	__int8 b;
} MyStruct;

typedef union {
	MyStruct s;
	__int16 val;
} MyUnion;

int main() {
	MyUnion u;
	u.s.a = 0x12; // 18
	u.s.b = 0x34; // 52

	printf("u.s.a = %x\n", u.s.a & 0xFF);
	printf("u.s.b = %x\n", u.s.b & 0xFF);
	printf("u.val = %x\n", u.val & 0xFFFF);

	return 0;
}

*/