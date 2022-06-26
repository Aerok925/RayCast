/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:24:12 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:24:12 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/draw_all.h"
#include "../mlx123/mlx.h"
#include <math.h>

void	mouse_init(t_win *win)
{
	mlx_mouse_get_pos(win->win, &win->mouse.x, &win->mouse.y);
	win->mouse.rotspeed = 0.025;
}

void	mouse_left(int x, int y, t_win *win)
{
	int		tempx;
	double	olddirx;
	double	oldplanex;

	mlx_mouse_move(win->win, SCREENWIDTH / 2, 0);
	mlx_mouse_hide();
	(void)y;
	olddirx = win->player.dirx;
	oldplanex = win->player.planex;
	tempx = SCREENWIDTH / 2;
	if (tempx < x)
	{
		win->player.dirx = win->player.dirx * cos(-win->mouse.rotspeed)
			- win->player.diry * sin(-win->mouse.rotspeed);
		win->player.diry = olddirx * sin(-win->mouse.rotspeed)
			+ win->player.diry * cos(-win->mouse.rotspeed);
		win->player.planex = win->player.planex * cos(-win->mouse.rotspeed)
			- win->player.planey * sin(-win->mouse.rotspeed);
		win->player.planey = oldplanex * sin(-win->mouse.rotspeed)
			+ win->player.planey * cos(-win->mouse.rotspeed);
	}
}

int	ft_mouse(int x, int y, t_win *win)
{
	int		tempx;
	double	olddirx;
	double	oldplanex;

	mlx_mouse_move(win->win, SCREENWIDTH / 2, 0);
	mlx_mouse_hide();
	olddirx = win->player.dirx;
	oldplanex = win->player.planex;
	tempx = SCREENWIDTH / 2;
	mouse_left(x, y, win);
	if (tempx > x)
	{
		win->player.dirx = win->player.dirx * cos(win->mouse.rotspeed)
			- win->player.diry * sin(win->mouse.rotspeed);
		win->player.diry = olddirx * sin(win->mouse.rotspeed)
			+ win->player.diry * cos(win->mouse.rotspeed);
		win->player.planex = win->player.planex * cos(win->mouse.rotspeed)
			- win->player.planey * sin(win->mouse.rotspeed);
		win->player.planey = oldplanex * sin(win->mouse.rotspeed)
			+ win->player.planey * cos(win->mouse.rotspeed);
	}
	win->mouse.x = x;
	drawall(win);
	return (0);
}
