#ifndef HEADER_BOARD
#define HEADER_BOARD

enum pieces { NONE, BOAT, HIT, MISS };
void drawBoard(int ** board);
int ** allocBoard();

#endif
