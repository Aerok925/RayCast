/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:18:27 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/12 21:26:52 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sizedst;
	size_t	sizesrc;
	size_t	res;

	j = 0;
	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	if (sizedst > size)
		return (size + sizesrc);
	else
		res = sizedst + sizesrc;
	i = sizedst;
	if (size > 0)
	{
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (res);
}
