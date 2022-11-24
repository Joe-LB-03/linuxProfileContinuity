
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) 
{
    Game *game;
    int i,j;
    // for incorrect boardSize or winLength you should return a NULL pointer
    if(boardSize < 3 || boardSize > 8 || winLength < 3 || winLength > boardSize)
    {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return NULL;
    }
    // allocate the Game data structure
    game = (Game *)malloc(sizeof(Game) + (sizeof(char)*boardSize*boardSize));
    createArray(game);

    // intialise the Game data structure values 
    game->boardSize = boardSize;
    game->winLength = winLength;

    // board values should be set to '.' (unused location)
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardSize;j++)
        {
            game->board[i][j] = '.';
            
        }
    }
    return game;
}

void createArray(Game *game)
{
    int i;
    char* array[game->boardSize];
    for(i=0;i<game->boardSize;i++)
    {
        array[i] = (char*)malloc(sizeof(char)*game->winLength);   
    }

    game->board = array;
}
