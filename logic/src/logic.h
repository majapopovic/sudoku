#ifndef _LOGIC_H
#define _LOGIC_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../../input/src/input.h"

typedef struct pindices
{
int indices [81];
int size;
} PINDICES;

int* generateSudoku (int);
//void generateSudoku (int);
int isEmpty (int*, ENTRY*);
int isColumnfree (int*, ENTRY*);
int isRowfree (int*, ENTRY*);
int isBoxfree (int*, ENTRY*);
void updateSudoku (ENTRY*, PINDICES*);
int* copySudoku(int*);
//void copySudoku(void);
PINDICES* prohibitedIndicesf(int*);



#endif
