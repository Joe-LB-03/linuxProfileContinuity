
#include <stdio.h>

#include "game.h"
#include "playGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) {

  char symbols[2] = { 'X','O' };
  // player 'X' plays first
  int player = 0;

  // starting board
  printf("New game starting\n");
  showGame( game );
  
  // Your game should be controlled by an outer loop
  // Each pass through the loop is one completed move by a player
  
   
  // Request a move from the next player and check it is valid (an unused square within the board)
  printf("Player %c: Enter your move as row column values:\n",symbols[player]); // use this to request the player move

  // If the move is invalid you should repeat the request for the current player
  printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move

  // If the move is valid update the board
  
  // After each completed move display the board 
  showGame( game );

  // After each valid move you can test for win or draw using functions you implement in endGame.c
  printf("Player %c has won\n",symbols[player]); // use to announce a winner - game is over
  printf("Match is drawn\n"); // use to announce a draw - game is over
 
  return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {

  printf("\n");
  printf("      0  1  2\n");
  printf("\n");
  printf(" 0    %c  %c  %c\n",game->board[0][0],game->board[0][1],game->board[0][2]);
  printf(" 1    %c  %c  %c\n",game->board[1][0],game->board[1][1],game->board[1][2]);
  printf(" 2    %c  %c  %c\n",game->board[2][0],game->board[2][1],game->board[2][2]);
  printf("\n");

  return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove( Game *game, char symbol ) {

  // read the players move from the keyboard, expected as two integers coordinates as shown on the board 

  // test that the chosen location is a valid empty space
  // if we do not accept the move return 0

  // if we accept then update the board and return 1

  return 1; // move accepted
}

