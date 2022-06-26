/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_drawline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:17:46 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:17:46 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DRAWLINE_H
# define S_DRAWLINE_H

typedef struct s_drawline{
	int		x_err;
	int		y_err;
	int		dx;
	int		dy;
	int		incx;
	int		incy;
	float	x;
	float	y;
	int		d;
}	t_drawline;

#endif /*S_DRAWLINE_H*/
