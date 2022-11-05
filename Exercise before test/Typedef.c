#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

// typedef existing_data_type new_data_type

// typedef gives freedom to the user by allowing them to create their own types

typedef int INTEGER;
typedef char Character;

typedef char user[100];
typedef unsigned long long ProcessData;

typedef struct s_Process // t_process 
{
	char ProcessName[100];
	int ProcessId;
	ProcessData WorkingSetSize;
	struct s_Process* next; // *
	struct s_Process* prev; // using struct for pointers

}t_Process;

#define DEBUG

#ifdef DEBUG

int main_10()
{

	/*char user1[25] = "Bro";*/

	INTEGER number = 125;
	Character letter = "A";

	user user1 = "Bro";
	user user2 = "hay";

	ProcessData WorkingSetSize = 153547913;
	ProcessData PageFualtCount = 153547913;

	t_Process* Process = (t_Process*)malloc(sizeof(t_Process));
	Process->ProcessId = 558;
	Process->prev = NULL;

	return 0;
}

#endif // DEBUG
