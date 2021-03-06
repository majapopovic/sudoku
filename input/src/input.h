#ifndef _INPUT_H
#define _INPUT_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct entry
{
int x;
int y;
int value;
} ENTRY;


void assignXCoordinate(ENTRY*);
void assignYCoordinate(ENTRY*);
void assignValue(ENTRY*);
//int* createSudoku(void);
ENTRY* createEntry1(void);
ENTRY* createEntry2(int, int, int);
int convertIndex(ENTRY*);
int isIndexValid(ENTRY*);
int isValueValid(ENTRY*);
int isEntryValid(ENTRY*);

#endif
