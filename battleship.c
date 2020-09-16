/* battleship.c */
/* James Gottshall - 9/4/20 */
#include <curses.h>
#include <stdlib.h>

enum pieces { NONE, BOAT, HIT, MISS };

void drawBoard(int board[8][8]) {
	for (int i=0; i<8; i++) {
		for (int j=0; i<8; j++){
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

int main(char ** args)
{
	int board[8][8], opponentBoard[8][8] = {0};
	// Ships: Carrier, Battleship, Destroyer, Submarine, and Patrol Boat
	int ships[] = {5,4,3,3,2};
	int maxlines, maxcols;
	bool gameover = false;

	// ncurses initialization
	initscr();
	cbreak();
	noecho();

	clear();

	maxlines = LINES - 1;
	maxcols = COLS - 1;

	// Main Game Loop
	/*
	while (!gameover) {
		
	}
	*/
	mvaddstr(2, 12, "Drawn");
	drawBoard(board);
	
	
	// Cleanup
	mvaddstr(maxlines, 0, "Press any key to quit");
	refresh();
	getch(); // Yeet Get Char
	endwin();

	exit(0);
}
