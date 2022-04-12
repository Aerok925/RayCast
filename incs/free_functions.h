/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:11:18 by jkieth            #+#    #+#             */
/*   Updated: 2022/04/12 18:11:18 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_FUNCTIONS_H
# define FREE_FUNCTIONS_H
# include <stdlib.h>
# include "../incs/struct_map.h"

void	*free_matrix(char **str_array);
void	*free_map(t_map *map);

#endif /*FREE_FUNCTIONS_H*/
