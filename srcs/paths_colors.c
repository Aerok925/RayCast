/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:23:56 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:37:27 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/init_paths_colors.h"

int	true_char(t_map *map, char c)
{
	if (!map->north || !map->south || !map->west || !map->east
		|| map->ceil_rgb == -1 || map->floor_rgb == -1)
	{
		if (c != '\0' && c != 'N' && c != 'S' && c != 'W'
			&& c != 'E' && c != 'F' && c != 'C')
			return (1);
	}
	return (0);
}

int	fill_path(t_map *map, char **str_array, int i)
{
	if (ft_strncmp(str_array[0], "NO", 3) == 0
		|| ft_strncmp(str_array[0], "SO", 3) == 0
		|| ft_strncmp(str_array[0], "WE", 3) == 0
		|| ft_strncmp(str_array[0], "EA", 3) == 0)
	{
		if (str_array[0][0] == 'N' && !map->north)
			map->north = ft_strdup(str_array[1]);
		else if (str_array[0][0] == 'N')
			return (1);
		if (str_array[0][0] == 'S' && !map->south)
			map->south = ft_strdup(str_array[1]);
		else if (str_array[0][0] == 'S')
			return (1);
		if (str_array[0][0] == 'W' && !map->west)
			map->west = ft_strdup(str_array[1]);
		else if (str_array[0][0] == 'W')
			return (1);
		if (str_array[0][0] == 'E' && !map->east)
			map->east = ft_strdup(str_array[1]);
		else if (str_array[0][0] == 'E')
			return (1);
		if (map->last_line < i)
			map->last_line = i;
	}
	return (0);
}

int	errors_paths_colors(int num, char **str_array1, char **str_array2)
{
	if (num == 1)
		printf("Error: Memory allocated error!\n");
	else if (num == 2)
		printf("Error: No valid symbol!\n");
	else if (num == 3)
		printf("Error: Too many paths!\n");
	else if (num == 4)
		printf("Error: Incorrect colors!\n");
	else if (num == 5)
		printf("Error: Too many colors!\n");
	else if (num == 6)
		printf("Error: No textures!\n");
	else if (num == 7)
		printf("Error: No colors!\n");
	else if (num == 8)
		printf("Error: File is not opened!\n");
	else if (num == 9)
		printf("Error: No paths or color!\n");
	if (str_array1)
		free_matrix(str_array1);
	if (str_array2)
		free_matrix(str_array2);
	return (1);
}

int	checks(t_map *map)
{
	if (!map->north || !map->south || !map->west || !map->east)
		return (errors_paths_colors(6, NULL, NULL));
	if (map->floor_rgb == -1 || map->ceil_rgb == -1)
		return (errors_paths_colors(7, NULL, NULL));
	if (check_path(map) == 1)
		return (errors_paths_colors(8, NULL, NULL));
	return (0);
}

int	paths_colors(t_map *map, char **full, int i)
{
	char	**temp;

	while (full[++i])
	{
		if (full[i][0] == '\0')
			continue ;
		if (true_char(map, full[i][0]) == 1)
			return (errors_paths_colors(2, NULL, NULL));
		temp = ft_split(full[i], ' ');
		if (!temp)
			return (errors_paths_colors(1, NULL, NULL));
		if (check_second_arg(temp) == 1)
			return (errors_paths_colors(9, temp, NULL));
		if (fill_path(map, temp, i) == 1)
			return (errors_paths_colors(3, temp, NULL));
		if (ft_strncmp(temp[0], "F", 2) == 0
			|| ft_strncmp(temp[0], "C", 2) == 0)
			if (pull_colors(map, temp, i, -1) == 1)
				return (1);
		free_matrix(temp);
	}
	if (checks(map) == 1)
		return (1);
	return (0);
}
