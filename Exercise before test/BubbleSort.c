#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

struct ItemNum
{
	int num;
	struct ItemNum* next;
	struct ItemNum* prev;
};
struct ItemNum* Head = NULL;
struct ItemNum* Tail = NULL;

//A function that writes a Log file
void Log(char message[100])
{
	//Enters the current date + time 
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);

	char str[100];
	sprintf(str, "%d.%d.%d: %d:%d:%d - ", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);


	FILE* f = fopen("LogFile.log", "a");
	fputs(str, f);
	fputs(message, f);
	fputs("\n", f);

	fclose(f);
}

//We will call this function when we have ERROR
void LogError(char message[100])
{
	char str[100];
	sprintf(str, "Error - %s", message);
	Log(str);
}

//We will call this function when we have an EVENT
void LogEvent(char message[100])
{
	char str[100];
	sprintf(str, "Event - %s", message);
	Log(str);
}

//We will call this function when we have an EVENT + want to write the value
void LogEventVal(char message[100], int val)
{
	char str[100];
	sprintf(str, "Event -  %s: Item Value: %d", message, val);
	Log(str);
}

void Add(int num)
{
	struct ItemNum* currentItem;
	currentItem = (struct ItemNum*)malloc(sizeof(struct ItemNum));
	if (currentItem == NULL)
	{
		LogError("Memory allocation problem");
		return;
	}
	else
	{
		currentItem->num = num;

		if (Head == NULL)
		{
			LogEvent("List starts Now");
			LogEventVal("Create new Item", num);

			Head = currentItem;
			Tail = currentItem;
			currentItem->next = NULL;
			currentItem->prev = NULL;
		}
		else
		{
			LogEventVal("A new value is Added", num);
			Tail->next = currentItem;
			currentItem->prev = Tail;
			currentItem->next = NULL;
			Tail = currentItem;
		}
	}
}

void PrintList()
{
	LogEvent("The list has been printed");

	int countItem = 1;
	struct ItemNum* currentItem = Head;

	printf("\nThe resulting linked list:\n");
	while (currentItem != NULL)
	{
		printf("#%d Item->num = %d\n", countItem, currentItem->num);
		currentItem = currentItem->next;
		countItem++;
	}
}

//Generates random numbers and puts them in a list
void GrillRandomNumber()
{
	LogEvent("Start inserting random numbers to the list");

	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		Add(rand());
	}

	LogEvent("End inserting random numbers to the list");
	LogEvent("List ends Now");
}

//Making swap between two Items
void Replace(struct ItemNum* item)
{
	if (item == NULL) //No Items in the list
	{
		LogEventVal("No need to swap. There is no Items in the list.", item->num);
		return;
	}
	else if (item->next == NULL) //One Item in the list
	{
		LogEventVal("No need to swap. There is only 1 Item in the list.", item->num);
		return;
	}
	else if (item == Head && item->next == Tail) //2 Items in the list: Head and Tail
	{
		item->next = NULL;
		item->prev = Tail;
		Tail->next = item;
		Tail->prev = NULL;
		Tail = item;
		Head = item->prev;
	}
	else if (item == Head && item->next != NULL) //2 first Items in the list
	{
		item->next = item->next->next;
		item->next->prev->next = item;
		item->next->prev->prev = NULL;
		item->prev = item->next->prev;
		item->next->prev = item;
		Head = item->prev;
	}
	else if (item->next == Tail && item->prev != NULL) //2 last Items in the list
	{
		item->prev->next = item->next;
		item->next->prev = item->prev;
		item->next->next = item;
		item->prev = item->next;
		item->next = NULL;
		Tail = item;
	}
	else //2 middle Items
	{
		item->prev->next = item->next;
		item->next = item->next->next;
		item->next->prev->prev = item->prev;
		item->prev = item->next->prev;
		item->next->prev->next = item;
		item->next->prev = item;
	}
}

//Sorts the list
void BubbleSort()
{
	//Start calculation of time
	time_t t1;
	time(&t1);


	//Starting to sort the list
	struct ItemNum* currentItem = Head;
	if (currentItem == NULL)
	{
		LogError("The List is empty");
		return;
	}

	LogEvent("Swap Item");
	int counter = 1;
	while (counter != 0)
	{
		counter = 0;
		currentItem = Head;

		while (currentItem != NULL)
		{
			if (currentItem->next != NULL && currentItem->num > currentItem->next->num)
			{
				Replace(currentItem);
				counter++;
				currentItem = currentItem->prev;
			}

			currentItem = currentItem->next;
		}
	}


	LogEvent("End sort list");

	time_t t2;
	time(&t2);
	time_t t3 = t2 - t1;
	struct tm* timeinfo;
	timeinfo = localtime(&t3);
	char str[100];
	sprintf(str, "Time between start sort and end sort is: %02d minutes and %02d seconds", timeinfo->tm_min, timeinfo->tm_sec);
	LogEvent(str);
}

//Free the list
void FreeList()
{
	LogEvent("Free list");

	struct ItemNum* currentItem = Head;
	struct ItemNum* release;

	while (currentItem != NULL)
	{
		release = currentItem;
		currentItem = currentItem->next;
		free(release);
	}
}

int main_9()
{
	srand(time(NULL));

	char userResponse = NULL;
	while (userResponse != 'E')
	{
		printf("\nPlease enter one of the following choices:\n1-Insert random numbers to the linked list\n2-Print the linked list\n3-Sort the list\nE-Exit the program\n");
		userResponse = getch();

		switch (userResponse)
		{
		case '1': //Insert random numbers to the linked list
			GrillRandomNumber();
			break;
		case '2': //Print the linked list
			PrintList();
			break;
		case '3': //Sort the list
			LogEvent("Start sort list");
			BubbleSort();
			break;
		case 'E':
			printf("Thank you for using our program\n");
			break;

		default:
			printf("Wrong selection, please try again\n");
			break;
		}
	}

	FreeList();


	return 0;
}