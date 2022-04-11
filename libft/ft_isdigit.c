/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:05:57 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/11 16:09:19 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
