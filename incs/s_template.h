/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_template.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkieth <jkieth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:20:44 by jkieth            #+#    #+#             */
/*   Updated: 2022/05/17 16:20:44 by jkieth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TEMPLATE_H
# define S_TEMPLATE_H

typedef struct s_template{
	int		height;
	int		width;
	void	*img;
	int		*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*name;
}	t_template;

#endif /*S_TEMPLATE_H*/
