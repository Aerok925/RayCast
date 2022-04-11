/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:36:27 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/10 21:20:11 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/struct_map.h"

t_map	*parser_map(char *path)
{
	t_map	*map;
	char	*buf;
	int		rd;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	rd = read(fd, buf, 1);
	while (rd != 0)
	{

	}
}
