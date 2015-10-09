#ifndef _GUI_H
#define _GUI_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>
#include "../../input/src/input.h"
#include "../../logic/src/logic.h"

SDL_Surface* load_image( char*);
void apply_surface( int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*);
bool init(void);
bool load_files(void);
void clean_up(void);
int* numberPosition(ENTRY*);
int* boxPosition(ENTRY*);
void checkSudoku(void);
void newSudoku(void);
void clearSudoku(void);
void handleButtonEvent(ENTRY*);
void drawSudoku(void);
int handleInputNumber(void);

extern int* sudoku;
extern int* original;
extern PINDICES* prohibitedIndices;

#endif

