/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:41:43 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/14 13:58:11 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cs;
	unsigned int	i;
	size_t			len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	cs = malloc(sizeof(char) * (len + 1));
	if (cs == NULL)
		return (NULL);
	while (s[i])
	{
		cs[i] = (*f)(i, s[i]);
		i++;
	}
	cs[i] = '\0';
	return (cs);
}
