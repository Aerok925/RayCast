#include "../incs/struct_map.h"
#include "../incs/mlx.h"
#include "math.h"
#include "../incs/parse_map.h"

#define PI 3.1415926535
#define P2 PI/2
#define P3 3 * P2
#define DR 0.0174533

typedef struct s_template{
	int		height;
	int		width;
	void	*img;
	int	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
} t_template;

typedef struct s_img{
	int		color;
	float	px;
	float	py;
	void	*img;
	int		*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	float		x1;
	float		y1;
	int		width;
	int		height;
	float	pdx;
	float	pdy;
	float	pa;
} t_img;

typedef struct s_win{
	void		*mlx;
	void		*win;
	t_template	temp;
	t_img		player;
	t_img		map[64];
	t_img		line;
	t_img		wall;
} t_win;

int mapX = 8, mapY = 8, mapS = 64;
int mapq[] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
};

void setImgtoTemplate(t_img *img, t_template *temp)
{
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
		{
			temp->buffer[(int)(y + img->py) * temp->width + (int)(x + img->px)] = img->buffer[y * img->width + x ];
		}
	}
}

void drawfullline(t_win *win, t_img *img)
{
	int x_err = 0, y_err = 0;
	int dx = img->x1 - img->px; int dy = img->y1 - img->py;
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
//	printf("%d \n ", d);
	float x = img->px;
	float y = img->py;
//	mlx_put_image_to_window(image->mlx, image->win, line->image,x, y);
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
		float defx, defy;
		defx = img->px;
		defy = img->py;
		img->px = x;
		img->py = y;
		setImgtoTemplate(img, &win->temp);
		img->px = defx;
		img->py = defy;
	}
}

float dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}




int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void templateBlack(t_template *temp){
	int color = 0x000000;
//	int white = 0xFFFFFF;
	for (int y = 0; y < temp->height; y++)
	{
		for (int x = 0; x < temp->width; x++)
		{
			temp->buffer[y * temp->width + x] = color;
		}
	}
}

void makecolor(t_img *line)
{
	for (int y = 0; y < line->height; y++)
		for (int x = 0; x < line->width; x++)
			line->buffer[y * line->height + x] = line->color;
}

void setImgtoTemplate123(t_template *temp, t_img *img, int qwe )
{
//	for (int y = 0; y < 8; y++)
		for (int x = 0; x < qwe; x++)
		temp->buffer[((int)img->px + x) + ((int)img->py) * temp->width] = img->buffer[(int)img->x1 + (int)x ];
}


int drawXRay(t_win *win){

	win->line.px = win->player.px + 5 - win->line.width / 2;
	win->line.py = win->player.py + 5 - win->line.height / 2;
	int r, mx, my, mp, dof;
	float  rx, ry, ra, xo, yo, disT;
	ra = win->player.pa;
	int disH, hx, hy;
	int disV, vx, vy;
	ra = win->player.pa - DR * 30;
	if (ra < 0){
		ra+=2*PI;
	}
	if (ra >2 * PI)
	{
		ra -=2*PI;
	}
	for (r = 0; r < 60; r++){
//		printf("%f \n", ra);
		dof = 0;
		disH = 1000000, hx = win->player.px, hy = win->player.py;
		float aTan =-1/ tan(ra);
		if (ra > PI) {
			ry = (((int)win->player.py>>6)<<6)-0.0001;
			rx = (win->player.py - ry) * aTan+win->player.px;
			yo = -64; xo = -yo*aTan;
		}
		if (ra < PI) {
			ry = (((int)win->player.py>>6)<<6)+64;
			rx = (win->player.py - ry) * aTan + win->player.px;
			yo = 64; xo = -yo*aTan;
		}
		if (ra == 0 || ra == PI){
			rx = win->player.px; ry = win->player.py; dof = 8;
		}
		while (dof < 8){
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX+mx;
			if (mp > 0 && mp<mapX*mapY && mapq[mp] == 1) { hx = rx; hy = ry; disH = dist(win->player.px , win->player.py, hx , hy); dof = 8;}
			else {rx+=xo; ry+=yo; dof++;}
		}
		dof = 0;
		disV = 1000000, vx = win->player.px, vy = win->player.py;
		float nTan =-tan(ra);
		if (ra > P2 && ra<P3) {
			rx = (((int)win->player.px>>6)<<6)-0.0001;
			ry = (win->player.px - rx) * nTan+win->player.py;
			xo = -64; yo = -xo*nTan;
		}
		if (ra < P2 || ra > P3) {
			rx = (((int)win->player.px>>6)<<6)+64;
			ry = (win->player.px - rx) * nTan + win->player.py;
			xo = 64; yo = -xo*nTan;
		}
		if (ra == 0 || ra == PI){
			rx = win->player.px; ry = win->player.py; dof = 8;
		}
		while (dof < 8){
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX+mx;
			if (mp > 0 && mp<mapX*mapY && mapq[mp] == 1) {vx = rx; vy = ry; disV = dist(win->player.px , win->player.py, vx , vy);dof = 8;}
			else {rx+=xo; ry+=yo; dof++;}
		}
		float shade = 1;
		if (disV < disH){
			rx = vx;
			ry = vy;
			disT = disV;
			shade = 0.5;
		}
		if (disV >= disH)
		{
			rx = hx;
			ry = hy;
			disT = disH;
		}
		win->line.x1 = rx;
		win->line.y1 = ry;
		ra +=DR;
		if (ra < 0){
			ra+=2*PI;
		}
		if (ra >2 * PI)
		{
			ra -=2*PI;
		}
		float ca = win->player.pa - ra;
		if (ca < 0){
			ca+=2*PI;
		}
		if (ca >2 * PI)
		{
			ca -=2*PI;
		}
		disT = disT * cos(ca);
		float lineH = (mapS * 512) / disT;
		float ty_step = 64.0 / (float)lineH;
		float ty_off = 0;
		if (lineH > 512)
		{
			ty_off = (lineH-512) / 2.0;
			lineH = 512;
		}
		float lineO = 256 - lineH / 2;
		float ty = ty_off * ty_step;
		float tx;
		if (shade == 1)
		{tx = (int)((rx / 2.0))%32;}
		else
			tx = (int)((ry / 2.0))%32;
//		printf("%f \n", ty);
		for (int y = 0; y < lineH; y++){
//			printf("%f \n", lineH);
				win->wall.px = r * 8  + 512;
				win->wall.py = y + lineO;
				win->wall.x1 = (int)(ty) * 64 + (int)tx ;
				win->wall.color = win->wall.buffer[(int)win->wall.x1];
				//			printf("%f \n", win->wall.x1);
				setImgtoTemplate123(&win->temp, &win->wall, 7);

//			setImgtoTemplate(&win->wall, &win->temp);
			ty+=ty_step;
		}

		drawfullline(win, &win->line);

	}
	return (1);
}

int drawline(t_win *win){
	win->line.px = win->player.px + 5 - win->line.width / 2;
	win->line.x1 = (win->player.px + win->player.pdx * 5) + 5 - win->line.width / 2;
	win->line.py = win->player.py + 5 - win->line.height;
	win->line.y1 = (win->player.py + win->player.pdy * 5) + 5 - win->line.height;
//	drawfullline(win, &win->line);
	drawXRay(win);
	return 1;
}


void makemap(t_win *img)
{
	int black = 0x00FF0000;
	int white = 0x00FFFFFF;
	for (int i = 0; i < 64; i++)
	{
		img->map[i].width = 63;
		img->map[i].height = 63;
		img->map[i].img = mlx_new_image(img->mlx, 64 - 1, 64 - 1);
		img->map[i].buffer = (int *)mlx_get_data_addr(img->map[i].img, &img->map[i].pixel_bits, &img->map[i].line_bytes, &img->map[i].endian);
	}
	for (int j = 0; j < 64; j++)
	{
		for(int y = 0; y < 64; ++y){
			for(int x = 0; x < 64; ++x)
			{
				if (mapq[j] == 1)
				{
					img->map[j].buffer[y * img->map[j].width + x ] = black;
				} else
				{
					img->map[j].buffer[y * img->map[j].width + x ] = white;
				}
			}
		}
	}
	for (int y = 0; y < 8; y++){
		for (int x = 0; x < 8;x++)
		{
			img->map[y * mapX + x].px = (double)x * (double)64;
			img->map[y * mapX + x].py = (double)y * (double)64;
		}
	}
}

int drawMap(t_win *img){
	for (int i = 0; i < 64; i++)
		setImgtoTemplate(&img->map[i], &img->temp);
	return 0;
}

int pressButton(int key, t_win *win){
	if (key == 2){
		win->player.pa+=0.1;
		if (win->player.pa > PI * 2){
			win->player.pa -= PI * 2;
		}
		win->player.pdx = cos(win->player.pa) * 5;
		win->player.pdy = sin(win->player.pa) * 5;
	}
	if (key == 0){
		win->player.pa-=0.1;
		if (win->player.pa < 0){
			win->player.pa += PI * 2;
		}
		win->player.pdx = cos(win->player.pa) * 5;
		win->player.pdy = sin(win->player.pa) * 5;
	}
	if (key == 1){
		win->player.px-=win->player.pdx;
		win->player.py-=win->player.pdy;
	}
	if (key == 13){
		win->player.px+=win->player.pdx;
		win->player.py+=win->player.pdy;
	}
	if (key == 53)
		exit(1);
	mlx_clear_window(win->mlx, win->win);
	templateBlack(&win->temp);
	drawMap(win);
	drawline(win);
	setImgtoTemplate(&win->player, &win->temp);
	mlx_put_image_to_window(win->mlx, win->win, win->temp.img, 0, 0);
	return 0;
}

int main()
{
	t_win win;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1024, 512, "Tutorial Window - Create Image");
	win.temp.width = 1024;
	win.temp.height = 512;
	win.temp.img = mlx_new_image(win.mlx, win.temp.width, win.temp.height);
	win.temp.buffer = (int *)mlx_get_data_addr(win.temp.img, &win.temp.pixel_bits, &win.temp.line_bytes, &win.temp.endian);
	templateBlack(&win.temp);
	win.player.width = 10;
	win.player.height = 10;
	win.player.color = 0x0000FF00;
	win.player.px = 70;
	win.player.py = 70;
	win.player.pdx = cos(win.player.pa) * 5;
	win.player.pdy = sin(win.player.pa) * 5;
	win.player.pa = 0;
	win.player.img = mlx_new_image(win.mlx, win.player.width, win.player.height);
	win.player.buffer = (int *)mlx_get_data_addr(win.player.img, &win.player.pixel_bits, &win.player.line_bytes, &win.player.endian);
	win.line.height = 1;
	win.line.width = 1;
	win.line.color = 0x000000FF;
	win.line.img = mlx_new_image(win.mlx, win.line.width, win.line.height);
	win.line.buffer = (int *)mlx_get_data_addr(win.line.img, &win.line.pixel_bits, &win.line.line_bytes, &win.line.endian);
	win.wall.height = 8;
	win.wall.width = 8;
	win.wall.color = 0x00FF00FF;
	int a, b;
	void *qwe = mlx_xpm_file_to_image(win.mlx, "textures/brick.xpm", &a, &b);
	win.wall.img = mlx_new_image(win.mlx, a, b);
	win.wall.buffer = (int *)mlx_get_data_addr(qwe, &win.wall.pixel_bits, &win.wall.line_bytes, &win.wall.endian);
//	makecolor(&win.wall);

	makecolor(&win.line);
	makemap(&win);
	drawMap(&win);
	makecolor(&win.player);
	setImgtoTemplate(&win.player, &win.temp);
	drawline(&win);
	mlx_put_image_to_window(win.mlx, win.win, win.temp.img, 0, 0);
	mlx_hook(win.win, 2, 1L << 0, pressButton, &win);
	mlx_loop(win.mlx);
}
