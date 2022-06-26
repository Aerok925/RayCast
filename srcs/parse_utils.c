/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:55:16 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/14 17:56:48 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parse_utils.h"

int	rgb_to_int(int *rgb)
{
	return ((rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}

int	count_lines(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit_space(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
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

char	*ft_charjoin(char *s1, char symbol)
{
	char	*dest;
	int		i;

	if (!s1)
		s1 = ft_strdup("");
	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i++] = symbol;
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			if (ft_strncmp(filename + i, ".cub", 5) == 0)
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (1);
}
