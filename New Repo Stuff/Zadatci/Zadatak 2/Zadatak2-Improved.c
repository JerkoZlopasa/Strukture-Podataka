#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <time.h>



//Declaring the structure 'Person' and a pointer to its location
typedef struct Person Person;
typedef Person* pos;

struct Person
{
	char name[50];
	char surname[50];
	int yobirth;
	pos next;

};



//Declaring necessary functions
pos setHead(pos);
pos createPerson(void);
pos addBegin(pos);
pos addEnd(pos);
void findPerson(pos);
pos removePersonNum(pos);
pos removePersonSur(pos);
void printList(pos);



int main()
{
	//Setting up header
	pos Header = NULL;
	Header = setHead(Header);

	for (int i = 0; i < 6; i++)
		addBegin(Header);

	printList(Header);

	findPerson(Header);
	removePersonNum(Header);
	removePersonSur(Header);

	printList(Header);


	return 0;
}



//Defining a function for setting up the header member
pos setHead(pos Header)
{
	//Allocating space for header member
	Header = (pos)malloc(sizeof(Person));


	//Adding description for header member
	printf("What is in the list? (separate categories with tabs) ");
	fgets(Header->name, sizeof(Header->name) / sizeof(char), stdin);
	

	//Setting the next member in head's link to be NULL
	Header->next = NULL;

	return Header;
}


//Defining a function to create a 'Person' object to not repeat code
pos createPerson(void)
{
	//Allocating space for the new person
	pos newP = (pos)malloc(sizeof(Person));


	//Adding a name for the new person
	printf("\nThe person's name: ");
	scanf("%s", newP->name);


	//Adding a surname for the new person
	printf("The person's surname: ");
	scanf("%s", newP->surname);


	//Adding a YOB for the new person
	printf("The person's year of birth: ");
	scanf("%d", &newP->yobirth);


	//Setting the point-to-next attribute of the person to NULL
	newP->next = NULL;


	return newP;
}


//Defining a function to add an entry to the start of the list
pos addBegin(pos Header)
{
	//Creating a new entry to add to the list
	pos Entry = createPerson();


	//Checking if the list is empty
	//Yes: add to the very start
	//No: insert between
	if (Header->next == NULL)
		Header->next = Entry;
	else
	{
		Entry->next = Header->next;
		Header->next = Entry;
 	}


	return Header;
}


//Defining a function to add to the end of the list
pos addEnd(pos Header)
{
	//Creating an entry and adding a 'current' variable 
	// to not mess up addresses
	pos Entry = createPerson();
	pos current = Header;


	//Checking if the list is empty
	//Yes: add to the very start
	//No: cycle to end and add
	if (current->next == NULL)
		current->next = Entry;
	else
	{
		while (current->next != NULL)
			current = current->next;

		current->next = Entry;
	}


	return Header;

}


//Defining a function for finding the person based on their surname
void findPerson(pos Header)
{
	//Declaring a surname to be searched and initializing it
	//Adding a position variable to cycle the list with
	char search[50];
	pos current = Header->next;


	//Checking the surname is in the correct range, then appending
	do
	{
		printf("Enter the surname to search the list by: ");
		scanf("%s", search);

	} while (!(search[0] >= 65 && search[0] <= 90) && !(search[0] >= 97 && search[0] <= 122));


	//Checking if the list has the wanted surname and printing the entry tied to it
	while (1)
	{
		if (current->next == NULL && strcmp(search, current->surname) != 0)
		{
			printf("List doesn't contain the surname '%s'!\n", search);
			break;
		}

		else if (strcmp(search, current->surname) == 0)
		{
			printf("Surname found! Entry tied to it is:\n%s\t%s\t\t%d\n\n", current->surname, current->name, current->yobirth);
			break;
		}

		current = current->next;
	}
}


//Defining a function to remove the person based on their surname
pos removePersonSur(pos Header)
{
	//Declaring a surname to be searched and initializing it
	//Adding a position variable to cycle the list with and one to store address to be deleted
	char search[50];
	pos current = Header;
	pos trash = NULL;


	//Checking the surname is in the correct range, then appending
	do
	{
		printf("Enter the surname tied to the entry you want to delete: ");
		scanf("%s", search);

	} while (!(search[0] >= 65 && search[0] <= 90) && !(search[0] >= 97 && search[0] <= 122));


	//Checking if the list has the wanted surname and deleting the entry tied to it
	while (1)
	{
		if (current->next == NULL && strcmp(search, current->next->surname) != 0)
		{
			printf("List doesn't contain the surname '%s'!", search);
			break;
		}

		else if (strcmp(search, current->next->surname) == 0)
		{
			trash = current->next;
			current->next = current->next->next;
			free(trash);

			printf("\nSuccessfully deleted the entry!\n");

			break;
		}

		current = current->next;
	}
}


//Defining a function to remove the person based on the position of the entry
pos removePersonNum(pos Header)
{
	//Declaring three position variables [current pos, wanted pos, total entries] 
	// to cycle the list with, one to store address to be deleted, one to count
	int position[3] = { 0 };
	pos current = Header;
	pos trash = NULL;


	//Printing the list for a clear view of all entries and their positions
	printf("The current list looks like this:\n");
	printf("%s", current->name);


	//Setting the pointer 'current', cycling to find number of entries, then resetting
	current = current->next;
	while (current != NULL)
	{
		printf("%d | %s\t%s\t%d\n", position[2] + 1, current->name, current->surname, current->yobirth);
		current = current->next;
		position[2]++;
	}
	current = Header;


	//Checking the position is in bounds
	do
	{
		printf("\nWhich position would you like to delete? ");
		scanf("%d", position + 1);

	} while (position[1] >= position[2]);


	//Cycling to find the entered position and deleting the entry at it
	while (1)
	{
		if (position[0]+1 == position[1])
		{
			trash = current->next;
			current->next = current->next->next;
			free(trash);

			printf("Successfully deleted the entry\n\n");
			break;
		}

		else
		{
			position[0]++;
			current = current->next;
		}
	}
}


//Defining a function to print the whole list
void printList(pos Header)
{
	//Defining a variable to cycle the list with and initializing it
	pos current = Header->next;


	//Formatted-printing the list
	puts("");

	printf("%s", Header->name);

	while (current != NULL)
	{
		printf("%s\t%s\t\t%d\n", current->name, current->surname, current->yobirth);
		current = current->next;
	}

	puts("");
}