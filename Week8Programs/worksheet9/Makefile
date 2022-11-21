
# code details

EXE = ./linkedList
SRC = main.c create.c add.c traverse.c 
OBJ = main.o create.o add.o traverse.o

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

main.o:        main.c     linkedList.h create.h add.h traverse.h
create.o:      create.c   linkedList.h create.h 
add.o:         add.c      linkedList.h add.h 
traverse.o:    traverse.c linkedList.h traverse.h create.h

