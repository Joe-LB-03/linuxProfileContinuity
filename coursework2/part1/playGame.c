#include <stdio.h>
#include <ctype.h>

#include "game.h"
#include "playGame.h"
#include "endGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) 
{
    char symbols[2] = { 'X','O' };
    
    // player 'X' plays first
    int player = 0;

    // starting board
    printf("New game starting\n");
    showGame( game );
    int moveGood;
  
    // Your game should be controlled by an outer loop
    // Each pass through the loop is one completed move by a player
    while(1)
    {
        printf("Player %c: Enter your move as row column values:\n",symbols[player]); // use this to request the player move
        int x,y;
        
        // Request a move from the next player and check it is valid (an unused square within the board)
        do
        {
            while(inputHandler(&x,&y) == 0)
            {
                // If the move is invalid you should repeat the request for the current player
                printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move
                printf("Player %c: Enter your move as row column values:\n",symbols[player]); // use this to request the player move
            }
            moveGood = makeMove(game,symbols[player],x,y); // If the move is valid update the board
            if(moveGood == 0)
            {
                printf("Move rejected. Please try again\n");
            }
        } while ( moveGood == 0 );
        
        // After each completed move display the board 
        showGame( game );
        game->turns++;

        // After each valid move you can test for win or draw using functions you implement in endGame.c
        if(winGame(game,symbols[player],x,y))
        {
            printf("Player %c has won\n",symbols[player]); // use to announce a winner - game is over
            return;
        }
        if(drawGame(game))
        {
            printf("Match is drawn\n"); // use to announce a draw - game is over
            return;
        }
        if(player == 0)
        {
            player = 1;
        }
        else
        {
            player = 0;
        }
    }
    return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) 
{
    int i,j;
    printf("\n");

    printf("    ");
    for(i = 0; i < game->boardSize; i++)
    {
        printf("  %d",i);
    }
    printf("\n");

    printf("\n");

    for(i = 0; i < game->boardSize; i++)
    {
        printf(" %d  ",i);
        for(j = 0; j < game->boardSize; j++)
        {
            printf("  %c",game->board[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove( Game *game, char symbol, int x, int y ) 
{
    // read the players move from the keyboard, expected as two integers coordinates as shown on the board 
    if(game->board[x][y] == '.') // test that the chosen location is a valid empty space
    {
        // if we accept then update the board and return 1
        game->board[x][y] = symbol;
        return 1;
    }
    else
    {
        return 0; // if we do not accept the move return 0
    }
    return 1; // move accepted
}

int inputHandler(int* x, int* y) // function to validate input
{
    char str[100] = {0};
    int digits = 0;
    fflush(stdin);
    fgets(str, 100, stdin);

    for(int i = 0; i < 100; i++)
    {
        if(isdigit(str[i]))
        {
            digits++;
        }
        if(!isdigit(str[i]) && (!isspace(str[i])) && (str[i] != '\0'))
        {
            if(((i != 0) && (str[i - 1] != ' ')) || (str[i] == ' ' && str[i-1] == ' '))
            {
                return 0; //input rejected
            }
        }

        if((str[i] == '\n') || (str[i] == '\0'))
        {
            break; //if we hit a newline or terminating character then break
        }
    }

    if(digits != 2)
    {
        return 0; //input rejected
    }

    sscanf(str, "%d%d", x, y);
    return 1; //input accepted
}