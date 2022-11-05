#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#pragma warning (disable : 4996)

typedef struct person {
    char name[25];
    unsigned int age;
    unsigned int id;
    struct person* next;
    struct person* prev;
}t_person;

t_person* head = NULL;
t_person* tail = NULL;

char fileName[25] = "test.txt";

void printTheList()
{
    t_person* printTheList = head;
    while (printTheList)
    {
        printf("%d\n%s\n%d\n", printTheList->age, printTheList->name, printTheList->id);
        printTheList = printTheList->next;
    }
    return;
}

void addToLinkedList(t_person* curr) 
{
    curr->next = NULL;
    if (!head)
    {
        head = curr;
        tail = curr;
        curr->prev = NULL;
    }
    else
    {
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
    }
}

void saveIntoFile(int argc, char* argv[]) 
{
    FILE* f = fopen(fileName, "w");
    if (!f)
    {
        //error
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            fputs(argv[i], f);
            fputs("\n", f);
        }
        fclose(f);
    }
}

void readFile() 
{
    FILE* f = fopen(fileName, "r");
    if (!f)
    {
        //error
    }
    else
    {
        char tempStr[1000];
        char* token;
        while (fgets(tempStr, 1000, f))
        {
            t_person* currPerson = (t_person*)malloc(sizeof(t_person));
            token = strtok(tempStr, " ");
            strcpy(currPerson->name, token);
            token = strtok(NULL, " ");
            currPerson->age = atoi(token);
            token = strtok(NULL, " ");
            currPerson->id = atoi(token);
            addToLinkedList(currPerson);
        }
    }
}

int main_8(int argc, char* argv[])
{
    saveIntoFile(argc, argv);
    readFile();
    printTheList();
    return 0;
}