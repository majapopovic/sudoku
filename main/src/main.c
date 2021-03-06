#include "main.h"


//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface* background = NULL;
SDL_Surface* number = NULL;
SDL_Surface* screen = NULL;
//ENTRY* entry;

SDL_Event event;

TTF_Font* font = NULL;
SDL_Color textColor = {0 , 0, 0 };

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




int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;
	///////////int position[2];
    //Initialize
    if( init() == false )
    {
printf("init los");
        //return 1;
    }

    //Load the files
    if( load_files() == false )
    {
	printf("Load los");
//        return 1;
    }
	//entry=createEntry2(1,1,5);
    //Render the text
    number = TTF_RenderText_Solid( font, "9", textColor );

    //If there was an error in rendering the text
    if( number == NULL )
    {
	printf("tekst los");
        //return 1;
    }
	//////////////position=numberPosition(entry);
    //Apply the images to the screen
    apply_surface( 0, 0, background, screen, NULL );
    apply_surface( 123, 54, number, screen, NULL );

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
	printf("Flip los");
        //return 1;
    }

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
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

