/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:24:08 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:24:08 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minimap_bonus.h"

void	create_mini_wall(t_win *win)
{
	int	y;
	int	x;

	win->map.wall.width = WIDTH_MINI;
	win->map.wall.height = WIDTH_MINI;
	win->map.wall.img = mlx_new_image(win->mlx,
			win->map.wall.width, win->map.wall.height);
	win->map.wall.buffer = (int *)mlx_get_data_addr(win->map.wall.img,
			&win->map.wall.pixel_bits,
			&win->map.wall.line_bytes, &win->map.wall.endian);
	y = 0;
	while (y < win->map.wall.height)
	{
		x = 0;
		while (x < win->map.wall.width)
		{
			if (y == WIDTH_MINI - 1 || x == WIDTH_MINI - 1)
				win->map.wall.buffer[x + y * win->map.wall.width] = DARKGREEN;
			else
				win->map.wall.buffer[x + y * win->map.wall.width] = INDIANRED;
			x++;
		}
		y++;
	}
}

void	create_mini_floor(t_win *win)
{
	int	y;
	int	x;

	win->map.floor.width = WIDTH_MINI;
	win->map.floor.height = WIDTH_MINI;
	win->map.floor.img = mlx_new_image(win->mlx, win->map.floor.width,
			win->map.floor.height);
	win->map.floor.buffer = (int *)mlx_get_data_addr(win->map.floor.img,
			&win->map.floor.pixel_bits, &win->map.floor.line_bytes,
			&win->map.floor.endian);
	y = 0;
	while (y < win->map.floor.height)
	{
		x = 0;
		while (x < win->map.floor.width)
		{
			win->map.floor.buffer[x + y * win->map.floor.width] = RED;
			x++;
		}
		y++;
	}
}

void	create_mini_transparent(t_win *win)
{
	int	x;
	int	y;

	win->map.transparent.width = WIDTH_MINI;
	win->map.transparent.height = WIDTH_MINI;
	win->map.transparent.img = mlx_new_image(win->mlx,
			win->map.transparent.width,
			win->map.transparent.height);
	win->map.transparent.buffer = (int *)mlx_get_data_addr(
			win->map.transparent.img,
			&win->map.transparent.pixel_bits, &win->map.transparent.line_bytes,
			&win->map.transparent.endian);
	y = 0;
	while (y < win->map.floor.height)
	{
		x = 0;
		while (x < win->map.floor.width)
		{
			win->map.transparent.buffer[x + y * win->map.transparent.width]
				= TRANSPARENT;
			x++;
		}
		y++;
	}
}

void	init_miniminimap(t_win *win)
{
	win->map.minimap.width = WIDHT_MINIMAP_STATIC * WIDTH_MINI;
	win->map.minimap.height = WIDHT_MINIMAP_STATIC * WIDTH_MINI;
	win->map.minimap.img = mlx_new_image(win->mlx,
			win->map.minimap.width, win->map.minimap.height);
	win->map.minimap.buffer = (int *) mlx_get_data_addr(win->map.minimap.img,
			&win->map.minimap.line_bytes, &win->map.minimap.pixel_bits,
			&win->map.minimap.endian);
}

void	draw_minimini_part2(t_win	*win, int *xy)
{
	if (xy[1] < 0 || xy[0] < 0)
		setimgtotemplate(&win->map.minimap,
			&win->map.transparent, xy[3], xy[2]);
	else if (xy[1] >= win->maps->width || xy[0] >= win->maps->height)
		setimgtotemplate(&win->map.minimap,
			&win->map.transparent, xy[3], xy[2]);
	else if (win->maps->all_map[xy[0]][xy[1]] == '1')
		setimgtotemplate(&win->map.minimap,
			&win->map.wall, xy[3], xy[2]);
	else if (win->maps->all_map[xy[0]][xy[1]] == '0')
		setimgtotemplate(&win->map.minimap,
			&win->map.floor, xy[3], xy[2]);
	else
		setimgtotemplate(&win->map.minimap,
			&win->map.transparent, xy[3], xy[2]);
}
