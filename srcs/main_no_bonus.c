/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_no_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:23:58 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:23:58 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/struct_map.h"
#include "../mlx123/mlx.h"
#include"../incs/raycast.h"
#include "../incs/s_win.h"
#include "../incs/parse_map.h"
#include "../incs/button_keyboard.h"
#include "../incs/draw_all.h"
#include "../incs/init.h"

void	draw_scope(t_win *win)
{
	win->scope.img = mlx_xpm_file_to_image(win->mlx,
			"textures/brick.xpm", &win->scope.width, &win->scope.height);
	win->scope.buffer = (int *) mlx_get_data_addr(win->scope.img,
			&win->scope.pixel_bits, &win->scope.line_bytes, &win->scope.endian);
	mlx_put_image_to_window(win->mlx, win->win,
		win->scope.img, SCREENWIDTH / 2, SCREENHEIGHT / 2);
}

int	create_adr_wall(t_win	*win, t_template *temp)
{
	temp->img = mlx_xpm_file_to_image(win->mlx,
			temp->name, &temp->width, &temp->height);
	if (temp->width != 64 || temp->height != 64)
		return (1);
	temp->buffer = (int *) mlx_get_data_addr(temp->img,
			&temp->pixel_bits, &temp->line_bytes, &temp->endian);
	return (0);
}

void	error_pixel(t_win *win)
{
	write(2, "Incorrect image resolution\n", 27);
	free_map(win->maps);
	exit(1);
}

void	argc_error(int argc)
{
	if (argc > 2)
	{
		write(2, "many arg\n", 9);
		exit (1);
	}
	else if (argc == 1)
	{
		write(2, "error arg\n", 10);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_win	win;

	argc_error(argc);
	player_init(&win, argv);
	vector_init(&win);
	win.player.movespeed = 0.2;
	win.player.rotspeed = 0.1;
	if (create_adr_wall(&win, &win.w))
		error_pixel(&win);
	if (create_adr_wall(&win, &win.s))
		error_pixel(&win);
	if (create_adr_wall(&win, &win.n))
		error_pixel(&win);
	if (create_adr_wall(&win, &win.e))
		error_pixel(&win);
	drawall_no_bonus(&win);
	mlx_hook(win.win, 2, 1L << 0, pressbutton_no_bonus, &win);
	mlx_hook(win.win, 17, 0, destroy, &win);
	mlx_loop(win.mlx);
}
