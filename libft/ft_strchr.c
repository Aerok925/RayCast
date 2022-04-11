/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:40:09 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/12 22:16:11 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sym;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (c > 256)
	{
		if (c > 256)
			c -= 256;
	}
	while (*s)
	{
		if (*s == c)
		{
			sym = (char *)s;
			return ((char *)sym);
		}
		s++;
	}
	return (NULL);
}
