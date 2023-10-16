#define _CRT_SECURE_NO_WARNINGS
#define MAXLIN 1024
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



int BrojiRetke(int a, char* buffer)
{
	FILE* fp = NULL;


	//Otvaranje datoteke i provjera otvaranja
	fp = fopen("StudentsAmogus.txt", "r");

	if (fp == NULL)
	{
		printf("Nema datoteke!");
		return 1;
	}


	//Preskakanje header retka i brojanje entryja
	while (fgetc(fp) != '\n');

	while (!feof(fp))
	{
		if (fgets(buffer, 1024, fp))
			a++;
	}

	fclose(fp);

	return a;
}



Studi* Alociraj(Studi* pointstud, int broj)
{
	//Alokacija prostora i provjera pointera
	pointstud = (Studi*)malloc(broj * sizeof(Studi));

	if (pointstud == NULL)
	{
		printf("Neuspjela alokacija!");
		return 1;
	}

	return pointstud;
}



int Pridaj(Studi* studarr, int najbod)
{
	int i = 0;
	FILE* fp = NULL;


	//Otvaranje datoteke i provjera otvaranja
	fp = fopen("StudentsAmogus.txt", "r");

	if (fp == NULL)
	{
		printf("Nema datoteke!");
		return 1;
	}


	//Preskakanje header retka i append u listu s provjerun maks bodova pa zatvaranje
	while (fgetc(fp) != '\n');

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d", (studarr + i)->ime, (studarr + i)->prezime, &studarr[i].bod);

		(studarr[i].bod > najbod) ? najbod = studarr[i].bod : 1;
		i++;
	}

	fclose(fp);

	return najbod;
}



void Ispis(Studi* studarr, int br, int najbod)
{
	int i = 0;
	//Ispis svega sto je potrebno
	printf("IME\tPREZIME\tBODOVI\tREL.BOD");
	for (i = 0; i < br; i++)
		printf("\n%s\t%s\t%d\t%f", studarr[i].ime, studarr[i].prezime, studarr[i].bod, (float)studarr[i].bod / (float)najbod * 100);

	printf("\n");

}



int main()
{
	//Deklariranje Varijabli, temp je tun za brojanje redaka
	char temp[MAXLIN] = "";
	int broj = 0, najbod = 0;
	Studi* studarr = NULL;

	//Brojanje studenata u fileu, vraca broj
	broj = BrojiRetke(broj, temp);
	
	//Alociranje prostora za listu studenata, vraca tu listu
	studarr = Alociraj(studarr, broj);
	
	//Funkcija citanja i dodavanja u listu studenata, dodatno racuna najbolji broj bodova
	najbod = Pridaj(studarr, najbod);

	//Funkcija ispisa
	Ispis(studarr, broj, najbod);


	
	return 0;
}