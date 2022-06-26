/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:24:23 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:24:23 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/init_paths_colors.h"

int	fill_colors(t_map *map, char **str_array, int *color, char **bufer)
{
	if (ft_strncmp(str_array[0], "F", 2) == 0)
	{
		if (map->floor_rgb != -1)
			return (errors_paths_colors(5, str_array, bufer));
		map->floor_rgb = rgb_to_int(color);
	}
	if (ft_strncmp(str_array[0], "C", 2) == 0)
	{
		if (map->ceil_rgb != -1)
			return (errors_paths_colors(5, str_array, bufer));
		map->ceil_rgb = rgb_to_int(color);
	}
	return (0);
}

int	check_symbols(char **str_array)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str_array[1][i])
	{
		if ((str_array[1][i] < '0' || str_array[1][i] > '9')
			&& str_array[1][i] != ',')
			return (1);
		if (str_array[1][i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	pull_colors(t_map *map, char **str_array, int last, int i)
{
	int		color[3];
	char	**buffer;

	if (!str_array[1] || check_symbols(str_array) == 1)
		return (errors_paths_colors(4, str_array, NULL));
	buffer = ft_split(str_array[1], ',');
	if (!buffer || count_str(buffer) != 3 || count_str(str_array) != 2)
		return (errors_paths_colors(4, str_array, buffer));
	while (buffer[++i])
	{
		if (is_num(buffer[i]) == 1)
			return (errors_paths_colors(4, str_array, buffer));
		color[i] = ft_atoi(buffer[i]);
		if (color[i] < 0 || color[i] > 255)
			return (errors_paths_colors(4, str_array, buffer));
	}
	if (fill_colors(map, str_array, color, buffer) == 1)
		return (1);
	free_matrix(buffer);
	if (map->last_line < last)
		map->last_line = last;
	return (0);
}

int	check_second_arg(char **str_array)
{
	if ((str_array[0][0] == 'N' || str_array[0][0] == 'S'
		|| str_array[0][0] == 'W' || str_array[0][0] == 'E')
		&& count_str(str_array) != 2)
		return (1);
	return (0);
}
