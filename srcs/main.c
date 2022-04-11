#include "../incs/struct_map.h"
#include "../incs/mlx.h"

float	px = 100, py = 100;


typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bitsinpixel;
	int			line_bytes;
	int			endian;
}			t_img;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 512, "Hello world!");
	t_img	pink_cube;
	pink_cube.ptr = mlx_new_image(mlx, 30, 30);
	pink_cube.addr = mlx_get_data_addr(pink_cube.ptr, &(pink_cube.bitsinpixel), &(pink_cube.line_bytes), &(pink_cube.endian));
	printf("%s %d %d %d\n", pink_cube.addr, pink_cube.bitsinpixel, pink_cube.line_bytes, pink_cube.endian);
//	int color = create_trgb(0, 255, 218, 233);
//	int width;
//	int height = 0;
//	printf("%d\n", color);
//	while (height < 3) {
//		width = 0;
//		while (width < 3) {
//			pink_cube.addr[height * 3 + width] = color;
//			width++;
//		}
//		height++;
//	}
	mlx_put_image_to_window(mlx, mlx_win, pink_cube.ptr, 0, 0);
	mlx_loop(mlx);
}