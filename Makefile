CFLAGS=-I. -L. #Local directory link flags
LDFLAGS=-lncurses
CC=gcc
DEPS = 
OBJ = battleship.o

%.o: %.c %(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

all: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
