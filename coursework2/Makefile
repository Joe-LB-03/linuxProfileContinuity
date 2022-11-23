
# code details

EXE = ./bin/tictactoe
SRC = endGame.c initGame.c main.c playGame.c  # ** list source code here **
OBJ = endGame.h game.h initGame.h playGame.h  # ** list object code here **

# generic build details

CC     = gcc
CFLAGS = -std=c99 -Wall
CLIBS  = 
CLINK  = 

# compile to object code

%.o: %.c
	$(CC) -c $(CFLAGS) $(CLIBS) $< -o $@

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

#
# ** put code dependencies here **
#
