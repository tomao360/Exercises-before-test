#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)


//-----------Dynamic Arrays-----------

struct Item
{
	int val;
	char name[100];
	short answer;
};

void EnterData(int num)
{
	struct Item* currentItem = (struct Item*)malloc(sizeof(struct Item) * num);
	if (currentItem == NULL)
	{
		//ERROR
		return;
	}

	struct Item* original = currentItem;

	int number;
	char str[30];
	int sum = 0;

	for (int i = 0; i < num; i++)
	{
		printf("Please enter val, and name: ");
		scanf("%d %s", &number, str);

		currentItem->val = number;
		strcpy(currentItem->name, str);

		if (strlen(currentItem->name) > 5 && currentItem->val > 10)
		{
			currentItem->answer = 1;
		}
		else
		{
			currentItem->answer = 0;
		}

		sum += currentItem->val;

		currentItem++;
	}

	printf("The sum of val is: %d", sum);

	free(original);
}


int main_4()
{
	int num;
	printf("Please enter the of the structs that you need: ");
	scanf("%d", &num);
	EnterData(num);

	return 0;
}