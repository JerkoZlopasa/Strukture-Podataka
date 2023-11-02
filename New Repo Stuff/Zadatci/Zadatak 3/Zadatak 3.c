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



//Declaring necessary functions (past task)
pos setHead(pos);
pos createPerson(void);
pos addBegin(pos);
pos addEnd(pos);
void findPerson(pos);
pos removePersonNum(pos);
pos removePersonSur(pos);
void printList(pos);



//Declaring necessary functions (this task)
pos addAfter(pos);
pos addBefore(pos);
pos sortSur(pos);
pos writeFile(pos);
pos readFile(pos);



//Exercise for reader: Test all zhe functiones and gib bugs if any exist. Hope I coded this well bruh
int main()
{
	//Setting up header1
	pos Header = NULL;
	Header = setHead(Header);


	//Setting up header2
	//NOTE: No need for setHead function, 
	//this one gets read from the file, not from stdin
	pos Header2 = (pos)malloc(sizeof(Person));
	Header2->next = NULL;

	sortSur(Header);
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


	return Header;
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
		if (position[0] + 1 == position[1])
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


	return Header;
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





//Defining a function for writing old list to file
pos writeFile(pos Header)
{
	//Defining a file variable and a position variable
	FILE* File = fopen("Persons.txt", "w");
	pos current = Header;


	//Checking if file opened successfully
	if (File == NULL)
	{
		printf("Failed to open file!");
		return NULL;
	}

	//Writing to file, description included
	else
	{
		//Printing header line into file (description)
		fprintf(File, "%s", current->name);
		current = current->next;

		while (current != NULL)
		{
			fprintf(File, "%s\t%s\t\t%d\n", current->name, current->surname, current->yobirth);
			current = current->next;
		}
	}


	//Closing file
	fclose(File);


	return Header;
}


//Defining a function for reading from file
//NOTE: Using new list from now on, I wanna keep things nice, tidy and organized, dammit! xD
pos readFile(pos Header2)
{
	//Defining a file variable and a position variable
	FILE* File = fopen("Readme.txt", "r");
	pos current = Header2;
	pos newP2 = NULL;

	//Checking if file opened successfully
	if (File == NULL)
	{
		printf("Failed to open file!");
		return NULL;
	}


	//Reading header of file
	fgets(Header2->name, 50, File);

	//Reading the rest of the file
	while (!feof(File))
	{
		newP2 = (pos)malloc(sizeof(Person));
		newP2->next = NULL;
		if(fscanf(File, "%s %s %d", newP2->name, newP2->surname, &newP2->yobirth));
		current->next = newP2;
		current = current->next;
	}


	//Closing the file
	fclose(File);


	return Header2;
}


//Defining a function for adding a new element at a certain point
pos addAfter(pos Header2)
{
	//Declaring three position variables [current pos, wanted pos, total entries] 
	// to cycle the list with, one to store new entry, one to count
	int position[3] = { 0 };
	pos current = Header2;
	pos Entry = NULL;


	//Printing the list for a clear view of all entries and their positions
	printf("\nThe current list looks like this:\n");
	printf("%s", current->name);


	//Setting the pointer 'current', cycling to find number of entries, then resetting
	current = current->next; 
	while (current != NULL) 
	{
		printf("%d | %s\t%s\t%d\n", position[2] + 1, current->name, current->surname, current->yobirth); 
		current = current->next; 
		position[2]++;
	}
	//Useful little line, makes the pos of the choice line up to the actual pos in the list. heheee cleverrr
	current = Header2;  


	//Checking the position is in bounds
	do
	{
		printf("\nAfter which position would you like to add an entry? ");
		scanf("%d", position + 1);

	} while (position[1] >= position[2]);


	//Creating new entry for the list
	Entry = createPerson();


	//Cycling to find the entered position and adding the entry after it
	while (1)
	{
		if (position[0] == position[1])
		{
			Entry->next = current->next;
			current->next = Entry;

			printf("Successfully added the entry\n\n");
			break;
		}

		else
		{
			position[0]++;
			current = current->next;
		}
	}


	return Header2;
}


//Defining a function for adding a new element before a certain point
pos addBefore(pos Header2)
{
	//Declaring three position variables [current pos, wanted pos, total entries] 
	// to cycle the list with, one to store address to be deleted, one to count
	int position[3] = { 0 };
	pos current = Header2;
	pos Entry = createPerson();


	//Printing the list for a clear view of all entries and their positions
	printf("\nThe current list looks like this:\n");
	printf("%s", current->name);


	//Setting the pointer 'current', cycling to find number of entries, then resetting
	current = current->next;
	while (current != NULL)
	{
		printf("%d | %s\t%s\t%d\n", position[2] + 1, current->name, current->surname, current->yobirth);
		current = current->next;
		position[2]++;
	}
	current = Header2;


	//Checking the position is in bounds
	do
	{
		printf("\nWhich position would you like to add before? ");
		scanf("%d", position + 1);

	} while (position[1] >= position[2]);


	//Cycling to find the entered position and add entry before it
	while (1)
	{
		if (position[0] + 1 == position[1])
		{
			Entry->next = current->next;
			current->next = Entry;

			printf("Successfully added the entry\n\n");
			break;
		}

		else
		{
			position[0]++;
			current = current->next;
		}
	}


	return Header2;
}


//Defining a function for sorted input of surnames
pos sortSur(pos Header)
{
	//Defining a 'current' variable for cycling the list, 
	// 'Entry' variable to house new entry and counter [current num, num entries]
	//Also 
	pos current = Header;
	pos Entry = NULL;
	int num[2] = { 0 };


	//Setting how many entries there are
	printf("How many entries do you want to add to the list? ");
	scanf("%d", num + 1);


	//Creating initial entry to have something to compare to
	Header->next = createPerson(); 
	
	//Doing sorted input, -1 due to initial entry
	for (num[0]; num[0] < num[1]-1; num[0]++)
	{
		//Creating other entries
		Entry = createPerson();

		while (current->next != NULL)
		{
			if (strcmp(Entry->surname, current->next->surname) < 0)
			{
				Entry->next = current->next;
				current->next = Entry;
				break;
			}

			else if (strcmp(Entry->surname, current->next->surname) > 0)
			{
				current = current->next;
			}

			else
				break;
		
		}

		current = Header;
	}


	return Header;
}