#ifndef _GUI_H
#define _GUI_H
//#include <SDL/SDL.h>
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
void checkSudoku(void);
void newSudoku(void);
void clearSudoku(void);
void handleButtonEvent(void);
void drawSudoku(void);

/*typedef struct Button
{
	int top_left;
	int top_right;
	int bottom_left;
	int bottom_right;
}Button;*/

#endif

