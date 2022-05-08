#include "../incs/struct_map.h"
#include "../incs/mlx.h"
#include "math.h"
#include "../incs/parse_map.h"
#include <string.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1920
#define screenHeight 1080
#define RED 0xF0FF0000
#define BLUE 0x000000FF
#define GREEN 0x0000FF00
#define WHITE 0x00FFFFFF
#define YELLOW 0x00FFFF00
#define BLACK 0x00000000
#define DARKGREEN 0x88006400
#define INDIANRED 0x88CD5C5C
#define TRANSPARENT 0xFF000000
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define WIDTH_MINI 16

typedef struct s_img{
	double posX;  //x and y start position
	double dirX; //initial direction vector
	double planeX;
	double planeY; //the 2d raycaster version of camera plane
	double dirY;
	double posY;
	double time; //time of current frame
	double oldTime; //time of previous frame
	double moveSpeed;
	double rotSpeed;
}	t_img;

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

typedef struct s_line{
	int x0;
	int x1;
	int y0;
	int y1;
	int color;
}	t_line;

typedef struct s_minimap{
	t_template	map;
	t_template	wall;
	t_template	floor;
	t_template	transparent;
}	t_minimap;

typedef struct s_win{
	void		*mlx;
	void		*win;
	t_template	temp;
	t_img		player;
	t_line		line;
	t_template	N;
	t_template	S;
	t_template	W;
	t_template	E;
	t_minimap 	map;
} t_win;



int worldMap[mapWidth][mapHeight] =
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

void color_in_template(t_template *temp)
{
	for (int y = 0; y < screenHeight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
		temp->buffer[x + y * screenWidth] = BLACK;
	}

}

void drawfullline(t_win *win, t_line *line)
{
	int x_err = 0, y_err = 0;
	int dx = line->x1 - line->x0; int dy = line->y1 - line->y0; //px/py - начальные точки x1/y1 конечные
	int incX = 0; int incY = 0;
	if (dx>0) {incX=1; }else if (dx!=0) incX=-1;
	if (dy>0) {incY=1; }else if (dy!=0) incY=-1;
	dx = abs(dx);
	dy = abs(dy);
	int d;
	if (dx > dy)
		d = dx;
	else
		d = dy;
	float x = (float)line->x0;
	float y = (float)line->y0;
//	mlx_put_image_to_window(image->mlx, image->win, line->image,x, y);
//	printf("%d %d\n", line->y1, line->y0);
	for (int i = 1; i <= d; i++){
		x_err +=dx;
		y_err += dy;
		if (x_err>=d)
		{
			x+=incX;
			x_err-=d;
		}
		if (y_err >= d){
			y+=incY;
			y_err-=d;
		}
		win->temp.buffer[(int)x + (int)y * screenWidth] = line->color;
//		printf("%d \n", (int)y);
	}
}

void raycast(t_win *win, t_img *player){
	for (int x = 0; x < screenWidth; x++){
		double cameraX = (2 * x / (double)screenWidth - 1);
		double rayDirX = (double)player->dirX + (double)player->planeX * (double)cameraX;
		double rayDirY = (double)player->dirY + (double)player->planeY * (double)cameraX;
		int mapX = (int)player->posX;
		int mapY = (int)player->posY;
		double sideDistX;
		double sideDistY;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->posY) * deltaDistY;
		}
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if(drawEnd >= screenHeight) drawEnd = screenHeight - 1;

		//textures
		int texNum = worldMap[mapX][mapY];
		double wallX;
		if(side == 0)
			wallX = player->posY + perpWallDist * rayDirY;
		else
			wallX = player->posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		int texX = (int)(wallX * (double)(win->W.width));
		if(side == 0 && rayDirX > 0) texX = win->W.width - texX - 1;
		if(side == 1 && rayDirY < 0) texX = win->W.width - texX - 1;
		double step = 1.0 * win->W.width / lineHeight;
		double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++){
			int texY = (int)texPos & (win->W.height - 1);
			texPos += step;
			if (side == 0 && rayDirX >= 0)
				win->temp.buffer[x + y * screenWidth] = win->W.buffer[win->W.width * texY + texX];
			else if (side == 0 && rayDirX < 0)
				win->temp.buffer[x + y * screenWidth] = win->S.buffer[win->S.width * texY + texX];
			else if (side == 1 && rayDirY < 0)
				win->temp.buffer[x + y * screenWidth] = win->E.buffer[win->E.width * texY + texX];
			else if (side == 1 && rayDirY >= 0)
				win->temp.buffer[x + y * screenWidth] = win->N.buffer[win->N.width * texY + texX];
		}
	}
	player->moveSpeed = 0.2;
	player->rotSpeed =  0.1;
}
void drawminimap(t_win *win)
{
	for (int y = 0; y < win->map.map.width; y++){
		for (int x = 0; x < win->map.map.height; x++){
			win->temp.buffer[x + y * screenWidth] = win->map.map.buffer[x + y * win->map.map.width];
		}
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

int pressButton(int key, t_win *win){
	if (key == KEY_W)
	{
		if (worldMap[(int)(win->player.posX + win->player.dirX * win->player.moveSpeed)][(int)win->player.posY] == 0)
			win->player.posX += win->player.dirX * win->player.moveSpeed;
		if(worldMap[(int)win->player.posX][(int)(win->player.posY + win->player.dirY * win->player.moveSpeed)] == 0)
			win->player.posY += win->player.dirY * win->player.moveSpeed;
	}
	if (key == KEY_S)
	{
		if(worldMap[(int)(win->player.posX - win->player.dirX * win->player.moveSpeed)][(int)(win->player.posY)] == 0)
			win->player.posX -= win->player.dirX * win->player.moveSpeed;
		if(worldMap[(int)(win->player.posX)][(int)(win->player.posY - win->player.dirY * win->player.moveSpeed)] == 0)
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
	color_in_template(&win->temp);
	raycast(win, &win->player);
//	setImgtoTemplate(&win->temp, &win->map.map, 0, 0);
	mlx_clear_window(win->mlx, win->win);
	mlx_put_image_to_window(win->mlx, win->win, win->temp.img, 0, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->map.map.img, 0, 0);
	return 0;
}

void create_adr_wall(t_win	*win, t_template *temp)
{
	temp->img = mlx_xpm_file_to_image(win->mlx, temp->name, &temp->width, &temp->height);
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
	win->map.map.width = mapWidth * WIDTH_MINI;
	win->map.map.height = mapHeight * WIDTH_MINI;
	win->map.map.img = mlx_new_image(win->mlx, mapWidth * WIDTH_MINI, mapHeight * WIDTH_MINI);
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

int main(){
	t_win		win;

	win.mlx = mlx_init();
	win.temp.width = screenWidth;
	win.temp.height = screenHeight;
	win.temp.img = mlx_new_image(win.mlx, screenWidth, screenHeight);
	win.temp.buffer = (int *) mlx_get_data_addr(win.temp.img, &win.temp.pixel_bits, &win.temp.line_bytes, &win.temp.endian);
	win.win = mlx_new_window(win.mlx, screenWidth, screenHeight, "cub3d");
	win.player.posX = 1.5;
	win.player.posY = 1.5;
	win.player.dirX = 1.0;
	win.player.dirY = 0.0;
	win.player.planeX = 0;
	win.player.planeY = -0.66;
	win.player.time = 0;
	win.player.oldTime = 0;
	win.W.name = "textures/banner.xpm";
	win.S.name = "textures/brick.xpm";
	win.E.name = "textures/1.xpm";
	win.N.name = "textures/door.xpm";


	create_adr_wall(&win, &win.W);
	create_adr_wall(&win, &win.S);
	create_adr_wall(&win, &win.E);
	create_adr_wall(&win, &win.N);
//	printf("%d %d\n", win.W.height, win.W.width);
	inicialization_minimap(&win);

	color_in_template(&win.temp);
	raycast(&win, &win.player);
//	setImgtoTemplate(&win.temp, &win.map.map, 0, 0);
	mlx_put_image_to_window(win.mlx, win.win, win.temp.img, 0, 0);
	mlx_put_image_to_window(win.mlx, win.win, win.map.map.img, 0, 0);
	mlx_hook(win.win, 2, 1L << 0, pressButton, &win);
	mlx_loop(win.mlx);
}