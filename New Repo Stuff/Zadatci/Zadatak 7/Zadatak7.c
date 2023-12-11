#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#define EXIT_SUCCESS 420
#define EXIT_FAILURE 404



//Defining structure "Directory"
typedef struct dir
{
	char name[100];
    struct dir* pasDir;
	struct dir* subDir;
    struct dir* nextDir;

} direc;


//Defining necessary functions
direc* setRoot(direc*);
direc* menu(direc*);
direc* make(direc*);
direc* change(direc*);
int newname(direc*);
direc* back(direc*);
int list(direc*);



int main()
{
	//Making root directory
    direc* Root = NULL;
    Root = setRoot(Root);

    //Cycling until user exits program
	while (Root = menu(Root));

	//Ending the program
    return EXIT_SUCCESS;
}



//Defining function for setting root folder
direc* setRoot(direc* Root)
{
	//Allocating space for root directory
    Root = (direc*)malloc(sizeof(direc));

	//Setup of root directory
    printf("Enter root directory name: ");
	scanf("%s", Root->name);
	Root->pasDir = NULL;
	Root->subDir = NULL;
	Root->nextDir = NULL;

    return Root;
}

//Defining function 'menu'
direc* menu(direc* Root)
{   
    int c;
    direc* pos = Root;

    printf("\nList of possible options:\n");
    printf("-------------------------\n");
    printf("1 - List directories\n");
    printf("2 - Make directory\n");
	printf("3 - Change directory name\n");
    printf("4 - Change directory\n");
    printf("5 - Go back a directory\n");
    printf("6 - Exit program\n");

    printf("Which option do you choose? ");
    scanf("%d", &c);

	switch (c)
	{
	case 1:
		list(pos);
		break;

	case 2:
		pos = make(pos);
		break;

	case 3:
		newname(pos);
		break;

	case 4:
		pos = change(pos);
		break;

	case 5:
		pos = back(pos);
		break;

	case 6:
		return NULL;
		break;

	default:
		printf("Wrong option!\n");
		break;
	}

	return pos;
}

//Defining function 'list'
int list(direc* pos)
{
	//Adding two position variables, one for cycling folders,
	//the other for cycling subfolders of those folders
	direc* curr = pos;
	direc* top = pos->subDir;

	printf("\nList of directories and subdirectories:\n");
	printf("-----------------------------------------------\n");

	while (curr != NULL)
	{
		printf("Directory: %s\n", curr->name);
		printf("Subdirectories of %s:\n", curr->name);
		while (top != NULL)
		{
			printf("%s\n", top->name);
			top = top->nextDir;
		}
		printf("\n");
		curr = curr->nextDir;
	}

    return 1;
}

//Defining function 'make'
direc* make(direc* pos)
{
	//Creating new directory
    direc* Entry = NULL;
	direc* next = pos->subDir;
	Entry = (direc*)malloc(sizeof(direc));

	//Checking if directory is allocated correctly
	if (Entry == NULL)
		return NULL;

    else
    {
		//Checking if name available, but searching entire list
		while(1)
		{
			printf("Enter new directory name: ");
			scanf("%s", Entry->name);

			if (pos->subDir == NULL)
				break;

			while (1)
			{
				if (next == NULL)
					break;

				if (strcmp(Entry->name, next->name) == 0)
					break;

				next = next->nextDir;
			}

			if (next == NULL)
				break;

			//Resetting values for proper searching
			else if (strcmp(next->name, Entry->name) == 0)
			{
				printf("%s already exists!\n", Entry->name);
				next = pos->subDir;
			}
		}

		//Adding entry to start
		Entry->subDir = NULL;
		Entry->pasDir = pos;
		Entry->nextDir = pos->subDir;
		pos->subDir = Entry;

		return pos;
    }
}

//Defining function 'change'
direc* change(direc* pos)
{
	//Declaring a name variable to search by
	direc* curr = pos;
	char name[100] = { 0 };
	
	//Printing current subdirectories of parent directory
	printf("\nCurrent subdirectories:");
	list(curr->subDir);
	curr = curr->subDir;

	//Searching for directory with precautions as to the existence of a directory
	while (1)
	{
		printf("Which directory do you want to change into? ");
		scanf("%s", name);

		while (1)
		{
			if (curr == NULL)
			{
				printf("No such directory! Please enter valid name!");
				break;
			}

			if (strcmp(name, curr->name) != 0)
				curr = curr->nextDir;

			if (strcmp(name, curr->name) == 0)
				return curr;

		}
	}
}

//Defining function 'rename'
int newname(direc* pos)
{
	printf("\nEnter new directory name: ");
	scanf("%s", pos->name);

	return 4;
}

//Defining function 'back'
direc* back(direc* pos)
{
	pos = pos->pasDir;
	return pos;
}