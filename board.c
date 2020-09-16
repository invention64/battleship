#include <ncurses.h>
#include <stdlib.h>
#include "board.h"

void drawBoard(int ** board) {
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++){
			char temp;
			switch (board[i][j]) {
				case NONE:
					temp = ' ';
					break;
				case BOAT:
					temp = '#';
					break;
				case HIT:
					temp = 'X';
					break;
				case MISS:
					temp = 'O';
					break;
				default:
					temp = '?';	
			}
			mvaddch(i + 2, j + 2, temp); 
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
