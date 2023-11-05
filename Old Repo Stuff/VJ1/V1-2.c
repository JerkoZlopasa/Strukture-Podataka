#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <math.h>



typedef struct Osoba* poz;

typedef struct
{
	char ime[50];
	char prezime[50];
	int god;
	poz pos;
	
} Osoba;



typedef struct
{
	char crit1[50];
	char crit2[50];
	char crit3[50];
	poz pos;

} Head;



void HeadInit(Head* header)
{
	FILE* fp = fopen("PersonsAmogus.txt", "r");

	fscanf(fp, "%s %s %s", header->crit1, header->crit2, header->crit3);

	header->pos = NULL;
}



void Connect(Osoba* C1, Osoba* C2)
{

}



int main()
{
	Head headi;

	HeadInit(&headi);

	printf("%s %s %s", headi.crit1, headi.crit2, headi.crit3);



	return 0;
}