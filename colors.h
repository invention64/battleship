#ifndef HEADER_COLOR
#define HEADER_COLOR
void init_colorpairs(void);
short curs_color(int fg);
int colornum(int fg, int bg);
void setcolor(int fg, int bg);
void unsetcolor(int fg, int bg);
#endif
