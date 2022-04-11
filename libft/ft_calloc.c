/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:22:55 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/11 16:49:50 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*arr;

	arr = malloc(size * number);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, number * size);
	return (arr);
}
