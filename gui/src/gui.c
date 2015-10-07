/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//Include SDL functions and datatypes
#include "gui.h"


//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BPP = 32;

//Control Buttons Borders

const int CONTROL_UPPER_BOUND = 522;
const int BOX_DIMENSION = 54;
//const int CONTROL_DOWN = 202;
const int CLEAR = 162;
const int NEW = 324;


//The surfaces
SDL_Surface* background = NULL;
SDL_Surface* number = NULL;
SDL_Surface* screen = NULL;
//ENTRY* entry;

SDL_Event event;

TTF_Font* font = NULL;
SDL_Color textColor = {0 , 0,  0 };
static int* sudoku;
static int* original;

SDL_Surface *load_image( char* filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load(filename);

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );/// OVO NE KONTAM!!!!!!!!
        }
    }

    //Return the optimized image
    return optimizedImage;
}


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
	
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}




int* numberPosition(ENTRY* entry)
{
	int* position=malloc(2*sizeof(int));
	position[0]=(entry->x-1)*BOX_DIMENSION+15;
	position[1]=(entry->y-1)*BOX_DIMENSION;
	return position;
}



bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
		printf ("Greska pri inicijalizaciji");
        //return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
	printf ("Greska pri setupu screena");
       // return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
	printf ("Greska pri setupu screena");
        //return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Sudoku", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the background image
    background = load_image( "../../resources/sudoku_button.bmp" );

    //Open the font
    font = TTF_OpenFont( "../../resources/mytype.ttf", 40 ); 

    //If there was a problem in loading the background
    if( background == NULL )
    {
	printf ("Greska pri setupu backgrounda");
    //    return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
	printf ("Greska pri setupu fonta");
      //  return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( number );

    //Close the font that was used
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

void checkSudoku(void)
{ 
	ENTRY* entry=malloc(sizeof(ENTRY*));
	int i, j, index;
	for (i=1;i<10;i++)
	{
		for (j=1;i<10;i++)
		{
			entry->x=i;
			entry->y=j;
			index=convertIndex(entry);
			entry->value=*(sudoku+index);
			if (!(isColumnfree(sudoku, entry) && isRowfree(sudoku, entry) && isBoxfree(sudoku, entry)))
				printf("Something is wrong\n");
		}
	}
	printf("Everything is OK\n");
//printf("Check Sudoku\n");
}

	
void newSudoku(void) // OVA FUNKCIJA MI NI NE TREBA, MOZDA SAMO ZBOG POINTERA NA FUNKCIJU jer je funkcija u drugom .c fajlu?! kako to realizovati  
{
	sudoku=generateSudoku();
	//printf("New Sudoku\n");
}



void clearSudoku(void)
{
	sudoku=copySudoku(original);
	//printf("Clear Sudoku\n");
}


void handleButtonEvent()
{
	int x,y;
	void (*fptr[3])(void) = {&checkSudoku, &clearSudoku, &newSudoku };
	if( event.type == SDL_MOUSEBUTTONDOWN ) // if the mousebutton was pressed
	{
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;
			
            //If the mouse is over the button
            if (y>CONTROL_UPPER_BOUND)
			{
				if (x>NEW)
					fptr[0]();
				else 
				{
					if (x>CLEAR)
						fptr[1]();
					else
						fptr[2]();
				}
			}
		}
	}
}


void drawSudoku(void)
{
	int i,j,value,index;
	//SDL_Surface* number=NULL;
	char a[2];
	int* position;
	ENTRY* entry=malloc(sizeof(ENTRY));
	apply_surface(0,0, background, screen, NULL );	
	for (i=1;i<10;i++)
		{
			for (j=1;j<10;j++)
			{
				entry->x=i;
				entry->y=j;
				index=convertIndex(entry);
				entry->value=*(sudoku+index);
				//itoa(entry->value, a, 10);
				sprintf(a,"%d",entry->value);
				if (entry->value!=0)
				{ 
					number = TTF_RenderText_Solid( font, a, textColor);
					if( number == NULL )
		    			printf("Number not read correctly\n");
					position=numberPosition(entry);
					apply_surface(position[0],position[1], number, screen, NULL );
				}
			}			
		}
}



				
int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;
    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }
	original=generateSudoku();
	sudoku=copySudoku(original);
	//draw Sudoku
	drawSudoku();
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
			handleButtonEvent();
			drawSudoku();
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
    }

    //Free surfaces and font then quit SDL_ttf and SDL
    clean_up();


    return 0;
}








