//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <errno.h>
//#include <time.h>
//#include <ctype.h>
//
//
//
//typedef struct osoba Osoba;
//typedef struct osoba* pozicija;
//
//struct osoba
//{
//	char ime[50];
//	char prezime[50];
//	int rodgodina;
//	pozicija next;
//
//};
//
//
//void unosPocetak(pozicija);
//void unosKraj(pozicija);
//void ispis(pozicija);
//void trazi(pozicija);
//
//
//void brisi(pozicija p)
//{
//	getchar();
//	char imebrisi[50] = "\0";
//
//	printf("Unesite ime koje zelite izbrisati: ");
//	fgets(imebrisi, 50, stdin);
//
//	while(p->next)
//}
//
//
//int main()
//{
//	Osoba head;
//	head.next = NULL;
//
//	unosPocetak(&head);
//	unosKraj(&head);
//
//	ispis(head.next);
//
//	return 0;
//}
//
//
//
//void unosPocetak(pozicija p)
//{
//	pozicija q;
//	q = (pozicija)malloc(sizeof(Osoba));
//
//	printf("Unesite ime osobe: ");
//	fgets(q->ime, 50, stdin);
//
//	printf("Unesite prezime osobe: ");
//	fgets(q->prezime, 50, stdin);
//
//	printf("Unesite godinu rodjenja: ");
//	scanf("%d", &(q->rodgodina));
//
//	q->next = p->next;
//	p->next = q;
//}
//
//void unosKraj(pozicija p)
//{
//	pozicija q = (pozicija)malloc(sizeof(Osoba));
//
//	while (p->next != NULL)
//	{
//		p = p->next;
//	}
//
//	printf("Unesite ime osobe: ");
//	fgets(q->ime, 50, stdin);
//
//	printf("Unesite prezime osobe: ");
//	fgets(q->prezime, 50, stdin);
//
//	printf("Unesite godinu rodjenja: ");
//	scanf("%d", &(q->rodgodina));
//
//	q->next = p->next;
//	p->next = q;
//}
//
//void ispis(pozicija p)
//{
//	while (p != NULL)
//	{
//		printf("%s %s %d", p->ime, p->prezime, p->rodgodina);
//		p = p->next;
//	}
//}
//
//void trazi(pozicija p)
//{
//	char trazen[50] = "\0";
//
//	getchar();
//	printf("Unesite prezime koje trazite: ");
//	fgets(trazen, 50, stdin);
//
//	while (p != NULL && strcmp(p->prezime, trazen) != 0)
//	{
//		p = p->next;
//	}
//
//	printf("Osoba je: %s %s,\n a trazeno prezime je %s", p->prezime, p->ime, trazen);
//
//}