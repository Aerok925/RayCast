/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minimap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:19:29 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:19:38 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MINIMAP_H
# define S_MINIMAP_H

# include "s_template.h"

typedef struct s_minimap{
	t_template	map;
	t_template	minimap;
	t_template	wall;
	t_template	floor;
	t_template	transparent;
}	t_minimap;

#endif /*S_MINIMAP_H*/
