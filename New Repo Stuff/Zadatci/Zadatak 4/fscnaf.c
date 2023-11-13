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
//typedef struct
//{
//	int koef;
//	char unknown;
//	int power;
//
//} Poli;
//
//
//
//int main()
//{
//	FILE* File = fopen("PolyRedo.txt", "r");
//	int status = 0;
//	int num = 0;
//	char* buffer[1024];
//	char* posinstr = buffer;
//	Poli Amogus;
//
//	fgets(buffer, sizeof(buffer), File);
//	
//	while (1)
//	{
//		status = sscanf(posinstr, "%d%c^%d %n", &Amogus.koef, &Amogus.unknown, &Amogus.power, &num);
//
//		if (status == 0)
//			break;
//
//		else if (status == 2)
//		{
//			printf("%d", Amogus.koef);
//			break;
//		}
//
//		
//
//		printf("%d%c^%d\n", Amogus.koef, Amogus.unknown, Amogus.power);
//		posinstr += num + 1;
//	}
//	
//	fclose(File);
//
//
//	return 0;
//}