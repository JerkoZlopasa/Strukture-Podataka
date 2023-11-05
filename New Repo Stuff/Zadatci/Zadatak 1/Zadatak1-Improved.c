#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <time.h>



//Declaring the structure 'Student'
typedef struct
{
	char name[50];
	char surname[50];
	int points;
}  Student;


//Declaring function prototypes
int countLines(Student*);
Student* allocSpace(Student*, int);
Student* readLines(Student*);
void findMax(Student*, int);
void printList(Student*, int);



int main()
{
	//Declaring a counter and list of students
	int numStud = 0;
	Student* StudList = NULL;


	//Counting lines
	numStud = countLines(StudList);

	//Allocating space for list
	StudList = allocSpace(StudList, numStud);


	//Filling the list
	StudList = readLines(StudList);


	//Finding max points
	findMax(StudList, numStud);


	//Printing the list
	printList(StudList, numStud);


	//Cleaning up memory
	free(StudList);


	return 0;
}



//Defining a function for counting lines
int countLines(Student* List)
{
	//Declaring variables, one for file, one for a buffer, one for counting
	FILE* File = NULL;
	char* buffer[1024] = { 0 };
	int numLines = 0;


	//Opening the file and checking if it was successful
	File = fopen("StudentsAmogus.txt", "r");

	if (File == NULL)
	{
		printf("File not opened!");
		return 0;
	}


	//Counting Lines
	while (!feof(File))
		(fgets(buffer, sizeof(buffer) / sizeof(char), File)) ? numLines++ : 1;


	//Closing the file
	fclose(File);


	return numLines;
}


//Defining a function for allocating memory
Student* allocSpace(Student* List, int numStud)
{
	//Allocating space for field of structures
	List = (Student*)malloc(numStud * sizeof(Student));


	//Checking if the allocation was successful
	if (List == NULL)
	{
		printf("Allocation failed!");
		return 0;
	}
	else
		return List;
}


//Defining a function for reading lines and appending them to the field
Student* readLines(Student* List)
{
	//Declaring necessary variables,
	//a file pointer, buffer for reading and a counter
	FILE* File = NULL;
	int i = 1, real = 0;


	//Opening the file and checking if it was successful
	File = fopen("StudentsAmogus.txt", "r");

	if (File == NULL)
	{
		printf("File not opened!");
		return 0;
	}


	//Skipped over first element, it is a header for the list, 
	// wrote file description into its "name" attribute
	fgets(List->name, sizeof(List->name) / sizeof(char), File);


	//Reading lines and appending them to the list
	while (!feof(File))
	{
		fscanf(File, "%s\t%s\t%d", (List+i)->name, (List+i)->surname, &List[i].points);
		
		//Counting the real number of entries in list
		((List[i].name[0] >= 65 && List[i].name[0] <= 90) || (List[i].name[0] >= 97 && List[i].name[0] <= 122)) ? real++ : 1;

		i++;
	}


	//Closing the file, fixing the alloc-ed space to not be trash, checking for NULL too
	fclose(File);

	List = (Student*)realloc(List, real * sizeof(Student));

	if (List == NULL)
		return NULL;
	else
		return List;
}


//Defining a function to find the max amount of points
void findMax(Student* List, int numStud)
{
	 //Defining a counter
	int i = 0;

	//Writing the max points into the header element, since it is empty
	for (i; i < numStud; i++)
		(List[i].points > List[0].points) ? List[0].points = List[i].points : 1;

}


//Defining a function for printing the list of students
void printList(Student* List, int numStud)
{
	//Declaring a counter variable
	int i = 1;

	//Printing the description
	printf("%.*s\t\tREL. POI.\n", strlen(List->name)-1, List->name);

	//Printing the rest of the list
	for(i; i < numStud; i++)
		if((List+i)->name[0] >=65 && (List + i)->name[0] <= 90)
			printf("%s\t%s\t\t%d\t\t%f\n", List[i].name, List[i].surname, List[i].points, (float)List[i].points/(float)List[0].points);

}