/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:11:15 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/12 22:16:17 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		needle_len;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack + i);
	if (len == 0)
		return (0);
	needle_len = ft_strlen(needle);
	if (needle_len > ft_strlen(haystack))
		return (NULL);
	while (i <= (len - needle_len) && haystack)
	{
		if ((haystack[0] == needle[0])
			&& (0 == ft_strncmp(haystack, needle, needle_len)))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
