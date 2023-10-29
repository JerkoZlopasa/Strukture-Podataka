#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <time.h>



//Declaring structure 'Student'
typedef struct
{
	char name[50];
	char surname[50];
	int point;

} Student;


//Declaring necessary functions
int CountStud(void);
Student* ReadStud(Student*, int, int*);
void PrintList(Student*);


int main()
{
	int maxPoint = 0;
	int numStud = CountStud();
	Student* StudList = (Student*)malloc(numStud*sizeof(Student));
	
	StudList = ReadStud(StudList, numStud, &maxPoint);

	PrintList(StudList, numStud, &maxPoint);

	return 0;
}



//Function for counting students
int CountStud()
{
	//Declaring necessary variables
	FILE* pointFile = fopen("StudentsAmogus.txt", "r");
	int count = 0;
	char buffer[1024];

	//Opening file and checking if opening is successful
	if (pointFile == NULL)
	{
		printf("Failed to open file!");
		return 0;
	}
	else
	{
		//Skipping first line which is assumed to be a description
		while (fgetc(pointFile) != '\n');

		//Counting the number of students
		while (!feof(pointFile))
			if(fgets(buffer, 1024, pointFile))
				count++;
		
		fclose(pointFile);
	}

	return count;
}


//Function for reading students off of file
Student* ReadStud(Student* StudList, int numStud, int* maxPoint)
{
	//Declaring necessary variables
	int i = 0;
	FILE* pointFile = fopen("StudentsAmogus.txt", "r");


	//Opening file and checking if opening is successful
	if (pointFile == NULL)
	{
		printf("Failed to open file!");
		return 0;
	}
	else
	{
		//Skipping first line which is assumed to be a description
		while (fgetc(pointFile) != '\n');

		//Reading the file, adding 'Students' to 'StudList'
		for (i; i < numStud; i++)
		{
			fscanf(pointFile, "%s\t%s\t%d", (StudList + i)->name, (StudList + i)->surname, &StudList[i].point);
			
			(StudList[i].point > *maxPoint) ? *maxPoint = StudList[i].point : 1;
		}
	}


	return StudList;
}


//Function for printing the list 
void PrintList(Student* StudList, int numStud, int* maxPoint)
{
	//Declaring necessary variables
	int i = 0;
	char desc[100];
	FILE* pointFile = fopen("StudentsAmogus.txt", "r");


	//Checking if file opened correctly, getting description of list params, then printing it and closing file
	if (pointFile == NULL)
	{
		printf("Failed to open file!");
		return 0;
	}
	else
	{
		printf("%s", fgets(desc, 50, pointFile));
		fclose(pointFile);
	}


	//Printing list entries
	for (i; i < numStud; i++)
		printf("%s\t%s\t\t%d\t\t%.2f\n", StudList[i].name, StudList[i].surname, StudList[i].point, (float)StudList[i].point/(float)*maxPoint);
}