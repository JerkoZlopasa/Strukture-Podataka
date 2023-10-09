#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <math.h>



typedef struct Student
{
	char ime[50];
	char prezime[50];
	int bod;

} Studi;



int main()
{
	char temp[1024] = "";
	int broj = 0;
	FILE* fp = NULL;

	fp = fopen("StudentsAmogus.txt", "r");

	if (fp == NULL)
	{
		printf("Nema datoteke!");
		return 1;
	}

	while (!feof(fp))
	{
		if (fgets(temp, 1024, fp))
			broj++;
	}

	return 0;
}