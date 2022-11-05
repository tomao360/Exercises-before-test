//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#pragma warning(disable : 4996)
//
//
////-----------Sorted Linked List-----------
//
//struct Item
//{
//	int val;
//	struct Item* next;
//	struct Item* prev;
//};
//struct Item* Head = NULL;
//struct Item* Tail = NULL;
//
//void Add(int val)
//{
//	struct Item* currentItem = (struct Item*) malloc(sizeof(struct Item));
//	if (currentItem == NULL)
//	{
//		//ERROR
//		return;
//	}
//	
//	currentItem->val = val;
//
//	if (Head == NULL)
//	{
//		Head = currentItem;
//		Tail = currentItem;
//		currentItem->next = NULL;
//		currentItem->prev = NULL;
//	}
//	else
//	{
//		Tail->next = currentItem;
//		currentItem->prev = Tail;
//		currentItem->next = NULL;
//		Tail = currentItem;
//	}
//}
//
//void GenerateList()
//{
//	srand(time(NULL));
//
//	for (int i = 0; i < 10; i++)
//	{
//		Add(rand() / 1000);
//	}
//}
//
//void PrintList()
//{
//	struct Item* currentItem = Head;
//
//	while (currentItem != NULL)
//	{
//		printf("%d\n", currentItem->val);
//		currentItem = currentItem->next;
//	}
//}
//
//void FreeList()
//{
//	struct Item* currentItem = Head;
//	struct Item* release;
//
//	while (currentItem != NULL)
//	{
//		release = currentItem;
//		currentItem = currentItem->next;
//		free(release);
//	}
//}
//
//struct Item* FindVal(int val)
//{
//	struct Item* currentItem = Head;
//	struct Item* ret;
//
//	while (currentItem != NULL)
//	{
//		if (currentItem->val == val)
//		{
//			ret = currentItem;
//			return ret;
//		}
//
//		currentItem = currentItem->next;
//	}
//
//	printf("There is no such number in the list\n");
//	return NULL;
//}
//
//struct Item* ChangeVal(int oldVal, int newVal)
//{
//	struct Item* OldVal = FindVal(oldVal);
//
//	OldVal->val = newVal;
//
//	return OldVal;
//}
//
//void ResetList()
//{
//	if (Head != NULL)
//	{
//		FreeList();
//		Head = NULL;
//		Tail = NULL;
//	}
//}
//
//
//struct Item* HigherNumber(int val)
//{
//	struct Item* currentItem = Head;
//
//	while (currentItem != NULL)
//	{
//		if (currentItem->val > val)
//		{
//			return currentItem;
//		}
//
//		currentItem = currentItem->next;
//	}
//
//	return NULL;
//}
//
//void LocateAfterTail(struct Item* item)
//{
//	Tail->next = item;
//	item->prev = Tail;
//	item->next = NULL;
//	Tail = item;
//}
//
//void LocateBeforeHead(struct Item* item)
//{
//	Head->prev = item;
//	item->next = Head;
//	item->prev = NULL;
//	Head = item;
//}
//
//void LocateBeforeItem(struct Item* newItem, struct Item* itemInList)
//{
//	newItem->next = itemInList;
//	itemInList->prev->next = newItem;
//	newItem->prev = itemInList->prev;
//	itemInList->prev->next = newItem;
//}
//
//void InsertItem(int val)
//{
//	struct Item* currentItem = (struct Item*)malloc(sizeof(struct Item*));
//	if (currentItem == NULL)
//	{
//		//ERROR
//		return;
//	}
//
//	currentItem->val = val;
//
//	if (Head == NULL)
//	{
//		Head = currentItem;
//		Tail = currentItem;
//		currentItem->next = NULL;
//		currentItem->prev = NULL;
//	}
//	else
//	{
//		struct Item* higherNum = HigherNumber(currentItem->val);
//
//		if (higherNum == NULL)
//		{
//			LocateAfterTail(currentItem);
//		}
//		else
//		{
//			if (higherNum == Head)
//			{
//				LocateBeforeHead(currentItem);
//			}
//			else
//			{
//				LocateBeforeItem(currentItem, higherNum);
//			}
//		}
//	}
//}
//
//
//
//int main_5()
//{
//	//GenerateList();
//	//PrintList();
//
//	//int number, number1;
//	//printf("Please enter the number that you are looking for in the list: ");
//	//scanf("%d", &number);
//	//struct Item* a = FindVal(number);
//	//printf("%p\n", a);
//
//	//printf("Please enter old value, and a new value: ");
//	//scanf("%d %d", &number, &number1);
//	//struct Item* b = ChangeVal(number, number1);
//	//printf("%p\n", b);
//
//	////FreeList();
//
//	ResetList();
//
//	InsertItem(23);
//	InsertItem(2);
//	InsertItem(65);
//	InsertItem(0);
//	InsertItem(25);
//	InsertItem(5);
//
//	PrintList();
//
//	return 0;
//}