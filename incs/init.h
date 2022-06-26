/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:14:58 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:14:58 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "s_win.h"

void	player_init(t_win *win, char **argv);
void	vector_init(t_win *win);
int		destroy(t_win *win);

#endif /*INIT_H*/
