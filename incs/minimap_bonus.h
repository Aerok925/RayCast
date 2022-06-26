/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:15:14 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:15:14 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "all_define.h"
# include "s_win.h"
# include "../mlx123/mlx.h"
# include "raycast.h"

void	create_mini_wall(t_win *win);
void	create_mini_floor(t_win *win);
void	create_mini_transparent(t_win *win);
void	inicialization_minimap(t_win *win);
void	create_hero(t_win *win);
void	draw_hero(t_win *win);
void	draw_miniminimap(t_win	*win);
void	draw_minimini_part2(t_win	*win, int *xy);
void	init_miniminimap(t_win *win);

#endif /*MINIMAP_BONUS_H*/
