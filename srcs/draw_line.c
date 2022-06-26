/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:23:38 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:23:38 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/draw_line.h"
#include "../incs/s_drawline.h"

void	drawline_calc_start_value(t_line *line, t_drawline *dline)
{
	dline->x_err = 0;
	dline->y_err = 0;
	dline->dx = line->x1 - line->x0;
	dline->dy = line->y1 - line->y0;
	dline->incx = 0;
	dline->incy = 0;
	if (dline->dx > 0)
		dline->incx = 1;
	else if (dline->dx != 0)
		dline->incx = -1;
	if (dline->dy > 0)
		dline->incy = 1;
	else if (dline->dy != 0)
		dline->incy = -1;
	dline->dx = abs(dline->dx);
	dline->dy = abs(dline->dy);
	if (dline->dx > dline->dy)
		dline->d = dline->dx;
	else
		dline->d = dline->dy;
}

void	drawfullline(t_win *win, t_line *line)
{
	t_drawline	dline;
	int			i;

	drawline_calc_start_value(line, &dline);
	dline.x = (float)line->x0;
	dline.y = (float)line->y0;
	i = 1;
	while (i <= dline.d)
	{
		dline.x_err += dline.dx;
		dline.y_err += dline.dy;
		if (dline.x_err >= dline.d)
		{
			dline.x += dline.incx;
			dline.x_err -= dline.d;
		}
		if (dline.y_err >= dline.d)
		{
			dline.y += dline.incy;
			dline.y_err -= dline.d;
		}
		win->temp.buffer[(int)dline.x + (int)dline.y
			* SCREENWIDTH] = line->color;
		i++;
	}
}
