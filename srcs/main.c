#include "../incs/struct_map.h"
#include "../incs/mlx.h"
#include "math.h"
#include "../incs/parse_map.h"

//#define PI 3.1415926535
//
//
typedef struct s_img
{
	void	*mlx;
	void	*win;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	void	*image;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_img;
//
//int mapX = 8, mapY = 8, mapS = 64;
//int mapq[] = {
//		1, 1, 1, 1, 1, 1, 1, 1,
//		1, 0, 1, 0, 0, 0, 0, 1,
//		1, 0, 1, 0, 0, 0, 0, 1,
//		1, 0, 1, 0, 0, 0, 0, 1,
//		1, 0, 0, 0, 0, 0, 0, 1,
//		1, 0, 0, 0, 0, 0, 0, 1,
//		1, 0, 0, 0, 0, 0, 0, 1,
//		1, 1, 1, 1, 1, 1, 1, 1
//};
//
////int drawline(){
////	t_img line;
////}
//
typedef struct s_test_img {
	void	*img;
	int		width;
	int		height;
}	t_test_img;
//
//int	drawMap(t_img *img)
//{
//	t_test_img	img_textures;
//	int			black = 0xFFA500;
//	int			white = 0xFFC0CB;
//	t_img		map[64];
//
//	img_textures.img = mlx_xpm_file_to_image(img->mlx, "textures/1.xpm", &img_textures.width, &img_textures.height);
//	for (int i = 0; i < 64; i++)
//	{
//		map[i].image = mlx_new_image(img->mlx, 64 - 1, 64 - 1);
//		map[i].buffer = mlx_get_data_addr(map[i].image, &map[i].pixel_bits, &map[i].line_bytes, &map[i].endian);
//	}
//	for (int j = 0; j < 64; j++)
//	{
//		for(int y = 0; y < 64; ++y){
//			for(int x = 0; x < 64; ++x)
//			{
//				int	pixel = (y * map[j].line_bytes) + (x * 4);
//				if (mapq[j] == 1)
//				{
//					map[j].buffer[pixel + 0] = (black) & 0xFF;
//					map[j].buffer[pixel + 1] = (black >> 8) & 0xFF;
//					map[j].buffer[pixel + 2] = (black >> 16) & 0xFF;
//					map[j].buffer[pixel + 3] = (black >> 24);
//				}
//				else
//				{
//					map[j].buffer[pixel + 0] = (white) & 0xFF;
//					map[j].buffer[pixel + 1] = (white >> 8) & 0xFF;
//					map[j].buffer[pixel + 2] = (white >> 16) & 0xFF;
//					map[j].buffer[pixel + 3] = (white >> 24);
//				}
//			}
//		}
//	}
//	for (int y = 0; y < 8; y++){
//		for (int x = 0; x < 8;x++)
//		{
//			map[y * mapX + x].px = (double)x * (double)64;
//			map[y * mapX + x].py = (double)y * (double)64;
//		}
//	}
//	for (int i = 0; i < 64; i++)
//		mlx_put_image_to_window(img->mlx, img->win, map[i].image, map[i].px, map[i].py);
//	return 0;
//}
//
//int pressButton(int key, t_img *img){
//	if (key == 2){
//		img->pa+=0.1;
//		if (img->pa > PI * 2){
//			img->pa -= PI * 2;
//		}
//		img->pdx = cos(img->pa) * 5;
//		img->pdy = sin(img->pa) * 5;
//	}
//	if (key == 0){
//		img->pa-=0.1;
//		if (img->pa < 0){
//			img->pa += PI * 2;
//		}
//		img->pdx = cos(img->pa) * 5;
//		img->pdy = sin(img->pa) * 5;
//	}
//	if (key == 1){
//		img->px+=img->pdx;
//		img->py+=img->pdy;
//	}
//	if (key == 13){
//		img->px-=img->pdx;
//		img->py-=img->pdy;
//	}
//	mlx_clear_window(img->mlx, img->win);
//	drawMap(img);
//	mlx_put_image_to_window(img->mlx, img->win, img->image, img->px, img->py);
//	return 0;
//}

//void	parse_result(t_map *map)
//{
//	int	i;
//
//	i = 0;
//	printf("NO - %s\n", map->north);
//	printf("SO - %s\n", map->south);
//	printf("WE - %s\n", map->west);
//	printf("EA - %s\n\n", map->east);
//	printf("F - %d,%d,%d\n", map->floor_rgb[0], map->floor_rgb[1], map->floor_rgb[2]);
//	printf("C - %d,%d,%d\n\nMAP:\n\n", map->ceil_rgb[0], map->ceil_rgb[1], map->ceil_rgb[2]);
//	while (map->all_map[i])
//		printf("%s\n", map->all_map[i++]);
//}

int	main(void)
{
//	t_map	*map;

//	if (argc != 2)
//		return (1);
//	map = parser_map(argv[1]);
//	if (!map)
//		return (1);
//	parse_result(map);
//	free_map(map);
	t_test_img	image;
	t_img		img;
	img.px = 300;
	img.py = 300;
	img.pa = 0;
	img.pdx = cos(img.pa) * 5;
	img.pdy = sin(img.pa) * 5;


	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1024, 510, "Tutorial Window - Create Image");
	image.img = mlx_xpm_file_to_image(img.mlx, "textures/1.xpm", &image.width, &image.height);
//	img.image = mlx_new_image(img.mlx, 10, 10);
//
//
//	img.buffer = mlx_get_data_addr(img.image, &img.pixel_bits, &img.line_bytes, &img.endian);
//	printf("%d %d %d\n", img.pixel_bits, img.line_bytes, img.endian);
//	int color = 0xABCDEF;
//
//	if (img.pixel_bits != 32)
//		color = mlx_get_color_value(img.mlx, color);
//
//	for(int y = 0; y < 10; ++y)
//		for(int x = 0; x < 10; ++x)
//		{
//			int pixel = (y * img.line_bytes) + (x * 4);
//			img.buffer[pixel + 0] = (color) & 0xFF;
//			img.buffer[pixel + 1] = (color >> 8) & 0xFF;
//			img.buffer[pixel + 2] = (color >> 16) & 0xFF;
//			img.buffer[pixel + 3] = (color >> 24);
//		}
	mlx_put_image_to_window(img.mlx, img.win, image.img, 100, 200);
	mlx_
//	drawMap(&img);
//	mlx_hook(img.win, 2, 1L << 0, pressButton, &img);
	mlx_loop(img.mlx);
	return (0);
}
