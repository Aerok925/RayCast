/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_paths_colors.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:24:23 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:24:23 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_PATHS_COLORS_H
# define INIT_PATHS_COLORS_H
# include "parse_map.h"

int	init_path(t_map *map, char **full);
int	pull_colors(t_map *map, char **str_array);
int	init_floor_and_ceil(t_map *map, char **full);

#endif /*INIT_PATHS_COLORS_H*/
