//
// Created by John Nappa on 5/10/22.
//

#ifndef QWE_S_TEMPLATE_H
#define QWE_S_TEMPLATE_H

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

#endif //QWE_S_TEMPLATE_H
