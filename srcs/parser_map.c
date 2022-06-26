/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:36:27 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/14 18:14:44 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/struct_map.h"
#include "../incs/parse_map.h"

int	fill_map(t_map *map, char **full)
{
	int	i;

	i = map->last_line + 1;
	while (full[i] && full[i][0] == '\0')
		i++;
	if (full[i] == NULL)
		return (1);
	map->all_map = str_array_dup(full, i, count_str(full));
	if (!map->all_map)
		return (1);
	map->all_map = correct_map(map->all_map, 0);
	if (!map->all_map)
		return (1);
	if (check_valid(map, -1, 0, 0) == 1)
		return (1);
	map->width = ft_strlen(map->all_map[0]);
	map->height = count_lines(map->all_map);
	return (0);
}

void	*error_func(char **full, t_map *map, int num)
{
	if (num == 0)
		printf("Error: Wrong filename!\n");
	else if (num == 1)
		printf("Error: File is not opened!\n");
	else if (num == 2)
		printf("Error: No valid map!\n");
	if (full)
		free_matrix(full);
	free_map(map);
	return (NULL);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->all_map = NULL;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->floor_rgb = -1;
	map->ceil_rgb = -1;
	map->last_line = 0;
	return (map);
}

t_map	*parser_map(char *file)
{
	t_map	*map;
	char	**full;

	full = NULL;
	map = init_map();
	if (!map)
		return (NULL);
	if (check_filename(file) == 1)
		return (error_func(full, map, 0));
	full = read_file(file, 0);
	if (!full)
		return (error_func(full, map, 1));
	if (paths_colors(map, full, -1) == 1)
		return (error_func(full, map, 3));
	if (fill_map(map, full) == 1)
		return (error_func(full, map, 2));
	free_matrix(full);
	return (map);
}
