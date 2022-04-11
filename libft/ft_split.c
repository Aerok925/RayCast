/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:51:21 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/15 19:12:45 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**ft_malloc_str(char *cs, char c, char **str, int count)
{
	int		i;
	int		token_len;

	i = 0;
	token_len = 0;
	while (*cs && i < count)
	{
		while (*cs && *cs == c)
			cs++;
		while (*cs && *cs != c)
		{
			token_len++;
			cs++;
		}
		str[i] = (char *)malloc(sizeof(char) * (token_len + 1));
		if (str[i] == NULL)
			return (ft_free_str(str));
		i++;
		token_len = 0;
	}
	return (str);
}

char	**ft_fill_str(char *cs, char c, char **str, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*cs && i < count)
	{
		while (*cs && *cs == c)
			cs++;
		while (*cs && *cs != c)
		{
			str[i][j] = *cs;
			cs++;
			j++;
			if (*cs == c || *cs == '\0')
			{
				str[i][j] = '\0';
				i++;
			}
		}
		j = 0;
		cs++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	i = 0;
	count = ft_len((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (str == NULL)
		return (NULL);
	str = ft_malloc_str((char *)s + i, c, str, count);
	if (str == NULL)
		return (NULL);
	return (ft_fill_str((char *)s, c, str, count));
}
