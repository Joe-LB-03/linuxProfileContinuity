#include <stdio.h>

#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol, int x, int y ) 
{
    if(checkVertical(game, x,y,symbol))
    {
        return 1;
    }
    if(checkHorizontal(game, x,y,symbol))
    {
        return 1;
    }
    if(checkDiagonalDownRight(game, x,y,symbol))
    {
        return 1;
    }
    if(checkDiagonalDownLeft(game, x,y,symbol))
    {
        return 1;
    }
    return 0;  // continue
}

// test for a draw
int drawGame( Game *game ) 
{
    // return 1(true) if game is drawn, 0(false) otherwise
    if(game->turns == game->maxTurns)
    {
        return 1;
    }
    return 0; // continue
}

// check for a win vertically
int checkVertical(Game *game, int x, int y, char symbol)
{
    int i;
    int count = 0;
    for(i = 0; i < game->boardSize; i++)
    {
        if(game->board[i][y] == symbol)
        {
            count++;
        }
    }
    if(count >= game->winLength)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// check for a win horizontally
int checkHorizontal(Game *game, int x, int y, char symbol)
{
    int i;
    int count = 0;
    for(i = 0; i < game->boardSize; i++)
    {
        if(game->board[x][i] == symbol)
        {
            count++;
        }
    }
    if(count >= game->winLength)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// check for a win in the diagonal right direction
int checkDiagonalDownRight(Game *game, int x, int y, char symbol)
{
    int count, basex, basey;
    basex = x;
    basey = y;
    count = 0;
    while(basex > 0 && basey > 0)
    {
        basex = basex -1;
        basey = basey -1;
    }

    while(basex < game->boardSize && basey<game->boardSize)
    {
        if(game->board[basex][basey] == symbol)
        {
            count++;
            if(count >= game->winLength)
            {
            return 1;
            }
        }
        else
        {
            count = 0;
        }
        basex++;
        basey++;
    }
    if(count >= game->winLength)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// check for a win in the diagonal left direction
int checkDiagonalDownLeft(Game *game, int x, int y, char symbol)
{
    int count, basex, basey;
    basex = x;
    basey = y;
    count = 0;
    while(basex > 0 && basey < game->boardSize)
    {
        basex = basex -1;
        basey = basey +1;
    }

    while(basex < game->boardSize && basey>0)
    {
        if(game->board[basex][basey] == symbol)
        {
            count++;
            if(count >= game->winLength)
            {
                return 1;
            }
        }
        else
        {
            count = 0;
        }
        basex++;
        basey = basey - 1;
    }
    if(count >= game->winLength)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}