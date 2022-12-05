#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"

/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) 
{
    if(argc != 3)
    {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return 0;
    }
    
    Game *game; // pointer for the game structure

    // allocate memory and assign starting values to the structure
    game = initGame(atoi(argv[1]),atoi(argv[2]));
    if ( game == NULL )
    {
        return 0;
    }
    
    playGame(game); // play a full game

    free(game); // free heap memory that was used

    return 0; //end
}

