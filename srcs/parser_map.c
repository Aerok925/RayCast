/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:36:27 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:33:40 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/struct_map.h"
#include "../incs/parse_map.h"

int	fill_map(t_map *map, char **full)
{
	int	i;

	i = 6;
	while (full[i] && is_digit_space(full[i]) == 1)
		i++;
	map->all_map = str_array_dup(full, i, count_str(full));
	if (!map->all_map)
		return (1);
	if (check_valid(map->all_map, 0, 0) == 1)
		return (1);
	map->all_map = correct_map(map->all_map);
	if (!map->all_map)
		return (1);
	return (0);
}

char	*read_file(char *file, int fd)
{
	char	*final_str;
	char	*buf;
	int		rd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (100 + 1));
	if (buf == NULL)
		return (NULL);
	rd = read(fd, buf, 100);
	if (rd <= 0)
	{
		free(buf);
		return (NULL);
	}
	final_str = ft_strdup("");
	while (rd > 0)
	{
		buf[rd] = '\0';
		final_str = ft_strjoin(final_str, buf);
		rd = read(fd, buf, 100);
	}
	free(buf);
	return (final_str);
}

void	*error_func(char *file, char **full, t_map *map, int num)
{
	if (num == 1)
		printf("Error: Memory allocated error!\n");
	else if (num == 2)
		printf("Error: No valid map!\n");
	else if (num == 3)
		printf("Error: The file cannot be opened!\n");
	else if (num == 4)
		printf("Error: Incorrect colors!\n");
	if (file)
		free(file);
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
	return (map);
}

t_map	*parser_map(char *file)
{
	t_map	*map;
	char	*open_file;
	char	**full;

	full = NULL;
	open_file = NULL;
	map = init_map();
	if (!map)
		return (NULL);
	open_file = read_file(file, 0);
	if (!open_file)
		return (error_func(open_file, full, map, 3));
	full = ft_split(open_file, '\n');
	if (!full)
		return (error_func(open_file, full, map, 1));
	if (init_path(map, full) == 1)
		return (error_func(open_file, full, map, 3));
	if (init_floor_and_ceil(map, full) == 1)
		return (error_func(open_file, full, map, 4));
	if (fill_map(map, full) == 1)
		return (error_func(open_file, full, map, 2));
	free_matrix(full);
	free(open_file);
	return (map);
}
