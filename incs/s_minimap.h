//
// Created by John Nappa on 5/10/22.
//

#ifndef QWE_S_MINIMAP_H
#define QWE_S_MINIMAP_H

#include "s_template.h"

typedef struct s_minimap{
	t_template	map;
	t_template	wall;
	t_template	floor;
	t_template	transparent;
}	t_minimap;

#endif //QWE_S_MINIMAP_H
