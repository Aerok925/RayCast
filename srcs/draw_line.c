#include "../incs/draw_line.h"

void drawfullline(t_win *win, t_line *line)
{
	int x_err = 0, y_err = 0;
	int dx = line->x1 - line->x0; int dy = line->y1 - line->y0; //px/py - начальные точки x1/y1 конечные
	int incX = 0; int incY = 0;
	if (dx>0) {incX=1; }else if (dx!=0) incX=-1;
	if (dy>0) {incY=1; }else if (dy!=0) incY=-1;
	dx = abs(dx);
	dy = abs(dy);
	int d;
	if (dx > dy)
		d = dx;
	else
		d = dy;
	float x = (float)line->x0;
	float y = (float)line->y0;
	for (int i = 1; i <= d; i++){
		x_err +=dx;
		y_err += dy;
		if (x_err>=d)
		{
			x+=incX;
			x_err-=d;
		}
		if (y_err >= d){
			y+=incY;
			y_err-=d;
		}
		win->temp.buffer[(int)x + (int)y * screenWidth] = line->color;
	}
}
