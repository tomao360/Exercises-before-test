#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#include "libexe.h"

//-----------bits-----------
//-----------.lib-----------

//Exercise 1
void MoveBit(unsigned char num, unsigned char moveBits)
{
	unsigned char number = num;
	number = number << moveBits;
	printf("%d", number);
}

//Exercise 3
void PrintBin(unsigned char num)
{
	unsigned char number = num;
	unsigned char mask = 0b10000000;

	for (int i = 0; i < 8; i++)
	{
		unsigned char checkBit = number & mask;

		if (checkBit != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}

		mask = mask >> 1;
	}
}

//Exercise 4 - HW
void checkBit(unsigned char num)
{
	unsigned char number = 0b00000001;
	unsigned char mask = 0b10000000;
	number = number << num - 1;


	for (int i = 0; i < 8; i++)
	{
		char oneBit = number & mask;

		if (oneBit != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}

		mask = mask >> 1;
	}
}


int main_1()
{
	MoveBit(23, 5);
	printf("\n");
	PrintBin(23);
	printf("\n");
	checkBit(7);
	printf("\n");

	//.lib
	int a =  mult(5,7);
	printf("%d", a);

	return 0;
}
