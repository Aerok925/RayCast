/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:13:54 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:13:54 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/check_valid.h"

int	is_digit_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] <= '0' || str[i] >= '9') && str[i] != ' ')
			return (1);
		i++;
	}
	if (str[i] != '\0')
		return (1);
	else
		return (0);
}

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

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_true_symbol(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	check_valid(char **map, int i, int j)
{
	int	player;

	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_true_symbol(map[i][j]) && map[i][j] != ' ')
				return (1);
			if (is_player(map[i][j]))
				player++;
			if ((is_player(map[i][j]) || map[i][j] == '0')
				&& (!is_true_symbol(map[i][j + 1])
					|| !is_true_symbol(map[i][j - 1])
					|| !is_true_symbol(map[i + 1][j])
					|| !is_true_symbol(map[i - 1][j])))
				return (1);
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}
