#define _CRT_SECURE_NO_WARNINGS
#define UNOS_EXIT 1
#include <stdio.h>
#include <stdlib.h>
//pozdrav antoni

typedef struct _osoba* pozicija;
typedef struct _osoba {
	char ime[50];
	char prezime[50];
	int godRod;
	pozicija next;
}osoba;



void MENU(pozicija p);
int unosNaPocetak(pozicija headAdresa);
int ispisListe(pozicija headNext);
int unosNaKrajListe(pozicija headAdresa);
int trazi(pozicija headNext);
int brisi(pozicija headAdresa);
int dodajIzaElementa(pozicija headAdresa);
int unosPrijeElementa(pozicija headAdresa);
int unosUdatoteku(pozicija headNext);
int citajIzDatoteke(void);

int main(void) {
	osoba head;
	head.next = NULL;

	MENU(&head);
	return EXIT_SUCCESS;
}

void MENU(pozicija headAdresa) {
	char odabir = { 0 };
	while (odabir != 'x') {

		printf("Odaberite x za izlazak iz programa.\n");
		printf("Odaberite a za unosNaPocetak.\n");
		printf("Odaberite i za ispisListe.\n");
		printf("Odaberite k za unosNaKrajListe.\n");
		printf("Odaberite t za trazenje osobe.\n");
		printf("Odaberite b za brisanje osobe.\n");
		printf("Odaberite f za unos iza elementa.\n");
		printf("Odaberite p za unos prije elementa.\n");
		printf("Odaberite d za unos u datoteku.\n");
		printf("Odaberite c za citanje iz datoteke.\n");

		scanf(" %c", &odabir);
		switch (odabir) {
		case 'X':
		case'x':
			printf("Kraj programa\n");
			break;
		case 'A':
		case 'a':
			unosNaPocetak(headAdresa);
			printf("Unos uspijesan!\n");
			break;
		case 'I':
		case'i':
			printf("Ispis liste:\n");
			ispisListe(headAdresa->next);
			break;
		case 'K':
		case'k':
			printf("Unos na kraj liste:\n");
			unosNaKrajListe(headAdresa);
			break;
		case 'T':
		case 't':
			printf("Trazenje osobe:\n");
			trazi(headAdresa->next);
			break;
		case 'B':
		case 'b':
			printf("Brisanje osobe:\n");
			brisi(headAdresa);
			break;

		case 'F':
		case 'f':
			printf("Dodavanje iza elementa:\n");
			dodajIzaElementa(headAdresa);
			break;
		case 'P':
		case 'p':
			printf("Unos prije elementa:\n");
			unosPrijeElementa(headAdresa);
			break;
		case 'D':
		case 'd':
			printf("Unos u datoteku:\n");
			unosUdatoteku(headAdresa->next);
			break;
		case 'C':
		case 'c':
			printf("Citanje iz dat:\n");
			citajIzDatoteke();
			break;
		}

	}
}

int unosNaPocetak(pozicija headAdresa) {
	pozicija novaOsoba = (pozicija)malloc(sizeof(osoba));
	//provjeru dodat
	printf("Unesite ime, prezime i godinu rodjenja:\n");
	scanf(" %s %s %d", novaOsoba->ime, novaOsoba->prezime, &(novaOsoba->godRod));
	novaOsoba->next = headAdresa->next;
	headAdresa->next = novaOsoba;

	return 1;
}

int ispisListe(pozicija current) {
	printf("Ime\tPrezime\tgodRod:\n");
	while (current != NULL) {
		printf("%s\t%s\t%d\n", current->ime, current->prezime, current->godRod);
		current = current->next;
	}
	return 2;
}

int unosNaKrajListe(pozicija current) {
	pozicija novaOsoba = (pozicija)malloc(sizeof(osoba));
	while (current->next != NULL) {
		current = current->next;
	}
	printf("Unesite ime, prezime i godinu rodjenja:\n");
	scanf(" %s %s %d", novaOsoba->ime, novaOsoba->prezime, &(novaOsoba->godRod));
	novaOsoba->next = current->next;
	current->next = novaOsoba;
	return 3;
}

int trazi(pozicija current) {

	char traziPrezime[50] = { 0 };
	printf("\nPrezime osobe koju trazite:\n");
	scanf(" %s", traziPrezime);
	while ((current != NULL &&  strcmp(current->prezime, traziPrezime)) != 0) {
		current = current->next;
	}
	if (current != NULL) {
		printf("Trazena osoba je: %s %s\n",current->ime,current->prezime);
	}
	else printf("Osoba nije pronadjena!\n");
	return 4;
}

int brisi(pozicija current) {
	pozicija temp = (pozicija)malloc(sizeof(osoba));
	char brisiPrezime[50] = { 0 };
	printf("Unesite prezime osobe koju zelite izbrisati:\n");
	scanf(" %s", brisiPrezime);
	while (current->next != NULL && strcmp(current->next->prezime, brisiPrezime) != 0) {
		current = current->next;
	}
	if (current->next != NULL) {
		temp = current->next;
		current->next = temp->next;
		free(temp);
	}
	else printf("Osoba nije pronadjena!\n");
	return 5;
}

int dodajIzaElementa(pozicija current) {

	pozicija novaOsoba = (pozicija)malloc(sizeof(osoba));
	pozicija temp = (pozicija)malloc(sizeof(osoba));
	char izaPrezimena[50] = { 0 };
	printf("Prezime osobe iza koje zelite unijeti novu osobu:\n");
	scanf(" %s", izaPrezimena);
	while (current != NULL && strcmp(current->prezime,izaPrezimena) != 0 ) {
		current = current->next;
	}
	if (current != NULL) {
		printf("Unesite ime prezime i godRod:\n");
		scanf(" %s %s %d", novaOsoba->ime, novaOsoba->prezime, &(novaOsoba->godRod));
		novaOsoba->next = current->next;
		current->next = novaOsoba;
	}
	else printf("Osoba nije pronadjena!\n");
	return 6;
}

int unosPrijeElementa(pozicija current) {
	pozicija novaOsoba = (pozicija)malloc(sizeof(osoba));
	char prijePrezimena[50] = { 0 };
	printf("Unesite prezime osobe ispred koje zelite unijeti element:\n");
	scanf(" %s", prijePrezimena);
	while (current->next != NULL && strcmp(current->next->prezime, prijePrezimena) != 0) {
		current = current->next;
	}
	if (current->next != NULL) {
		printf("Unesite ime prezime i godRod Noveosobe:\n");
		scanf(" %s %s %d", novaOsoba->ime, novaOsoba->prezime, &(novaOsoba->godRod));
		novaOsoba->next = current->next;
		current->next = novaOsoba;
	}
	else printf("Prazna lista!\n");
	return 7;
}

int unosUdatoteku(pozicija current) {
	FILE* file = fopen("struktura.txt", "w");
	fprintf(file,"IME\tPrezime\tGODROD:\n");
	while (current != NULL) {
		fprintf(file,"%s\t%s\t%d", current->ime, current->prezime, current->godRod);
		current = current->next;
	}
	fclose(file);
	return 8;
}

int citajIzDatoteke(void) {
	pozicija temp = (pozicija)malloc(sizeof(osoba));
	FILE* file = fopen("struktura.txt", "r");

	while (fgetc(file) != '\n');
	printf("Ime\tPrezime\tGodRod:\n");
	while (!feof(file)) {
		if (fscanf(file, " %s %s %d", temp->ime, temp->prezime, &(temp->godRod))==3){
			printf("%s\t%s\t%d\n", temp->ime, temp->prezime, temp->godRod);
		}
		else printf("Prazna datoteka!\n");
	}
	free(temp);
	fclose(file);
	return 9;
}