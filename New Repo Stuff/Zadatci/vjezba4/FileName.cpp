#include<stdio.h>
int main()

{
	int i = 0;
	int suma = 0;
	while (i < 11) {
		suma = suma + i;
		i++;
	}
	printf("Suma prvih deset prirodnih brojeva je %d", suma);
	return 0;
		

}
