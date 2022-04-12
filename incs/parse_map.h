/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:58:31 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/10 21:01:05 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H
# include "../libft/libft.h"
# include "struct_map.h"
# include "free_functions.h"
# include "check_valid.h"
# include "correct_map_init.h"
# include "init_paths_colors.h"

t_map	*parser_map(char *path);

#endif /*PARSE_MAP_H*/
