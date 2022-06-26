/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_keyboard.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:13:29 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:13:29 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_KEYBOARD_H
# define BUTTON_KEYBOARD_H

# include "s_win.h"

int	pressbutton(int key, t_win *win);
int	pressbutton_no_bonus(int key, t_win *win);

#endif /*BUTTON_KEYBOARD_H*/
