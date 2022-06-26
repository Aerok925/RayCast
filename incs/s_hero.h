/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hero.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:18:12 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:18:12 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_HERO_H
# define S_HERO_H

# include "s_template.h"

typedef struct s_hero{
	t_template	temp;
	double		x;
	double		y;
}	t_hero;

#endif /*S_HERO_H*/
