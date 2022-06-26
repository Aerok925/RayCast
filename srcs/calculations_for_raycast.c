/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_for_raycast.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:22:56 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:22:56 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incs/raycast.h"

void	first_calculate(t_math *math, t_img *player)
{
	math->raydirx = (double)player->dirx
		+ (double)player->planex * (double)math->camerax;
	math->raydiry = (double)player->diry
		+ (double)player->planey * (double)math->camerax;
	math->mapx = (int)player->posx;
	math->mapy = (int)player->posy;
	if (math->raydirx == 0)
		math->deltadistx = 1e30;
	else
		math->deltadistx = fabs(1 / math->raydirx);
	if (math->raydiry == 0)
		math->deltadisty = 1e30;
	else
		math->deltadisty = fabs(1 / math->raydiry);
	math->hit = 0;
}

void	found_step(t_math *math, t_img *player)
{
	if (math->raydirx < 0)
	{
		math->stepx = -1;
		math->sidedistx = (player->posx - math->mapx) * math->deltadistx;
	}
	else
	{
		math->stepx = 1;
		math->sidedistx = (math->mapx + 1.0 - player->posx) * math->deltadistx;
	}
	if (math->raydiry < 0)
	{
		math->stepy = -1;
		math->sidedisty = (player->posy - math->mapy) * math->deltadisty;
	}
	else
	{
		math->stepy = 1;
		math->sidedisty = (math->mapy + 1.0 - player->posy) * math->deltadisty;
	}
}

void	found_x_y_tex(t_math *math, t_img *player, t_win *win)
{
	if (math->side == 0)
		math->perpwalldist = (math->sidedistx - math->deltadistx);
	else
		math->perpwalldist = (math->sidedisty - math->deltadisty);
	math->lineheight = (int)(SCREENHEIGHT / math->perpwalldist);
	math->drawstart = -math->lineheight / 2 + SCREENHEIGHT / 2;
	if (math->drawstart < 0)
		math->drawstart = 0;
	math->drawend = math->lineheight / 2 + SCREENHEIGHT / 2;
	if (math->drawend >= SCREENHEIGHT)
		math->drawend = SCREENHEIGHT - 1;
	if (math->side == 0)
		math->wallx = player->posy + math->perpwalldist * math->raydiry;
	else
		math->wallx = player->posx + math->perpwalldist * math->raydirx;
	math->wallx -= floor((math->wallx));
	math->texx = (int)(math->wallx * (double)(win->w.width));
	if (math->side == 0 && math->raydirx > 0)
		math->texx = win->w.width - math->texx - 1;
	if (math->side == 1 && math->raydiry < 0)
		math->texx = win->w.width - math->texx - 1;
}

void	draw_sky_and_floor(t_win *win, t_math *math, int x)
{
	math->step = 1.0 * win->w.width / math->lineheight;
	math->texpos = (math->drawstart - SCREENHEIGHT / 2 + math->lineheight / 2)
		* math->step;
	win->line.x0 = x;
	win->line.x1 = x;
	win->line.y0 = -1;
	win->line.y1 = math->drawstart;
	win->line.color = win->maps->ceil_rgb;
	drawfullline(win, &win->line);
	win->line.y0 = math->drawend - 1;
	win->line.y1 = SCREENHEIGHT - 1;
	win->line.color = win->maps->floor_rgb;
	drawfullline(win, &win->line);
}

void	draw_textures(t_win *win, t_math *math, int x)
{
	int	y;

	y = math->drawstart;
	while (y < math->drawend)
	{
		math->texy = (int) math->texpos & (win->w.height - 1);
		math->texpos += math->step;
		if (math->side == 0 && math->raydirx >= 0)
			win->temp.buffer[x + y * SCREENWIDTH] = win->s.buffer[win->s.width
				* math->texy + math->texx];
		else if (math->side == 0 && math->raydirx < 0)
			win->temp.buffer[x + y * SCREENWIDTH] = win->n.buffer[win->n.width
				* math->texy + math->texx];
		else if (math->side == 1 && math->raydiry < 0)
			win->temp.buffer[x + y * SCREENWIDTH] = win->w.buffer[win->w.width
				* math->texy + math->texx];
		else if (math->side == 1 && math->raydiry >= 0)
			win->temp.buffer[x + y * SCREENWIDTH] = win->e.buffer[win->e.width
				* math->texy + math->texx];
		y++;
	}
}
