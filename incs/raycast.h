/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:16:58 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:16:58 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "math.h"
# include "s_win.h"
# include "all_define.h"
# include "draw_line.h"

typedef struct s_math{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	perpwalldist;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		drawstart;
	int		drawend;
	double	wallx;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	int		lineheight;
	int		linewidth;
}	t_math;

void	first_calculate(t_math *math, t_img *player);
void	found_step(t_math *math, t_img *player);
void	found_x_y_tex(t_math *math, t_img *player, t_win *win);
void	draw_sky_and_floor(t_win *win, t_math *math, int x);
void	draw_textures(t_win *win, t_math *math, int x);
void	check_dist(t_math *math);
void	setimgtotemplate(t_template *in, t_template *from, int x1, int y1);
void	raycast(t_win *win, t_img *player);
void	check_dist(t_math *math);

#endif /*RAYCAST_H*/
