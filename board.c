#include <ncurses.h>
#include <stdlib.h>
#include "board.h"
#include "colors.h"

void drawBoard(int ** board) {
	char head = 'A';
	// Draw Heading
	for (int i=0; i<8; i++) {
		mvaddch(1, i*2 + 2, head+i);
		mvprintw(i*2 + 2, 1, "%d", i + 1);
	}
	
	// fg and bg temp vars
	int fg, bg;
	fg = 7;
	bg = 1;
	// Draw Board
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++){
			char temp;
			switch (board[i][j]) {
				case NONE:
					temp = ' ';
					break;
				case BOAT:
					temp = '#';
					bg = 0;
					fg = 7;
					break;
				case HIT:
					temp = 'O';
					fg = 4;
					break;
				case MISS:
					temp = 'O';
					fg = 7;
					break;
				default:
					temp = '?';
			}
			setcolor(fg, bg);
			mvaddch(j*2 + 2, i*2 + 2, temp); 
			unsetcolor(fg, bg);
		}
	}
	refresh();
}

int ** allocBoard() {
	int ** newBoard = (int **)malloc(sizeof(int*)*8);
	for (int i=0; i < 8; i++) {
		newBoard[i] = (int *)malloc(sizeof(int)*8);
		for (int j=0; j < 8; j++) {
			newBoard[i][j] = NONE;
		}
	}
	return newBoard;
}
