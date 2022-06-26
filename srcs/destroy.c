/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:23:24 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:23:24 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx123/mlx.h"
#include "../incs/s_win.h"
#include "../incs/free_functions.h"

int	destroy(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	free_map(win->maps);
	exit(0);
}
