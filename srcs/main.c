#include "../incs/struct_map.h"
#include "../incs/mlx.h"
#include"../incs/raycast.h"
#include "../incs/parse_map.h"
#include "../incs/s_win.h"
#include <string.h>

int worldMap1[24][24] =
		{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

int worldMap[24][10] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 1 , 0, 0, 0, 0, 0, 1},
{1, 0, 1, 1 , 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void raycast(t_win *win, t_img *player)
{
	int		x;
	t_math	math;

	x = 0;
	while (x < screenWidth)
	{
		math.cameraX = (2 * x / (double)screenWidth - 1);
		first_calculate(&math, player);
		found_step(&math, player);
		while (math.hit == 0)
		{
			check_dist(&math);
			if(worldMap[math.mapX][math.mapY] == 1)
				math.hit = 1;
		}
		found_x_y_tex(&math, player, win);
		draw_sky_and_floor(win, &math, x);
		draw_textures(win, &math, x);
		x++;
	}
}

void setImgtoTemplate(t_template *in, t_template *from, int x1, int y1)
{
	for (int y = 0; y < from->height; y++)
	{
		for (int x = 0; x < from->width; x++)
		{
			in->buffer[(int)(y + y1) * in->width + (int)(x + x1)] = from->buffer[y * from->width + x];
		}
	}
}

void draw_hero(t_win *win)
{
	win->hero.y = win->player.posX * WIDTH_MINI - win->hero.temp.width / 2;
	win->hero.x = win->player.posY * WIDTH_MINI - win->hero.temp.width / 2;
	setImgtoTemplate(&win->temp, &win->hero.temp, (int)win->hero.x, (int)win->hero.y);
//	mlx_put_image_to_window(win->mlx, win->win, win->hero.temp.img, win->hero.x, win->hero.y);
}

void drawall(t_win *win)
{
	raycast(win, &win->player);
	setImgtoTemplate(&win->temp, &win->map.map, 0, 0);
	mlx_clear_window(win->mlx, win->win);
	mlx_put_image_to_window(win->mlx, win->win, win->temp.img, 0, 0);
	draw_hero(win);
}

int pressButton(int key, t_win *win){
	if (key == KEY_W)
	{
		if (worldMap[(int)(win->player.posX + win->player.dirX * win->player.moveSpeed)][(int)win->player.posY] != 1)
			win->player.posX += win->player.dirX * win->player.moveSpeed;
		if(worldMap[(int)win->player.posX][(int)(win->player.posY + win->player.dirY * win->player.moveSpeed)] != 1)
			win->player.posY += win->player.dirY * win->player.moveSpeed;
	}
	if (key == KEY_S)
	{
		if(worldMap[(int)(win->player.posX - win->player.dirX * win->player.moveSpeed)][(int)(win->player.posY)] != 1)
			win->player.posX -= win->player.dirX * win->player.moveSpeed;
		if(worldMap[(int)(win->player.posX)][(int)(win->player.posY - win->player.dirY * win->player.moveSpeed)] != 1)
			win->player.posY -= win->player.dirY * win->player.moveSpeed;
	}
	if (key == KEY_A)
	{
		double oldDirX = win->player.dirX;
		win->player.dirX = win->player.dirX * cos(win->player.rotSpeed) - win->player.dirY * sin(win->player.rotSpeed);
		win->player.dirY = oldDirX * sin(win->player.rotSpeed) + win->player.dirY * cos(win->player.rotSpeed);
		double oldPlaneX = win->player.planeX;
		win->player.planeX = win->player.planeX * cos(win->player.rotSpeed) - win->player.planeY * sin(win->player.rotSpeed);
		win->player.planeY = oldPlaneX * sin(win->player.rotSpeed) + win->player.planeY * cos(win->player.rotSpeed);
	}
	if (key == KEY_D)
	{
		double oldDirX = win->player.dirX;
		win->player.dirX = win->player.dirX * cos(-win->player.rotSpeed) - win->player.dirY * sin(-win->player.rotSpeed);
		win->player.dirY = oldDirX * sin(-win->player.rotSpeed) + win->player.dirY * cos(-win->player.rotSpeed);
		double oldPlaneX = win->player.planeX;
		win->player.planeX = win->player.planeX * cos(-win->player.rotSpeed) - win->player.planeY * sin(-win->player.rotSpeed);
		win->player.planeY = oldPlaneX * sin(-win->player.rotSpeed) + win->player.planeY * cos(-win->player.rotSpeed);
	}
	if (key == 53)
		exit(1);
	drawall(win);
	return 0;
}

void create_adr_wall(t_win	*win, t_template *temp)
{
	temp->img = mlx_xpm_file_to_image(win->mlx, temp->name, &temp->width, &temp->height);
	printf("%d %d\n", temp->width, temp->height);
	temp->buffer = (int *) mlx_get_data_addr(temp->img, &temp->pixel_bits, &temp->line_bytes, &temp->endian);
}

void create_mini_wall(t_win *win)
{
	win->map.wall.width = WIDTH_MINI;
	win->map.wall.height = WIDTH_MINI;
	win->map.wall.img = mlx_new_image(win->mlx, win->map.wall.width, win->map.wall.height);
	win->map.wall.buffer = (int *)mlx_get_data_addr(win->map.wall.img, &win->map.wall.pixel_bits, &win->map.wall.line_bytes, &win->map.wall.endian);

	for (int y = 0; y < win->map.wall.height; y++)
		for (int x = 0; x < win->map.wall.width; x++)
		{
			if (y == WIDTH_MINI - 1 || x == WIDTH_MINI - 1)
				win->map.wall.buffer[x + y * win->map.wall.width] = DARKGREEN;
			else
				win->map.wall.buffer[x + y * win->map.wall.width] = INDIANRED;
		}
}

void create_mini_floor(t_win *win)
{
	win->map.floor.width = WIDTH_MINI;
	win->map.floor.height = WIDTH_MINI;
	win->map.floor.img = mlx_new_image(win->mlx, win->map.floor.width, win->map.floor.height);
	win->map.floor.buffer = (int *)mlx_get_data_addr(win->map.floor.img, &win->map.floor.pixel_bits, &win->map.floor.line_bytes, &win->map.floor.endian);
	for (int y = 0; y < win->map.floor.height; y++)
		for (int x = 0; x < win->map.floor.width; x++)
		{
			win->map.floor.buffer[x + y * win->map.floor.width] = RED;
		}
}

void create_mini_transparent(t_win *win)
{
	win->map.transparent.width = WIDTH_MINI;
	win->map.transparent.height = WIDTH_MINI;
	win->map.transparent.img = mlx_new_image(win->mlx, win->map.transparent.width, win->map.transparent.height);
	win->map.transparent.buffer = (int *)mlx_get_data_addr(win->map.transparent.img, &win->map.transparent.pixel_bits, &win->map.transparent.line_bytes, &win->map.transparent.endian);
	for (int y = 0; y < win->map.floor.height; y++)
		for (int x = 0; x < win->map.floor.width; x++)
		{
			win->map.transparent.buffer[x + y * win->map.transparent.width] = TRANSPARENT;
		}
}

void inicialization_minimap(t_win *win)
{
	create_mini_wall(win);
	create_mini_floor(win);
	create_mini_transparent(win);
	win->map.map.width = win->maps->width * WIDTH_MINI;
	win->map.map.height = win->maps->height * WIDTH_MINI;

	win->map.map.img = mlx_new_image(win->mlx, win->maps->width * WIDTH_MINI, win->maps->height * WIDTH_MINI);
	win->map.map.buffer = (int *) mlx_get_data_addr(win->map.map.img, &win->map.map.pixel_bits, &win->map.map.line_bytes, &win->map.map.endian);
	for (int y = 0; y < win->map.map.height / WIDTH_MINI; y++)
	{
		for (int x = 0; x < win->map.map.width / WIDTH_MINI; x++)
		{
			if (worldMap[y][x] == 1)
				setImgtoTemplate(&win->map.map, &win->map.wall, x * WIDTH_MINI, y * WIDTH_MINI);
			else if (worldMap[y][x] == 0)
				setImgtoTemplate(&win->map.map, &win->map.floor, x * WIDTH_MINI, y * WIDTH_MINI);
			else
				setImgtoTemplate(&win->map.map, &win->map.transparent, x * WIDTH_MINI, y * WIDTH_MINI);
		}
	}

}

void create_hero(t_win *win)
{
	win->hero.temp.width = WIDHT_HERO;
	win->hero.temp.height = WIDHT_HERO;
	win->hero.temp.img = mlx_new_image(win->mlx, win->hero.temp.width, win->hero.temp.height);
	win->hero.temp.buffer = (int *) mlx_get_data_addr(win->hero.temp.img, &win->hero.temp.pixel_bits, &win->hero.temp.line_bytes, &win->hero.temp.endian);
	for (int y = 0; y < win->hero.temp.height; y++)
		for (int x = 0; x < win->hero.temp.width; x++)
			win->hero.temp.buffer[y * win->hero.temp.width + x] = BLUE;
}



int main(){
	t_win		win;

	win.maps = parser_map("map.cub");
	int i = 0;
	if (win.maps == NULL)
		return 0;
	win.maps->width = 10;
	win.maps->height = 24;
	win.maps->x = 1.5;
	win.maps->y = 1.5;
	win.mlx = mlx_init();
	win.temp.width = screenWidth;
	win.temp.height = screenHeight;
	win.temp.img = mlx_new_image(win.mlx, screenWidth, screenHeight);
	win.temp.buffer = (int *) mlx_get_data_addr(win.temp.img, &win.temp.pixel_bits, &win.temp.line_bytes, &win.temp.endian);
	win.win = mlx_new_window(win.mlx, screenWidth, screenHeight, "cub3d");
	win.player.posX = win.maps->x;
	win.player.posY = win.maps->y;

	//смотрим на юг
//	win.player.dirX = 1.0;
//	win.player.dirY = 0.0;
//	win.player.planeX = 0;
//	win.player.planeY = -0.66;

//nor
//	win.player.dirX = -1.0;
//	win.player.dirY = 0.0;
//	win.player.planeX = 0;
//	win.player.planeY = 0.66;


//west
//	win.player.dirX = 0;
//	win.player.dirY = -1.0;
//	win.player.planeX = -0.66;
//	win.player.planeY = 0;

//east
	win.player.dirX = 0;
	win.player.dirY = 1.0;
	win.player.planeX = 0.66;
	win.player.planeY = 0;
	win.player.time = 0;
	win.player.oldTime = 0;
	win.player.moveSpeed = 0.2;
	win.player.rotSpeed =  0.1;
	win.W.name = win.maps->west;
	win.S.name = win.maps->south;
	win.E.name = win.maps->east;
	win.N.name = win.maps->north;

	create_adr_wall(&win, &win.W);
	create_adr_wall(&win, &win.S);
	create_adr_wall(&win, &win.N);
	create_adr_wall(&win, &win.E);
//	printf("%d %d\n", win.W.height, win.W.width);
	create_hero(&win);
	inicialization_minimap(&win);
	drawall(&win);
	mlx_hook(win.win, 2, 1L << 0, pressButton, &win);
	mlx_loop(win.mlx);
}