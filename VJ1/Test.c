#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>



typedef struct studi Studi;
typedef Studi* pos;



struct studi
{
	char headi[50];
	char ime[10];
	char prezime[10];
	int god;
	pos nextu;
};



Studi* describe(Studi* head)
{
	printf("Unesite sto se nalazi u vezanoj listi: ");
	fgets(head->headi, 50, stdin);
	printf("\n");
	head->nextu = NULL;

	return head;
}



pos create(pos stud)
{
	stud = (Studi*)malloc(sizeof(Studi));

	printf("Unesite ime studenta: ");
	fgets(stud->ime, 10, stdin);

	printf("Unesite prezime studenta: ");
	fgets(stud->prezime, 10, stdin);

	printf("Unesite godine studenta: ");
	scanf("%d", &stud->god);
	getchar();

	stud->nextu = NULL;

	return stud;
}



void connect(pos pos1, pos pos2)
{
	printf("\n\nHead %p\tStud to be %p", pos1, pos2);

	printf("\n\nHead files: %s %p", pos1->headi, pos1->nextu);
	printf("\n\nStud files: %s %s %d", pos2->ime, pos2->prezime, pos2->god);

	pos1->nextu = pos2;

	printf("\nStud files provjera: %s %s %d", pos1->nextu->ime, pos1->nextu->prezime, pos1->nextu->god);
}



void connecti(pos pos1, pos pos2)
{
	printf("\n\nCurrent %p\tStud to be %p\n", pos1->nextu, pos2);

	printf("\n\nStud1 files: %p", pos1->nextu->nextu);
	printf("\n\nStud2 files: %s %s %d", pos2->ime, pos2->prezime, pos2->god);

	pos1->nextu->nextu = pos2;

	printf("\n\nStud1 files provjera: %s %s %d", pos1->nextu->ime, pos1->nextu->prezime, pos1->nextu->god);
	printf("\n\nStud2 files provjera: %s %s %d", pos1->nextu->nextu->ime, pos1->nextu->nextu->prezime, pos1->nextu->nextu->god);
}



int main()
{
	Studi* head = (Studi*)malloc(sizeof(Studi));
	Studi* stud = NULL;

	head = describe(head);
	connect(head, create(stud));

	printf("\n\nHead Next: %p\tStud: %p\n\n\n", head->nextu, stud);
	
	connecti(head, create(stud));
	printf("\n\nHead Next: %p\tStud Next: %p\t Stud: %p", head->nextu, head->nextu->nextu, stud);
	printf("\n\nStud1: %s %s %d \n\nStud 2: %s %s %d\n", head->nextu->ime, head->nextu->prezime, head->nextu->god, head->nextu->nextu->ime, head->nextu->nextu->prezime, head->nextu->nextu->god);

	return 0;
}