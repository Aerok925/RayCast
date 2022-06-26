/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:13:54 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/14 18:14:44 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/check_valid.h"

int	check_path(t_map *map)
{
	if (open(map->north, O_RDONLY) == -1)
		return (1);
	if (open(map->south, O_RDONLY) == -1)
		return (1);
	if (open(map->west, O_RDONLY) == -1)
		return (1);
	if (open(map->east, O_RDONLY) == -1)
		return (1);
	return (0);
}

int	is_player(t_map *map, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		map->direction = c;
		map->all_map[y][x] = '0';
		map->x = (double)y;
		map->y = (double)x;
		return (1);
	}
	return (0);
}

int	is_true_symbol(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	not_wall(char **map, int count_line, int i, int j)
{
	if (i == 0 && ((!is_true_symbol(map[i][j + 1])
			|| !(j != 0 && !is_true_symbol(map[i][j - 1]))
		|| !is_true_symbol(map[i + 1][j]))))
		return (1);
	else if (i != count_line - 1 && ((!is_true_symbol(map[i][j + 1])
			|| (j != 0 && !is_true_symbol(map[i][j - 1]))
		|| !is_true_symbol(map[i - 1][j])
			|| !is_true_symbol(map[i + 1][j]))))
		return (1);
	else if (i == count_line - 1 || j == 0)
		return (1);
	return (0);
}

int	check_valid(t_map *map, int i, int j, int check)
{
	int	player;

	player = 0;
	while (map->all_map[++i])
	{
		j = -1;
		while (map->all_map[i][++j])
		{
			if (!is_true_symbol(map->all_map[i][j])
				&& map->all_map[i][j] != ' ')
				return (1);
			if (is_player(map, map->all_map[i][j], j, i))
				player++;
			if (map->all_map[i][j] == '0'
				&& not_wall(map->all_map, count_str(map->all_map), i, j) == 1)
				return (1);
			check++;
		}
		if (check != 0 && map->all_map[i][0] == '\0')
			return (1);
	}
	if (player != 1)
		return (1);
	return (0);
}
