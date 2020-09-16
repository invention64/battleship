/* battleship.c */
/* James Gottshall - 9/4/20 */
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "board.h"
#include "gui.h"

int main(int argc, char ** args)
{
	// Allocate Boards
	int ** board = allocBoard();
	int ** opponentBoard = allocBoard();

	// Ships: Carrier, Battleship, Destroyer, Submarine, and Patrol Boat
	int ships[] = {5,4,3,3,2};
	int maxlines, maxcols;
	bool gameover = false;

	// ncurses initialization
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE); // Sets keypad mode to true for the standard screen
	refresh(); // First refresh after init clears screen

	// initialize  colors
	if (has_colors() == FALSE) {
		endwin();
		puts("Your terminal does not support color");
		exit(1);
	}
	start_color();
	init_colorpairs();
	
	// Set maxlines and maxcols variables
	maxlines = LINES - 1;
	maxcols = COLS - 1;

	// Show start menu
	int * pipe_file = start_menu();
	
	mvprintw(2,2, "Read: %d", pipe_file[0]);
	mvprintw(3,2, "Write: %d", pipe_file[1]);
	mvaddstr(5,2, "Press Any Key to Continue");
	refresh();
	int ch = getch(); // Wait until user presses a key
	usleep(200);

	// Main Game Loop
	/*
	while (!gameover) {
		
	}
	*/
	clear();
	refresh();

	mvaddstr(0, maxcols/2, "Drawn");
	drawBoard(board);
	
	// Cleanup
	mvaddstr(maxlines, 0, "Press any key to quit");
	refresh();
	ch = getch(); // Yeet Get Char
	endwin();

	exit(0);
}
