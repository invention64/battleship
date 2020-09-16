CFLAGS=-I. -L. -Wall #Local directory link flags
LDFLAGS=-lncurses
CC=gcc
DEPS = colors.h board.h gui.h
OBJ = battleship.o colors.o board.o gui.o

%.o: %.c %(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

all: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
