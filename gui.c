#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "colors.h"

int end_game(int code) {
	clear();
	endwin();
	exit(code);
}

int * create_pipe() {
	int * pfds;
	pfds = malloc(sizeof(int)*2);
	if (pipe(pfds) == -1) {
		perror("pipe");
		end_game(1);
	}
	return pfds;
}

int * start_menu() {
	int fg, bg;
	fg = COLOR_BLACK;
	int selected = 0;
	while (true) {
		bg = (selected) ? (COLOR_WHITE) : (COLOR_RED);
		attron(COLOR_PAIR(colornum(fg, bg)));
		mvaddstr(LINES/2,COLS/2," Create Game ");
		bg = (selected) ? (COLOR_RED) : (COLOR_WHITE);
		attron(COLOR_PAIR(colornum(fg, bg)));
		mvaddstr(LINES/2 + 2, COLS/2, " Join Game  ");
		refresh();

		int key = getch();
		if (key == 's') {
			selected = 1;
		}
		else if (key == 'w') {
			selected = 0;
		}
		else if (key == 27) { end_game(0); }
		else if (key == ' ') { break; }
	}
	attron(COLOR_PAIR(colornum(COLOR_WHITE, COLOR_BLACK)));
	clear();
	refresh();
	return create_pipe();
}
