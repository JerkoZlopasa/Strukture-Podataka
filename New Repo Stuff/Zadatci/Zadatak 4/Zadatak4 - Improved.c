#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <time.h>


//Defining a structure and position argument for the object 'Polinome'
typedef struct poli Poli;
typedef Poli* pos;

struct poli
{
	char desc[50];
	char unknown;
	int koef;
	int pot;
	pos next;
};



//Defining necessary functions
pos setHead(pos);
pos readPoli(pos);
pos sortInput(pos);
pos sumPoli(pos, pos, pos);
pos prodPoli(pos, pos, pos);
pos printPoli(pos);



int main()
{
	//Declaring all necessary variables for task and initializing them
	pos Head = (pos)malloc(sizeof(Poli));
	pos PolSum = (pos)malloc(sizeof(Poli));
	pos PolProd = (pos)malloc(sizeof(Poli));


	//Sets up header member and makes a list of polinomes
	setHead(Head);
	readPoli(Head);

	sortInput(Head);

	return 0; 
}



//Defining a function for setting up the header of the list
pos setHead(pos Header)
{
	//Declaring a file variable to read description from
	FILE* File = fopen("Polinomi.txt", "r");


	//Checking if file opened successfully
	if (File == NULL)
	{
		printf("File failed to open!");
		return NULL;
	}

	
	//Reading the first line, assumed to be a header, 
	// because all nicely sorted data needs a header :)
	fgets(Header->desc, sizeof(Header->desc) / sizeof(char), File);
	

	//Setting connection of header to NULL for now
	Header->next = NULL;


	//Closing file
	fclose(File);


	return Header;
}


//Defining a function for defining the number of polinomes
pos readPoli(pos Header)
{
	//Defining a file pointer variable, a list which will hold polinomes and a counter
	//Also declaring and initializing buffer used for checking if reading reached end-of-polinome
	FILE* File = fopen("Polinomi.txt", "r");
	char buffer[1024] = { 0 };
	pos ListPoli = NULL;
	int numPoli = 0;
	int i = 0;


	//Checking if file opened successfully
	if (File == NULL)
	{
		printf("File failed to open!");
		return NULL;
	}


	//Skipping first line, assumed to be header
	while (fgetc(File) != '\n');


	//Counting number of polinomes
	while (1)
	{
		//Getting a line to check from file
		fgets(buffer, sizeof(buffer) / sizeof(char), File);


		//Checking if the character in first line isn't in the 0-9 range
		//That means that an end of the polinome has been reached
		(!(buffer[0] >= 48 && buffer[0] <= 57)) ? numPoli++ : 1;


		//If the end of file is reached, that means and end of polinomes, too
		if (feof(File))
		{
			numPoli++;
			break;
		}
	}

	
	//Initializing a list to hold polinomes and connecting to header
	//and setting every ListPoli member's connection to NULL
	ListPoli = (pos)malloc(numPoli * sizeof(Poli));
	Header->next = ListPoli;

	for (i = 0; i < numPoli; i++)
		ListPoli[i].next = NULL;


	//Closing file
	fclose(File);


	return Header;
}


//Defining a function for sorted input
pos sortInput(pos Header)
{
	//Declaring all necessary variables, a 'current' variable for positioning, a 'listEl' variable
	//for cycling the list in a member
	//a buffer for reading lines and an integer to cycle the greater list containing polinomes 
	FILE* File = fopen("Polinomi.txt", "r");
	pos listEl = Header->next;
	pos Entry = NULL;
	pos current = listEl;
	char buffer[1024] = { 0 };
	int i = -1;


	//Checking if file opened successfully
	if (File == NULL)
	{
		printf("File failed to open!");
		return NULL;
	}


	//Sorted input, using header line too
	while (!feof(File))
	{
		//Get line from file to check
		fgets(buffer, sizeof(buffer) / sizeof(char), File);

		//If the first char of the buffer-string is a number, it gets appended to the list
		if (buffer[0] >= 48 && buffer[0] <= 57)
		{
			//Preparing object 'Entry' for potential insertion
			Entry = (pos)malloc(sizeof(Poli));
			Entry->next = NULL;
			sscanf(buffer, "%d\t%c\t%d", &Entry->koef, &Entry->unknown, &Entry->pot);

			//How to deal with an unitialized entry? Make it a header for the polinome!
			if (!(current->koef >= 48 && current->koef <= 57) && current->next == NULL)
			{
				strcpy_s(current->desc, sizeof(Header->desc), "Polinome start!");
				current->next = Entry;
				current = current->next;
			}

			//Accounting for greater power (both ways)
			else if (Entry->unknown == current->next->unknown && Entry->pot > current->next->pot)
			{
				Entry->next = current->next;
				current->next = Entry;
			}

			else if (Entry->unknown == current->next->unknown && Entry->pot < current->next->pot)
			{
				while (current->next != NULL && current->next->pot > Entry->pot)
					current = current->next;

				Entry->next = current->next;
				current->next = Entry;
			}


			//Resetting the position
			current = listEl + i;
		}

		//If the first char of buffer-string isn't a number, it increases the index of the greater-list member
		//NOTE: The -1 is here done because of header file, so in the first pass it cleverly won't take the
		//greater-list member at listEl[-1], but cycle to listEl[0] and through its members instead
		else
		{
			i++;
			current = listEl + i;
		}
	}


	//Summing all the entries with the same power
	while (i >= 0)
	{
		current = listEl[i].next;
		Entry = listEl[i].next->next;
		
		while (Entry != NULL)
		{
			if (current->unknown == Entry->unknown && current->pot == Entry->pot)
			{
				while (Entry != NULL && current->pot == Entry->pot)
				{
					current->koef += Entry->koef;
					Entry = Entry->next;
				}
				current->next = Entry;
				break;
			}

			else
			{
				current = current->next;
				Entry = Entry->next;
			}
		}

		i--;
	}


	//Closing file
	fclose(File);


	current = listEl[1].next;
	while (current != NULL)
	{
		printf("%d %c %d\n", current->koef, current->unknown, current->pot);
		current = current->next;
	}


	return Header;
}


//Defining a function for printing the needed polinome
pos printPoli(pos Poli)
{
	//Declaring and initializing a position variable
	pos	current = Poli; 


	//Printing the polinome
	while (current != NULL)
	{
		//First condition checks if the element is in the beginning or middle
		if (current->next != NULL)
			printf("%d%c^%d + ", current->koef, current->unknown, current->pot);

		//Second condition checks if the element is at the end for a nice, formatted printing experience
		else
			printf("%d%c^%d", current->koef, current->unknown, current->pot);
	
		//Updating the position
		current = current->next;
	}


	return Poli;

}