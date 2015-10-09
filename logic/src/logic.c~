#include "logic.h"
#include "../../gui/src/gui.h"


int* generateSudoku(int choice)
{
    original=(int*)calloc(81,sizeof(int)); 
	switch(choice)
	{
		case 0:
		{
			original[1]=6;
			original[2]=4;
			original[4]=3;
			original[5]=2;
			original[7]=8;
			original[8]=1;

			original[9]=3;
			original[15]=7;
			original[16]=9;

			original[18]=8;
			original[19]=7;
			original[22]=9;
			original[23]=5;

			original[29]=6;
			original[30]=1;
			original[34]=4;

			original[36]=4;
			original[37]=3;
			original[43]=2;
			original[44]=8;//////

			original[46]=8;
			original[50]=4;
			original[51]=9;

			original[57]=5;
			original[58]=4;
			original[61]=6;
			original[62]=9;

			original[64]=9;
			original[65]=3;
			original[71]=7;

			original[72]=5;
			original[73]=4;
			original[75]=9;
			original[76]=7;
			original[78]=2;
			original[79]=1;
			break;
		}
		case 1:
		{
			original[0]=3;
			original[2]=2;
			original[4]=5;
			original[5]=4;
			original[8]=6;

			original[15]=8;

			original[18]=9;
			original[21]=6;
			original[24]=1;
			original[25]=4;
			original[26]=5;

			original[30]=2;
			original[34]=8;
			original[35]=1;

			original[36]=2;
			original[38]=7;
			original[40]=9;
			original[42]=5;
			original[44]=4;

			original[45]=6;
			original[46]=5;
			original[50]=8;

			original[54]=1;
			original[55]=6;
			original[56]=4;
			original[59]=9;
			original[62]=3;

			original[65]=3;

			original[72]=8;
			original[75]=1;
			original[76]=3;
			original[78]=4;
			original[80]=7;	
			break;	
	}
	case 2:
	{
			original[2]=9;
			original[3]=5;
			original[5]=2;
			original[8]=4;

			original[9]=7;
			original[11]=4;
			original[12]=1;
			original[15]=6;

			original[18]=3;
			original[19]=5;
			original[21]=6;
			original[22]=9;
			original[24]=8;
			original[25]=2;


			original[29]=6;
			original[32]=7;
			original[34]=5;
			original[35]=3;

			original[45]=2;
			original[46]=8;
			original[48]=9;
			original[51]=7;

			original[55]=3;
			original[56]=2;
			original[58]=5;
			original[59]=1;
			original[61]=6;
			original[62]=8;

			original[65]=8;
			original[68]=9;
			original[69]=5;
			original[71]=1;

			original[72]=9;
			original[75]=3;
			original[77]=8;
			original[78]=4;
			break;
	}
	}
		return original;
	}

int* copySudoku(int* original)
{
	sudoku=(int*)calloc(81,sizeof(int));
	int i;
	for (i=0;i<=80;i++)
	sudoku[i]=original[i];
	return sudoku;
}

PINDICES* prohibitedIndicesf(int* original)
{
	prohibitedIndices=(PINDICES*)calloc(1,sizeof(PINDICES));
	prohibitedIndices->size=0;
	int i,j=0;
	for (i=0;i<=80;i++)
	{
		if(*(original+i)!=0)
		{
			prohibitedIndices->indices[j]=i;
			prohibitedIndices->size++;
			j++;
		}
	}
	return prohibitedIndices;
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
	rowBegin=(int)convertIndex(entry)/9;
	rowBegin=rowBegin*9;
	for (i=rowBegin;i<rowBegin+9;i++)
		{
			if (i!=convertIndex(entry))
			{
				if (*(sudoku+i)==entry->value)
				return 0;
			}
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
				if (convertIndex(element)!=convertIndex(entry))
				{
					if (*(sudoku+convertIndex(element))==entry->value)
					{
						free(element);
						return 0;
					}
									
				}
			}
		}
	free(element);
	return 1;
}


void updateSudoku (ENTRY* entry,PINDICES* prohibitedIndices)
{
	int i;
	for (i=0;i<prohibitedIndices->size;i++)
	{
		if (prohibitedIndices->indices[i]==convertIndex(entry))
		return;
	}
	*(sudoku+convertIndex(entry))=entry->value;
}













