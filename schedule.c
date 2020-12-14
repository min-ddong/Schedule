#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element
//enum type's name
char type_string[MAX_TYPE][20] = 
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

//month's name
char month_string[13][4] = 
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions
typedef enum scheduleType {
	drama=0, 		//��� 
	movie=1, 			//��ȭ 
	advertisement=2, 	//���� 
	entertainment=3, 	//���� 
	meeting=4,		//ȸ�� 
	fitness=5,		//� 
	privacy=6			//���λ� 
} scheduleType_e;



//structure definition for a schedule info.
typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
} schedInfo_t;


void sched_printTypes(void) 
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj) 
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	printf("Schedule Name : %s (%s)\n", schedPtr->name, type_string[schedPtr->type]);
	printf("When : %s. %i\n", month_string[schedPtr->month], schedPtr->day);
	printf("Where : %s\n", schedPtr->place);
	
	return;
}









//generating a structure of scheduling information
void* sched_genSchedInfo(char* name, char* place, int type, int month, int day)
{
	schedInfo_t* schedPtr;
	
	//error handler //�̻��� �� ���Գ� Ȯ��  
	if(name == NULL || place == NULL || type > 6 ||type < 0 || month < 1 || month > 12 || day < 1 || day > 31 )
	return NULL;
	//allocate memory and set the member variables
	//info�� ���� 
	schedPtr = malloc(sizeof(schedInfo_t));
	strcpy(schedPtr->name, name);
	strcpy(schedPtr->place, place);
	schedPtr->type = type;
	schedPtr->month = month;
	schedPtr->day = day;
	
	return (void*)schedPtr;
}



//get month information from the scheduler info structure
float sched_getMonth(void* obj)
{
   return ((schedInfo_t*)obj)->month;
}


//get type information from the scheduler info structure
int sched_getType(void* obj)
{
   return ((schedInfo_t*)obj)->type;
}

char* sched_getPlace(void* obj)
{
   return ((schedInfo_t*)obj)->place;
}

char* sched_getName(void* obj)
{
   return ((schedInfo_t*)obj)->name;
}

int sched_getDay(void* obj)
{
   return ((schedInfo_t*)obj)->day;
}
//convert the name of the type into the enum(integer) value
int sched_convertType(char* typeName)
{
   
}
