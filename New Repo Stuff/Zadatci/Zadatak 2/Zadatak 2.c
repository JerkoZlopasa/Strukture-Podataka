#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <time.h>



//Declaring structure name and position argument for structure 'Person'
typedef struct person Person;
typedef Person* pos;


//Defining the structure itself
struct person
{
	char desc[50];
	char name[50];
	char surname[50];
	int yobirth;
	pos next;
};


//Defining functions for list
void Setup(pos);
void AddEnd(pos);
void AddBegin(pos);
void SurSearch(pos);
int StringCompare(char[50], char[50]);
void PrintList(pos);
void Erase(pos);

int main()
{
	Person Header;
	Setup(&Header);

	AddEnd(&Header);
	PrintList(&Header);

	AddBegin(&Header);
	PrintList(&Header);

	AddEnd(&Header);
	PrintList(&Header);

	SurSearch(&Header);

	Erase(&Header);
	PrintList(&Header);

	return 0;
}


//Sets up the header's description and link to next entry 
void Setup(pos Head)
{
	//Setting the pointer of the header to null for first pass
	Head->next = NULL;

	//Setting a description for the header, so the list is user friendly
	printf("What is in the file? ");
	fgets(Head->desc, sizeof(Head->desc), stdin);
}


//Adds entry to end of the list
void AddEnd(pos Head)
{
	//Declaring a temporary variable and a new entry
	pos current = Head;
	pos new = (pos)malloc(sizeof(Person));

	//Initializing the new entry
	printf("\nType the name, surname and y.o.b, separated by a space: ");
	fscanf(stdin, "%s %s %d", new->name, new->surname, &new->yobirth);

	//Cycling to the end of the list
	while (current->next != NULL)
		current = current->next;

	//Linking the new entry to the end of the list
	current->next = new;
	new->next = NULL;

	
}


//Adds entry to the beginning of the list
void AddBegin(pos Head)
{
	//Declaring a temporary variable and creating an inject entry
	pos after = Head->next;
	pos inject = (pos)malloc(sizeof(Person));
	
	//Initializing the entry
	printf("\nType the name, surname and y.o.b, separated by a space: ");
	fscanf(stdin, "%s %s %d", inject->name, inject->surname, &inject->yobirth);

	//Sorting out the new entry's links to the next one and the header
	inject->next = after;
	Head->next = inject;
}


//Helper function for comparing strings
int StringCompare(char searched[50], char compared[50])
{
	int count = 0;
	int i = 0;
	
	//The limit here is intentional because the normal strlen counts the '\0', this doesn't
	for (i = 0; i < strlen(searched)-1; i++)
		(searched[i] == compared[i]) ? count++ : 1;

	return count;
}


//Find entry by surname search
void SurSearch(pos Head)
{
	//Declaring some temporary variables necessary for the search and counter to find position of entry
	char searched[50];
	pos current = Head->next;

	//Initializing the surname to search by
	getchar();
	printf("\nType the surname you want to search the list by: ");
	fgets(searched, 50, stdin);

	//Searching for the surname and by using StringCompare, a helper function
	while (1)
	{
		if (current == NULL)
		{
			printf("\nNo entry tied to surname %s!\n", searched);
			break;
		}

		if (StringCompare(searched, current->surname) == strlen(searched) - 1)
		{
			printf("\nSurname found! Entry tied to it is:\n%s\t%s\t%d\n", current->name, current->surname, current->yobirth);
			break;
		}

		current = current->next;
	}
}


//Erase element from list
void Erase(pos Head)
{
	//Declaring some temporary variables necessary for the search and counter to find position of entry
	char erase[50];
	pos current = Head->next;
	pos tempconnect = NULL;

	//Initializing the surname to search by
	printf("\nType the surname you want to erase from the list: ");
	fgets(erase, 50, stdin);

	//Searching for the surname and by using StringCompare, a helper function
	while (1)
	{
		if (current == NULL)
		{
			printf("\nNo entry tied to surname %s!\n", erase);
			break;
		}

		if (StringCompare(erase, current->next->surname) == strlen(erase) - 1)
		{
			printf("Successfully deleted the entry!\n");
			tempconnect = current->next->next;
			free(current->next);
			current->next = tempconnect;
			break;
		}

		current = current->next;
	}
}


//Print the list
void PrintList(pos Head)
{
	//Defining temporary variables
	pos current = Head->next;
	
	//Printing the description of the list
	printf("%s", Head->desc);

	//Printing the remainder of the list
	while (current != NULL)
	{
		printf("%s\t%s\t\t%d\n", current->name, current->surname, current->yobirth);
		current = current->next;
	}
}