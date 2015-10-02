#include "logic.h"
int* generateSudoku(void)
{
    int* sudoku=(int*)calloc(81,sizeof(int)); 
    *(sudoku+1)=5;
    *(sudoku+7)=9;
    *(sudoku+13)=8;
    *(sudoku+16)=4;
    *(sudoku+21)=3;
    *(sudoku+56)=7;
    *(sudoku+67)=9;
    *(sudoku+73)=6;
	return sudoku;
}


int isEmpty(int* sudoku, ENTRY* entry)
{
	if(*(sudoku+convertIndex(entry))==0)
	return 1;
	else return 0;
}


int isColumnfree(int* sudoku, ENTRY* entry)
{
int i;
	for (i=convertIndex(entry)-9;i>=0;)
		{
		if (*(sudoku+i)==entry->value)
			return 0;
		i-=9;
		}

	for (i=convertIndex(entry)+9;i<=80;)
		{
		if (*(sudoku+i)==entry->value)
			return 0;
		i+=9;
		}
	return 1;
}

int isRowfree(int* sudoku, ENTRY* entry)
{
	int rowBegin,i;
	rowBegin=convertIndex(entry)/9;
	rowBegin=rowBegin*9;
	for (i=rowBegin;i<rowBegin+9;i++)
		{
		if (*(sudoku+i)==entry->value)
			return 0;
		}
	return 1;
}

int setInitial(int coordinate)
{
	int initial;
	if (coordinate<4) initial=1;
	else
		{
		if (coordinate<7) initial=4;
		else
			initial=7;
		}
	return initial;
}



int isBoxfree(int* sudoku, ENTRY* entry)
{
	int initialX,i;
	int initialY,j;
	ENTRY* element=(ENTRY*)malloc(sizeof(ENTRY));
//set initial position entry of a box
	initialX=setInitial(entry->x);
	initialY=setInitial(entry->y);
	for (i=0;i<3;i++)
		{
		for (j=0;j<3;j++)
			{
			element->x=initialX+i;
			element->y=initialY+j;
			if (*(sudoku+convertIndex(element))==entry->value)
				return 0;			
			}
		}
	return 1;
}


void updateSudoku (int* sudoku, ENTRY* entry)
{
*(sudoku+convertIndex(entry))=entry->value;
}












