#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"

/*
 * main function: program entry point
 */

int main( void ) 
{
    
    Game *game; // pointer for the game structure

    // allocate memory and assign starting values to the structure
    game = initGame(3,3);
    if ( game == NULL )
    {
        return 0;
    }
    
    playGame(game); // play a full game

    free(game); // free heap memory that was used

    return 0; //end
}