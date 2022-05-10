//
// Created by John Nappa on 5/10/22.
//

#ifndef QWE_RAYCAST_H
#define QWE_RAYCAST_H

#include "math.h"
#include "s_win.h"
#include "all_define.h"
#include "draw_line.h"

typedef struct s_math{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	perpWallDist;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		drawStart;
	int		drawEnd;
	double	wallX;
	int		texX;
	double	step;
	double	texPos;
	int		texY;
	int		lineHeight;
	int		lineWidth;
}	t_math;

void	first_calculate(t_math *math, t_img *player);
void	found_step(t_math *math, t_img *player);
void	found_x_y_tex(t_math *math, t_img *player, t_win *win);
void	draw_sky_and_floor(t_win *win, t_math *math, int x);
void	draw_textures(t_win *win, t_math *math, int x);
void	check_dist(t_math *math);
#endif //QWE_RAYCAST_H
