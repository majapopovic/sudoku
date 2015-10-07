#ifndef _LOGIC_H
#define _LOGIC_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../../input/src/input.h"

int* generateSudoku (void);
int isEmpty (int*, ENTRY*);
int isColumnfree (int*, ENTRY*);
int isRowfree (int*, ENTRY*);
int isBoxfree (int*, ENTRY*);
void updateSudoku (int*, ENTRY*);
int* copySudoku(int*);
int* prohibitedIndices(int*);

#endif
