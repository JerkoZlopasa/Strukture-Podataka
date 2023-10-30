#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <time.h>


//Defining Structure Polinome
typedef struct poli* pos;
typedef struct poli
{
	char desc[50];
	int koef;
	int pot;
	pos next;
} poli;


//Defining necessary functions
void SortInput(pos);
void SumPoli(void);
void MultPoli(void);


int main()
{
	poli head;
	head.next = NULL;

	SortInput(&head);

	return 0;
}


void SortInput(pos Header)
{
	//Declaring necessary variables
	pos current;
	FILE* File = fopen("Polinomi.txt", "r");
	(File == NULL) ? printf("File not opened!") : 1;

	//Skipping first, header, line
	while (fgetc(File) != '\n');

	
}
