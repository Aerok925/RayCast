/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_img.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:18:36 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:18:36 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_IMG_H
# define S_IMG_H

typedef struct s_img{
	double	posx;
	double	dirx;
	double	planex;
	double	planey;
	double	diry;
	double	posy;
	double	time;
	double	oldtime;
	double	movespeed;
	double	rotspeed;
}	t_img;

#endif /*S_IMG_H*/
