//
// Created by John Nappa on 5/10/22.
//

#ifndef QWE_S_WIN_H
#define QWE_S_WIN_H

#include "struct_map.h"
#include "s_line.h"
#include "s_minimap.h"
#include "s_hero.h"

typedef struct s_win{
	void		*mlx;
	void		*win;
	t_template	temp;
	t_img		player;
	t_line		line;
	t_template	N;
	t_template	S;
	t_template	W;
	t_template	E;
	t_minimap 	map;
	t_hero		hero;
	t_map		*maps;
} t_win;

#endif //QWE_S_WIN_H
