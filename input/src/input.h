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
int* createSudoku(void);
ENTRY* createEntry(void);
int convertIndex(ENTRY*);
int isIndexValid(ENTRY*);
int isValueValid(ENTRY*);
int isEntryValid(ENTRY*);

#endif
