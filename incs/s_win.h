/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_win.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:21:09 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:21:09 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_WIN_H
# define S_WIN_H
# include "struct_map.h"
# include "s_line.h"
# include "s_minimap.h"
# include "s_hero.h"
# include "s_mouse.h"

typedef struct s_win{
	void		*mlx;
	void		*win;
	t_template	temp;
	t_img		player;
	t_line		line;
	t_template	n;
	t_template	s;
	t_template	w;
	t_template	e;
	t_minimap	map;
	t_hero		hero;
	t_map		*maps;
	t_template	scope;
	t_mouse		mouse;
}	t_win;

#endif /*S_WIN_H*/
