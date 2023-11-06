////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <stdlib.h>
////#include <ctype.h>
////#include <string.h>
////#include <math.h>
////#include <errno.h>
////#include <time.h>
////
////
//////Defining Structure Polinome
////typedef struct poli* pos;
////typedef struct poli
////{
////	char desc[50];
////	int koef;
////	int pot;
////	pos next;
////} poli;
////
////
//////Defining necessary functions
////void SortInput(pos);
////void SumPoli(void);
////void MultPoli(void);
////
////
////int main()
////{
////	poli head;
////	head.next = NULL;
////
////	SortInput(&head);
////
////	return 0;
////}
////
////
////void SortInput(pos Header)
////{
////	//Declaring necessary variables
////	pos current;
////	FILE* File = fopen("Polinomi.txt", "r");
////	(File == NULL) ? printf("File not opened!") : 1;
////
////	//Skipping first, header, line
////	while (fgetc(File) != '\n');
////
////	
////}
//=======
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//struct _polinom;
//typedef struct _polinom* position;
//typedef struct _polinom {
//	int coef;
//	int exp;
//	position next;
//}polinom;
//
//
//int fromFilePolinom(char* filename, position head1, position head2);
//int parseStringToElements(char* buffer, position head);
//position createEl(int coef, int exp);
//int insertSorted(position newEl, position head);
//void printPolinom(position headnext);
//
//int main(void) {
//	polinom head1 = { .coef = 0, .exp = 0, .next = NULL };
//	polinom head2 = { .coef = 0, .exp = 0, .next = NULL };
//	char* filename = "polinomi.txt";
//
//	if (fromFilePolinom(filename, &head1, &head2) == EXIT_SUCCESS) {
//		printPolinom(head1.next);
//		printPolinom(head2.next);
//
//
//	}
//
//
//	return EXIT_SUCCESS;
//}
//
//int fromFilePolinom(char* filename, position head1, position head2) {
//	FILE* dat = fopen(filename, "r");
//	if (!dat) {
//		printf("FILE error~\n");
//		return 100;
//	}
//	char buffer1[1024] = { 0 };
//	char buffer2[1024] = { 0 };
//
//	fgets(buffer1, 1024, dat);
//	parseStringToElements(buffer1, head1);
//	fgets(buffer2, 1024, dat);
//	parseStringToElements(buffer2, head2);
//
//	;
//
//
//	return EXIT_SUCCESS;
//}
//
//int parseStringToElements(char* buffer, position head) {
//	char* thisbuffer = buffer;
//	int coef = 0, exp = 0, num = 0;
//	position newEl = NULL;
//	while (strlen(thisbuffer) > 0) {
//		int status = sscanf(thisbuffer, " %dx^%d %n", &coef, &exp, &num);
//		newEl = createEl(coef, exp);
//		insertSorted(newEl, head);
//
//		thisbuffer += num;
//	}
//
//
//	return EXIT_SUCCESS;
//}
//
//position createEl(int coef, int exp) {
//	position newEl = (position)malloc(sizeof(polinom));
//	if (!newEl) {
//		printf("ALOK ERROR~\n");
//		return NULL;
//	}
//	newEl->coef = coef;
//	newEl->exp = exp;
//	newEl->next = NULL;
//
//	return newEl;
//}
//int insertSorted(position newEl, position head) {
//	position current = head;
//
//	while (current->next != NULL && current->next->exp > newEl->exp) {
//		current = current->next;
//	}
//	if (current->next != NULL && current->next->exp == newEl->exp) {
//		int tempCoef = current->next->coef + newEl->coef;
//		current->next->coef = tempCoef;
//		free(newEl);
//
//	}
//	else {
//		newEl->next = current->next;
//		current->next = newEl;
//	}
//
//
//	return EXIT_SUCCESS;
//}
//
//void printPolinom(position headnext) {
//	position current = headnext;
//	while (current != NULL) {
//		printf("%dx^%d ", current->coef, current->exp);
//		current = current->next;
//	}
//	printf("\n");
//}
//
//>>>>>>> 6ddb049a18c7df7a5af3c8ac8cf47b791cc2e19d
