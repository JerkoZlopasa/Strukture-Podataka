#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#define EXIT_SUCCESS 69420
#define EXIT_FAILURE 404


//Defining the structure 'Num' for the list
typedef struct num
{
	char desc[50];
	int num;
	struct num* next;

} Num;



//Defining necessary functions
Num* push(Num*, int);
int pop(Num*);
void result(Num*);



int main()
{
	Num* Head = (Num*)malloc(sizeof(Num));
	Head->next = NULL;

	result(Head);


	return EXIT_SUCCESS;
}


//Defining the 'Push to stack' function
Num* push(Num* Header, int n)
{
	//Defining 'Entry' variable for number
	Num* Entry = (Num*)malloc(sizeof(Num));

	//Checking if Entry allocated correctly
	if (Entry == NULL)
		return EXIT_FAILURE;

	else
	{
		Entry->num = n;
		Entry->next = Header->next;
		Header->next = Entry;

		return Header;
	}
}


//Defining the 'Call from stack' function
int pop(Num* Header)
{
	int numero = 0;
	Num* temp = Header->next;

	numero = Header->next->num;

	Header->next = Header->next->next;
	free(temp);

	return numero;
}


//Defining the result function
void result(Num* Header)
{
	//Defining a file, buffer, character and number list variable 
	FILE* File = fopen("Postfiks.txt", "r");
	char buffer[50];
	int c = 0;
	int arr[2] = { 0 };
	

	//Checking if file opened successfully
	if (File == NULL)
		return EXIT_FAILURE;

	else
	{
		while (!feof(File))
		{
			//Getting a line from the file
			fgets(buffer, sizeof(buffer), File);
			c = buffer[0];

			//Checking which of the operations the character/number is
			switch (c)
			{
				case '+':
					arr[0] = pop(Header);
					arr[1] = pop(Header);
					push(Header, arr[1] + arr[0]);
					break;

				case '-':
					arr[0] = pop(Header);
					arr[1] = pop(Header);
					push(Header, arr[1] - arr[0]);
					break;

				case '*':
					arr[0] = pop(Header);
					arr[1] = pop(Header);
					push(Header, arr[1] * arr[0]);
					break;

				case '/':
					arr[0] = pop(Header);
					arr[1] = pop(Header);
					push(Header, arr[1] / arr[0]);
					break;

				//If none of the conditions above are satisfied, pushed the number version of c to stack
				default:
					push(Header, c - 48);
					break;
			}
		}

		//Closing file and printing result
		fclose(File);
		printf("%d", Header->next->num);
	}
}