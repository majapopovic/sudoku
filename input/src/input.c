#include "input.h"

/*int* createSudoku(void)
{
    return (int*)calloc(50,sizeof(int)); 
    *(sudoku+1)=5;
    *(sudoku+7)=9;
    *(sudoku+9)=8;
    *(sudoku+16)=4;
    *(sudoku+21)=3;
    *(sudoku+56)=7;
    *(sudoku+67)=9;
    *(sudoku+73)=6;

}*/

ENTRY* createEntry1(void)
{
	ENTRY* entry=(ENTRY*)malloc(sizeof(ENTRY));
	assignXCoordinate(entry);
	assignYCoordinate(entry);
	assignValue(entry);
	return entry;
}


ENTRY* createEntry2(int a, int b, int c)
{
	ENTRY* entry=(ENTRY*)malloc(sizeof(ENTRY));
	entry->x=a;
	entry->y=b;
	entry->value=c;
	return entry;
}

void assignXCoordinate(ENTRY* entry)
{    
	printf("Unesi x koordinatu:");
	scanf("%d",&(entry->x));
}


void assignYCoordinate(ENTRY* entry)
{    
	printf("Unesi y koordinatu:");
	scanf("%d",&entry->y);
}

void assignValue(ENTRY* entry)
{    
	printf("Unesi broj:");
	scanf("%d",&entry->value);
}

int isEntryValid(ENTRY* entry)
{
	if (isIndexValid(entry) & isValueValid(entry))
	return 1;
	else return 0;
}

int convertIndex(ENTRY* entry)
{
	return (((entry->x) - 1)*9 + (entry->y) - 1);
}


int isValueValid(ENTRY* entry)
{
	if (entry->value>0 & entry->value<10 )
	return 1;
	else return 0;
}


int isIndexValid(ENTRY* entry)
{
	int index=convertIndex(entry);
	if (index>=0 & index<=80 )
	return 1;
	else return 0;
}


