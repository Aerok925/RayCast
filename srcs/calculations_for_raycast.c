#include"../incs/raycast.h"

void first_calculate(t_math *math, t_img *player)
{
	math->rayDirX = (double)player->dirX + (double)player->planeX * (double)math->cameraX;
	math->rayDirY = (double)player->dirY + (double)player->planeY * (double)math->cameraX;
	math->mapX = (int)player->posX;
	math->mapY = (int)player->posY;
	if (math->rayDirX == 0)
		math->deltaDistX = 1e30;
	else
		math->deltaDistX = fabs(1 / math->rayDirX);
	if (math->rayDirY == 0)
		math->deltaDistY = 1e30;
	else
		math->deltaDistY = fabs(1 / math->rayDirY);
	math->hit = 0;
}

void found_step(t_math *math, t_img *player)
{
	if(math->rayDirX < 0)
	{
		math->stepX = -1;
		math->sideDistX = (player->posX - math->mapX) * math->deltaDistX;
	}
	else
	{
		math->stepX = 1;
		math->sideDistX = (math->mapX + 1.0 - player->posX) * math->deltaDistX;
	}
	if(math->rayDirY < 0)
	{
		math->stepY = -1;
		math->sideDistY = (player->posY - math->mapY) * math->deltaDistY;
	}
	else
	{
		math->stepY = 1;
		math->sideDistY = (math->mapY + 1.0 - player->posY) * math->deltaDistY;
	}
}

void found_x_y_tex(t_math *math, t_img *player, t_win *win)
{
	if(math->side == 0)
		math->perpWallDist = (math->sideDistX - math->deltaDistX);
	else
		math->perpWallDist = (math->sideDistY - math->deltaDistY);
	math->lineHeight = (int)(screenHeight / math->perpWallDist);
	math->drawStart = -math->lineHeight / 2 + screenHeight / 2;
	if(math->drawStart < 0)
		math->drawStart = 0;
	math->drawEnd = math->lineHeight / 2 + screenHeight / 2;
	if(math->drawEnd >= screenHeight)
		math->drawEnd = screenHeight - 1;
	if(math->side == 0)
		math->wallX = player->posY + math->perpWallDist * math->rayDirY;
	else
		math->wallX = player->posX + math->perpWallDist * math->rayDirX;
	math->wallX -= floor((math->wallX));
	math->texX = (int)(math->wallX * (double)(win->W.width));
	if(math->side == 0 && math->rayDirX > 0)
		math->texX = win->W.width - math->texX - 1;
	if(math->side == 1 && math->rayDirY < 0)
		math->texX = win->W.width - math->texX - 1;
}

void draw_sky_and_floor(t_win *win, t_math *math, int x)
{
	math->step = 1.0 * win->W.width / math->lineHeight;
	math->texPos = (math->drawStart - screenHeight / 2 + math->lineHeight / 2) * math->step;
	//sky
	win->line.x0 = x;
	win->line.x1 = x;
	win->line.y0 = 0;
	win->line.y1 = math->drawStart;
	win->line.color = SKY;
	drawfullline(win, &win->line);
	//floor
	win->line.y0 = math->drawEnd - 1;
	win->line.y1 = screenHeight - 1;
	win->line.color = FLOOR;
	drawfullline(win, &win->line);
}

void draw_textures(t_win *win, t_math *math, int x)
{
	for (int y = math->drawStart; y < math->drawEnd; y++) {
		math->texY = (int) math->texPos & (win->W.height - 1);
		math->texPos += math->step;
		if (math->side == 0 && math->rayDirX >= 0)
			win->temp.buffer[x + y * screenWidth] = win->S.buffer[win->S.width * math->texY + math->texX];
		else if (math->side == 0 && math->rayDirX < 0)
			win->temp.buffer[x + y * screenWidth] = win->N.buffer[win->N.width * math->texY + math->texX];
		else if (math->side == 1 && math->rayDirY < 0)
			win->temp.buffer[x + y * screenWidth] = win->W.buffer[win->W.width * math->texY + math->texX];
		else if (math->side == 1 && math->rayDirY >= 0)
			win->temp.buffer[x + y * screenWidth] = win->E.buffer[win->E.width * math->texY + math->texX];
	}
}

void check_dist(t_math *math)
{
	if(math->sideDistX < math->sideDistY)
	{
		math->sideDistX += math->deltaDistX;
		math->mapX += math->stepX;
		math->side = 0;
	}
	else
	{
		math->sideDistY +=math->deltaDistY;
		math->mapY += math->stepY;
		math->side = 1;
	}
}
