/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:03:13 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/11 19:52:18 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b1;
	char			symbol;
	size_t			i;

	i = 0;
	b1 = (unsigned char *)b;
	symbol = c;
	while (i < len)
	{
		b1[i] = symbol;
		i++;
	}
	return (b);
}
