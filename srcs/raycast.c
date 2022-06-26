/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:24:25 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:24:25 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/raycast.h"

void	raycast(t_win *win, t_img *player)
{
	int		x;
	t_math	math;

	x = 0;
	while (x < SCREENWIDTH)
	{
		math.camerax = (2 * x / (double)SCREENWIDTH - 1);
		first_calculate(&math, player);
		found_step(&math, player);
		while (math.hit == 0)
		{
			check_dist(&math);
			if (win->maps->all_map[math.mapx][math.mapy] == '1')
				math.hit = 1;
		}
		found_x_y_tex(&math, player, win);
		draw_sky_and_floor(win, &math, x);
		draw_textures(win, &math, x);
		x++;
	}
}
