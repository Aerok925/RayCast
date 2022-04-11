/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:49:33 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/14 16:20:46 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_set(char s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*str_create(char const *s1, size_t i, size_t len)
{
	char	*str;
	size_t	j;

	j = 0;
	str = malloc(sizeof(char) * (len - i + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 || !set)
		return ((char *)s1);
	while (s1[i])
	{
		if (search_set(s1[i], set) == 0)
			break ;
		i++;
	}
	len = ft_strlen(s1) + 1;
	if (i == len - 1)
		return (ft_strdup(""));
	while (len--)
	{
		if (search_set(s1[len - 1], set) == 0)
			break ;
	}
	return (str_create(s1, i, len));
}
