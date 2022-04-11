/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:25:05 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/13 17:28:38 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lenght;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	if (lenght <= start || len == 0)
		return (ft_strdup(""));
	if (start + len < lenght)
		lenght = start + len;
	str = malloc(sizeof(char) * (lenght - start + 1));
	if (str == NULL)
		return (NULL);
	i = start;
	while (i < lenght && s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
