/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:18:49 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:18:49 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/correct_map_init.h"

char	*fill_len_with_space(char *old_str, int max_len)
{
	int		i;
	char	*new_line;

	new_line = malloc(sizeof(char) * (max_len + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (old_str[i])
	{
		new_line[i] = old_str[i];
		i++;
	}
	while (i < max_len)
		new_line[i++] = ' ';
	new_line[i] = '\0';
	return (new_line);
}

char	**correct_map(char **map, int i)
{
	char	**new_map;
	int		max_len;

	max_len = find_biggest_line(map);
	if (max_len == 0)
		return (map);
	new_map = malloc(sizeof(char *) * (count_str(map) + 1));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		if (ft_strlen(map[i]) == max_len)
			new_map[i] = ft_strdup(map[i]);
		else
		{
			new_map[i] = fill_len_with_space(map[i], max_len);
			if (!new_map[i])
				return (free_matrix(new_map));
		}
		i++;
	}
	new_map[i] = NULL;
	free_matrix(map);
	return (new_map);
}

int	count_str(char **strs)
{
	int	count;

	count = 0;
	if (!strs)
		return (count);
	while (strs[count])
		count++;
	return (count);
}

char	**str_array_dup(char **strs, int start, int finish)
{
	char	**new_strs;
	int		i;

	i = 0;
	if (finish - start <= 0)
		return (NULL);
	new_strs = malloc(sizeof(char *) * ((finish - start) + 1));
	if (new_strs == NULL)
		return (NULL);
	while (strs && strs[start] && start < finish)
	{
		new_strs[i] = ft_strdup(strs[start]);
		start++;
		i++;
	}
	new_strs[i] = NULL;
	return (new_strs);
}

int	find_biggest_line(char **map)
{
	int	len;
	int	max;
	int	count;
	int	i;

	i = 0;
	max = 0;
	count = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len == max)
			count++;
		if (len > max)
			max = len;
		i++;
	}
	if (count == count_str(map))
		return (0);
	return (max);
}
