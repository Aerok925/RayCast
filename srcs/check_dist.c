/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:23:13 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:23:13 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/raycast.h"

void	check_dist(t_math *math)
{
	if (math->sidedistx < math->sidedisty)
	{
		math->sidedistx += math->deltadistx;
		math->mapx += math->stepx;
		math->side = 0;
	}
	else
	{
		math->sidedisty += math->deltadisty;
		math->mapy += math->stepy;
		math->side = 1;
	}
}
