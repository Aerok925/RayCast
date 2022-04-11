/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:46:26 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/11 21:18:33 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*sym;

	i = 0;
	while (c > 256)
	{
		if (c > 256)
			c -= 256;
	}
	while (*s++)
		i++;
	s--;
	while (i >= 0)
	{
		if (*s == c)
		{
			sym = (char *)s;
			return ((char *)sym);
		}
		i--;
		s--;
	}
	return (NULL);
}
