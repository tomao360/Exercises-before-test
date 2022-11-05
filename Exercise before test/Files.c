#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//-----------Files-----------

void HowManyChar()
{
	FILE* f = fopen("C:\\Users\\97252\\source\\repos\\Exercise before test\\Exercise before test\\Exe1.txt", "r");
	if (f == NULL)
	{
		//ERROR
		return;
	}

	char ch = fgetc(f);
	int counter = 0;

	while (ch != EOF)
	{
		ch = fgetc(f);
		counter++;
	}

	printf("%d\n", counter);
	fclose(f);
}

void HowManyAsterisks()
{
	FILE* f = fopen("C:\\Users\\97252\\source\\repos\\Exercise before test\\Exercise before test\\Exe1.txt", "r");
	if (f == NULL)
	{
		//ERROR
		return;
	}

	char ch = fgetc(f);
	int counter = 0;

	while (ch != EOF)
	{
		ch = fgetc(f);

		if (ch == '*')
		{
			counter++;
		}
	}

	printf("%d\n", counter);
	fclose(f);
}

void HowManyLines()
{
	FILE* f = fopen("C:\\Users\\97252\\source\\repos\\Exercise before test\\Exercise before test\\Exe2.txt", "r");
	if (f == NULL)
	{
		//ERROR
		return;
	}

	char ch = fgetc(f);
	int counterLines = 1;

	while (ch != EOF)
	{
		ch = fgetc(f);
		if (ch == '\n')
		{
			counterLines++;
		}
	}

	printf("%d\n", counterLines);
	fclose(f);
}


void readFile()
{
	FILE* f = fopen("C:\\Users\\97252\\source\\repos\\Exercise before test\\Exercise before test\\Exe3.txt", "r");
	if (f == NULL)
	{
		//ERROR
		return;
	}

	char ch = 0;
	while (ch != EOF)
	{
		char number = fgetc(f) - '0';
		ch = fgetc(f);

		if (ch == 'c')
		{
			char* charPtr = (char*)malloc(sizeof(char) * number);
			if (charPtr == NULL)
			{
				//ERROR
				return;
			}

			char* original = charPtr;
			int num;
			printf("Please enter %d characters\n", number);
			for (int i = 0; i < number; i++)
			{
				scanf(" %c", &num);
				charPtr++;
			}
			free(original);
		}

		if (ch == 'i')
		{
			int* charInt = (int*)malloc(sizeof(int) * number);
			if (charInt == NULL)
			{
				//ERROR
				return;
			}

			int* original = charInt;
			int num;
			printf("Please enter %d integer numbers\n", number);
			for (int i = 0; i < number; i++)
			{
				scanf("%d", &num);
				charInt++;
			}

			free(original);
		}
	}

	fclose(f);
}

void CreateFiles(int num)
{
	char str[20] = "";
	char asterisks[10] = "";

	for (int i = 1; i <= num; i++)
	{
		sprintf(str, "file%d.txt", i);

		FILE* f = fopen(str, "w");
		if (f == NULL)
		{
			//ERROR
			return;
		}

		asterisks[i-1] = '*'; //you start to put the asterisks from the first cell (no cell 0), because of this I did i-1

		fwrite(&asterisks, sizeof(char) * i, 1, f); //fwrite starts to read from character 0
		fclose(f);
	}
}




int main_3()
{
	HowManyChar();
	HowManyAsterisks();
	HowManyLines();
	//readFile();
	CreateFiles(3);

	return 0;
}