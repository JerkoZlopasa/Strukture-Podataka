//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <math.h>
//#include <errno.h>
//#include <time.h>
//
//
//
//typedef struct poli Poli;
//typedef Poli* pos;
//
//struct poli
//{
//	char desc[50];
//	char unknown;
//	int koef;
//	int pot;
//	pos next;
//};
//
//
//int main()
//{
//	pos Head = (pos)malloc(sizeof(Poli));
//	pos ListPoli = (pos)malloc(3 * sizeof(Poli));
//	pos Entry = (pos)malloc(sizeof(Poli));
//
//	char buffer[50];
//	pos current = &ListPoli[0];
//	FILE* File = fopen("Polinomi.txt", "r");
//
//	int i = -1;
//	current->next = NULL;
//
//
//	while (!feof(File))
//	{
//		fgets(Entry->desc, 50, File);
//
//		Entry->next = NULL;
//
//		current->next = Entry;
//
//		current = current->next;
//		
//		printf("%s", current->desc);
//	}
//
//
//	current = ListPoli;
//
//	printf("Current: %s", current->next->desc);  
//
//	return 0;
//}
