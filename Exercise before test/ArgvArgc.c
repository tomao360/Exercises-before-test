#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)


//-----------Argv Argc-----------

void TestCopy(char* fileSource, char* fileDest)
{
	FILE* f = fopen(fileSource, "r");
	if (f == NULL)
	{
		//ERROR
		return;
	}

	char temp;
	int count = 0;

	while (fread(&temp, sizeof(char), 1, f))
	{
		count++;
	}

	fclose(f);

	f = fopen(fileSource, "r");
	if (f == NULL)
	{
		//ERROR
		return;
	}

	char* filecontent = (char*)malloc(sizeof(char) * count);
	if (filecontent == NULL)
	{
		//ERROR
		return;
	}

	fread(filecontent, sizeof(char) * count, 1, f);
	fclose(f);

	f = fopen(fileDest, "w");
	if (f == NULL)
	{
		//ERROR
		return;
	}

	fputs(filecontent, f);
	fclose(f);
	free(filecontent);

}


int main_7(int argc, char* argv[])
{
	printf("start");
	TestCopy(argv[1], argv[2]);


	return 0;
}
