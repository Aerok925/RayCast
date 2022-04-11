/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:58:06 by jkieth            #+#    #+#             */
/*   Updated: 2021/10/14 14:56:03 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstr(int n, char *str, int i)
{
	if (n >= 10)
	{
		ft_fstr(n / 10, str, i);
		ft_fstr(n % 10, str, i);
	}
	else
	{
		while (str[i] != '\0')
			i++;
		str[i] = n + '0';
	}
	return (str);
}

char	*create_str(int count, int n, int i)
{
	char	*str;

	i = n;
	if (n < 0)
	{
		if (n == -2147483648)
			count = 10;
		else
			i *= -1;
		count += 1;
	}
	while (i >= 10)
	{
		i = i / 10;
		count++;
	}
	i = 0;
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	while (i < count + 1)
		str[i++] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = create_str(1, n, 0);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[1] = '2';
			n = 147483648;
		}
		else
			n *= -1;
	}
	return (ft_fstr(n, str, 0));
}
