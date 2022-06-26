/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_no_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:23:33 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:23:33 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx123/mlx.h"
#include"../incs/raycast.h"
#include "../incs/minimap_bonus.h"

void	drawall_no_bonus(t_win *win)
{
	mlx_clear_window(win->mlx, win->win);
	raycast(win, &win->player);
	mlx_put_image_to_window(win->mlx, win->win, win->temp.img, 0, 0);
}
