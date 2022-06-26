/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:23:44 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:23:44 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/s_win.h"
#include "../mlx123/mlx.h"
#include "../incs/parse_map.h"

void	player_init(t_win *win, char **argv)
{
	win->maps = parser_map(argv[1]);
	if (win->maps == NULL)
		exit (1);
	win->mlx = mlx_init();
	win->maps->x += 0.5;
	win->maps->y += 0.5;
	win->temp.width = SCREENWIDTH;
	win->temp.height = SCREENHEIGHT;
	win->temp.img = mlx_new_image(win->mlx, SCREENWIDTH, SCREENHEIGHT);
	win->temp.buffer = (int *) mlx_get_data_addr(win->temp.img,
			&win->temp.pixel_bits, &win->temp.line_bytes, &win->temp.endian);
	win->win = mlx_new_window(win->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3d");
	win->player.posx = win->maps->x;
	win->player.posy = win->maps->y;
	if (win->maps->direction == 'S')
	{
		win->player.dirx = 1.0;
		win->player.diry = 0.0;
		win->player.planex = 0;
		win->player.planey = -0.66;
	}
}

void	vector_init(t_win *win)
{
	if (win->maps->direction == 'N')
	{
		win->player.dirx = -1.0;
		win->player.diry = 0.0;
		win->player.planex = 0;
		win->player.planey = 0.66;
	}
	else if (win->maps->direction == 'W')
	{
		win->player.dirx = 0;
		win->player.diry = -1.0;
		win->player.planex = -0.66;
		win->player.planey = 0;
	}
	else if (win->maps->direction == 'E')
	{
		win->player.dirx = 0;
		win->player.diry = 1.0;
		win->player.planex = 0.66;
		win->player.planey = 0;
	}
	win->w.name = win->maps->west;
	win->s.name = win->maps->south;
	win->e.name = win->maps->east;
	win->n.name = win->maps->north;
}
