/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_mini_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:24:03 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:24:03 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minimap_bonus.h"

void	draw_miniminimap(t_win	*win)
{
	int	xy[4];

	xy[2] = 0;
	xy[0] = (int)win->player.posx - WIDHT_MINIMAP_STATIC / 2;
	while (xy[0] < (int)win->player.posx + WIDHT_MINIMAP_STATIC / 2)
	{
		xy[3] = 0;
		xy[1] = (int)win->player.posy - WIDHT_MINIMAP_STATIC / 2;
		while (xy[1] < (int)win->player.posy + WIDHT_MINIMAP_STATIC / 2)
		{
			draw_minimini_part2(win, xy);
			xy[1]++;
			xy[3] += WIDTH_MINI;
		}
		xy[0]++;
		xy[2] += WIDTH_MINI;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->map.minimap.img, 0, 0);
}

void	inicialization_minimap(t_win *win)
{
	create_mini_wall(win);
	create_mini_floor(win);
	create_mini_transparent(win);
	win->map.map.width = win->maps->width * WIDTH_MINI;
	win->map.map.height = win->maps->height * WIDTH_MINI;
	init_miniminimap(win);
}

void	create_hero(t_win *win)
{
	int	y;
	int	x;

	win->hero.temp.width = WIDHT_HERO;
	win->hero.temp.height = WIDHT_HERO;
	win->hero.temp.img = mlx_new_image(win->mlx,
			win->hero.temp.width, win->hero.temp.height);
	win->hero.temp.buffer = (int *) mlx_get_data_addr(win->hero.temp.img,
			&win->hero.temp.pixel_bits, &win->hero.temp.line_bytes,
			&win->hero.temp.endian);
	y = 0;
	while (y < win->hero.temp.height)
	{
		x = 0;
		while (x < win->hero.temp.width)
		{
			win->hero.temp.buffer[y * win->hero.temp.width + x] = BLUE;
			x++;
		}
		y++;
	}
}

void	draw_hero(t_win *win)
{
	win->hero.y = WIDHT_MINIMAP_STATIC / 2 * WIDTH_MINI;
	win->hero.x = WIDHT_MINIMAP_STATIC / 2 * WIDTH_MINI;
	mlx_put_image_to_window(win->mlx, win->win,
		win->hero.temp.img, win->hero.x, win->hero.y);
}
