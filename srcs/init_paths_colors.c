/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_paths_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:23:56 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:37:27 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/init_paths_colors.h"

int	init_floor_and_ceil(t_map *map, char **full)
{
	char	**str_array;
	int		i;

	i = 4;
	while (full[i])
	{
		str_array = ft_split(full[i], ' ');
		if (!str_array)
			return (0);
		if (ft_strncmp(str_array[0], "F", 2) == 0
			|| ft_strncmp(str_array[0], "C", 2) == 0)
		{
			if (pull_colors(map, str_array) == 1)
			{
				free_matrix(str_array);
				return (1);
			}
		}
		free_matrix(str_array);
		i++;
	}
	return (0);
}

int	pull_colors(t_map *map, char **str_array)
{
	int		color;
	int		i;
	char	**buffer;

	if (!str_array[1])
		return (1);
	buffer = ft_split(str_array[1], ',');
	if (!buffer || count_str(buffer) != 3)
		return (1);
	i = -1;
	while (buffer[++i])
	{
		color = ft_atoi(buffer[i]);
		if (color < 0 || color > 255)
		{
			free_matrix(buffer);
			return (1);
		}
		if (ft_strncmp(str_array[0], "F", 2) == 0)
			map->floor_rgb[i] = color;
		if (ft_strncmp(str_array[0], "C", 2) == 0)
			map->ceil_rgb[i] = color;
	}
	free_matrix(buffer);
	return (0);
}

int	init_path(t_map *map, char **full)
{
	char	**str_array;
	int		i;

	i = 0;
	while (i < 4)
	{
		str_array = ft_split(full[i], ' ');
		if (!str_array)
			return (0);
		if (!str_array[1])
			return (1);
		if (ft_strncmp(str_array[0], "NO", 3) == 0)
			map->north = ft_strdup(str_array[1]);
		if (ft_strncmp(str_array[0], "SO", 3) == 0)
			map->south = ft_strdup(str_array[1]);
		if (ft_strncmp(str_array[0], "WE", 3) == 0)
			map->west = ft_strdup(str_array[1]);
		if (ft_strncmp(str_array[0], "EA", 3) == 0)
			map->east = ft_strdup(str_array[1]);
		free_matrix(str_array);
		i++;
	}
	if (check_path(map) == 1)
		return (1);
	return (0);
}
