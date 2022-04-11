/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:51:09 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/11 16:10:10 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	unsigned const char	*csrc;
	unsigned char		*lastdst;
	unsigned const char	*lastsrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned const char *)src;
	if (cdst < csrc)
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	else if (cdst > csrc)
	{
		lastdst = cdst + (len - 1);
		lastsrc = csrc + (len - 1);
		while (len--)
			*lastdst-- = *lastsrc--;
	}
	return (dst);
}
