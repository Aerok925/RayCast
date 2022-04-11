/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:47:22 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/15 17:47:59 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_count(t_list *lst, size_t count)
{
	if (lst->next == NULL)
		return (count);
	return (ft_size_count(lst->next, count + 1));
}

int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 1;
	if (lst == NULL)
		return (0);
	return (ft_size_count(lst, count));
}
