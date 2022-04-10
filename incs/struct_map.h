#ifndef CUB3D_STRUCT_MAP_H
# define CUB3D_STRUCT_MAP_H

#include "stdio.h"

typedef struct s_map{
	char	*all_map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		FRGB[3];
	int		CRGB[3];
}	t_map;

#endif //CUB3D_STRUCT_MAP_H
