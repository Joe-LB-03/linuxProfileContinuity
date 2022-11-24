
# code details

EXE = ./bin/tictactoe
SRC = main.c endGame.c initGame.c playGame.c  # ** list source code here **
OBJ = main.o endGame.o initGame.o playGame.o  # ** list object code here **

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

main.o:		main.c game.h initGame.h initGame.c playGame.h playGame.c
initGame.o: initGame.c game.h initGame.h 
playGame.o: playGame.c game.h playGame.h endGame.h endGame.c
endGame.o:	endGame.c game.h endGame.h