/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:14:07 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:14:07 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_VALID_H
# define CHECK_VALID_H
# include "../incs/parse_map.h"

int	check_valid(char **map, int i, int j);
int	check_path(t_map *map);
int	is_digit_space(char *str);

#endif /*CHECK_VALID_H*/
