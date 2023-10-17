#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <math.h>



typedef struct Osoba* position;

struct Osoba {
	int x;
	position next;

};




void HeadInit(position Head,int x)
{
	FILE* fp = fopen("PersonsAmogus.txt", "r");
	fscanf(fp, " %d", (*(Head)).x);
	(*(Head)).next = NULL;
	fclose(fp);
}
// Šalje se adresa od Head, ne treba se slati druga osoba jer æe Head nakon zavrsetka funkcije
// sadržavati adresu(next) od lokalne noveOsoba(manje posla),svakim pozivom ce se koristit ista
// lokalna position(pointer na strukturu)  novaOsoba
void povezi(position Head) {
	position novaOsoba = NULL;
	(*(novaOsoba)).next = (*(Head)).next;
	(*(Head)).next = novaOsoba;

}
int main()
{
	struct Osoba Head;
	//(J) Šalje se adresa od Head jer ne možes slati neinicijaliziranu strukturu Head
	// odnosno varijable strukture su neincijalizirane(nemaju pridanu vrijednost) pa je to
	//samo tip(struktura), slièno da si napisa da šalješ struct osoba
	HeadInit(&Head,5);
	povezi(&Head);

	return 0;
}