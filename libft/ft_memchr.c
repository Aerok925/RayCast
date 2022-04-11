/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:11:08 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/12 18:20:10 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*adress;
	unsigned char	symbol;

	i = 0;
	src = (unsigned char *)s;
	symbol = c;
	while (i < n)
	{
		if (src[i] == symbol)
		{
			adress = &src[i];
			return (adress);
		}
		i++;
	}
	return (NULL);
}
