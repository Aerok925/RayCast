/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:13:24 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/16 19:13:24 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parse_map.h"

char	**expansion_array(char **strs)
{
	char	**new_strs;
	int		i;

	i = 0;
	if (!strs)
	{
		new_strs = malloc(sizeof(char *) * 2);
		if (!new_strs)
			return (NULL);
	}
	else
	{
		new_strs = malloc(sizeof(char *) * (count_str(strs) + 2));
		if (!new_strs)
			return (NULL);
		while (strs[i])
		{
			new_strs[i] = ft_strdup(strs[i]);
			i++;
		}
	}
	new_strs[i++] = ft_strdup("");
	new_strs[i] = NULL;
	free_matrix(strs);
	return (new_strs);
}

char	**write_array(int fd, int rd, char **final_str, char *buf)
{
	int	i;

	i = 0;
	final_str = expansion_array(final_str);
	if (!final_str)
		return (NULL);
	while (rd > 0)
	{
		buf[rd] = '\0';
		if (buf[0] == '\n')
		{
			final_str = expansion_array(final_str);
			i++;
		}
		else
			final_str[i] = ft_strjoin(final_str[i], buf);
		rd = read(fd, buf, 1);
	}
	return (final_str);
}

char	**read_file(char *file, int fd)
{
	char	**final_str;
	char	*buf;
	int		rd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * 2);
	if (buf == NULL)
		return (NULL);
	rd = read(fd, buf, 1);
	if (rd <= 0)
	{
		free(buf);
		return (NULL);
	}
	final_str = NULL;
	final_str = write_array(fd, rd, final_str, buf);
	free(buf);
	return (final_str);
}
