#include "../incs/struct_map.h"
#include "../incs/mlx.h"
#include "math.h"

#define PI 3.1415926535
#define P2 PI/2
#define P3 3 * P2
#define DR 0.0174533

typedef struct s_line{
	int x0;
	int y0;
	int x1;
	int y1;
	int color;
	int height;
	int width;
	void *image;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
} t_line;

typedef struct s_map{
	double px;
	double py;
	void *image;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}t_map;

typedef struct		s_img
{
	void	*mlx;
	void	*win;
	double px;
	double py;
	double pdx;
	double pdy;
	double pa;

	void		*image;
	char		*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	t_line	line;
	t_map map[64];
	t_line	d3;
}	t_img;



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

void drawfullline(t_line *line, t_img *image)
{
	int x_err = 0, y_err = 0;
	int dx = line->x1 - line->x0; int dy = line->y1 - line->y0;
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
	int x = line->x0;
	int y = line->y0;
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
		if (i % 5 == 1)
		mlx_put_image_to_window(image->mlx, image->win, line->image,x, y);
	}
}

void makecolor(t_line *line)
{
	for (int y = 0; y < line->height; y++)
	{
		for (int x = 0; x < line->width; x++)
		{
			int pixel = (y * line->line_bytes) + (x * 4);
			line->buffer[pixel + 0] =(line->color) & 0xFF;
			line->buffer[pixel + 1] =(line->color >> 8) & 0xFF;
			line->buffer[pixel + 2] =(line->color >> 16) & 0xFF;
			line->buffer[pixel + 3] =(line->color >> 24);
		}
	}
}

float dist(float ax, float ay, float bx, float by, float ang)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

int drawXRay(t_img *img, t_line *line){

	line->x0 = img->px + 5 - line->width / 2;
	line->y0 = img->py + 5 - line->height / 2;
	int r, mx, my, mp, dof;
	float  rx, ry, ra, xo, yo, disT;
	ra = img->pa;
	int disH, hx, hy;
	int disV, vx, vy;
	ra = img->pa - DR * 30 ;
	if (ra < 0){
		ra+=2*PI;
	}
	if (ra >2 * PI)
	{
		ra -=2*PI;
	}
	for (r = 0; r < 60; r++){
		dof = 0;
		disH = 1000000, hx = img->px, hy = img->py;
		float aTan =-1/ tan(ra);
		if (ra > PI) {
			ry = (((int)img->py>>6)<<6)-0.0001;
			rx = (img->py - ry) * aTan+img->px;
			yo = -64; xo = -yo*aTan;
		}
		if (ra < PI) {
			ry = (((int)img->py>>6)<<6)+64;
			rx = (img->py - ry) * aTan + img->px;
			yo = 64; xo = -yo*aTan;
		}
		if (ra == 0 || ra == PI){
			rx = img->px; ry = img->py; dof = 8;
		}
		while (dof < 8){
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX+mx;
			if (mp > 0 && mp<mapX*mapY && mapq[mp] == 1) {hx = rx; hy = ry; disH = dist(img->px , img->py, hx , hy, ra); dof = 8;}
			else {rx+=xo; ry+=yo; dof++;}
		}
		dof = 0;
		disV = 1000000, vx = img->px, vy = img->py;
		float nTan =-tan(ra);
		if (ra > P2 && ra<P3) {
			rx = (((int)img->px>>6)<<6)-0.0001;
			ry = (img->px - rx) * nTan+img->py;
			xo = -64; yo = -xo*nTan;
		}
		if (ra < P2 || ra > P3) {
			rx = (((int)img->px>>6)<<6)+64;
			ry = (img->px - rx) * nTan + img->py;
			xo = 64; yo = -xo*nTan;
		}
		if (ra == 0 || ra == PI){
			rx = img->px; ry = img->py; dof = 8;
		}
		while (dof < 8){
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX+mx;
			if (mp > 0 && mp<mapX*mapY && mapq[mp] == 1) {vx = rx; vy = ry; disV = dist(img->px , img->py, vx , vy, ra);dof = 8;}
			else {rx+=xo; ry+=yo; dof++;}
		}
		if (disV < disH){
			rx = vx;
			ry = vy;
			disT = disV;
		}
		if (disV > disH)
		{
			rx = hx;
			ry = hy;
			disT = disH;
		}
		line->x1 = rx;
		line->y1 = ry;
		ra +=DR;
		if (ra < 0){
			ra+=2*PI;
		}
		if (ra >2 * PI)
		{
			ra -=2*PI;
		}
		float ca = img->pa - ra;
		if (ca < 0){
			ca+=2*PI;
		}
		if (ca >2 * PI)
		{
			ca -=2*PI;
		}
		disT = disT * cos(ca);
		float lineH = (mapS * 320) / disT;
		if (lineH > 320)
			lineH = 320;
		float lineO = 160 - lineH / 2;
		img->d3.x0 = r * 8 + 530;
		img->d3.y0 = lineO;
		img->d3.x1 = r * 8 + 530;
		img->d3.y1 = lineH + lineO;

		drawfullline(&img->d3, img);
		drawfullline(line, img);
	}
	return (1);
}

int drawline(t_img *image, t_line *line1){
//	t_line line;
//	line.color = 0xFF0000;
//	line.height = 3;
//	line.width = 3;
//	line.image = mlx_new_image(image->mlx, line.width, line.height);
//	line.buffer = mlx_get_data_addr(line.image, &line.pixel_bits, &line.line_bytes, &line.endian);
//	makecolor(&line);
//	line.x0 = image->px + 5 - line.width / 2;
//	line.x1 = (image->px + image->pdx * 5) + 5 - line.width / 2;
//	line.y0 = image->py + 5 - line.height / 2;
//	line.y1 = (image->py + image->pdy * 5) + 5 - line.height / 2;
	drawXRay(image, line1);
//	drawfullline(&line, image);
	return 1;
}

int drawMap(t_img *img){
	for (int i = 0; i < 64; i++)
		mlx_put_image_to_window(img->mlx, img->win, img->map[i].image, img->map[i].px, img->map[i].py);
	return 0;
}

int pressButton(int key, t_img *img){
	if (key == 2){
		img->pa+=0.1;
		if (img->pa > PI * 2){
			img->pa -= PI * 2;
		}
		img->pdx = cos(img->pa) * 5;
		img->pdy = sin(img->pa) * 5;
	}
	if (key == 0){
		img->pa-=0.1;
		if (img->pa < 0){
			img->pa += PI * 2;
		}
		img->pdx = cos(img->pa) * 5;
		img->pdy = sin(img->pa) * 5;
	}
	if (key == 1){
		img->px-=img->pdx;
		img->py-=img->pdy;
	}
	if (key == 13){
		img->px+=img->pdx;
		img->py+=img->pdy;
	}
	mlx_clear_window(img->mlx, img->win);
	drawMap(img);
	mlx_put_image_to_window(img->mlx, img->win, img->image, img->px, img->py);
	drawline(img, &img->line);
	return 0;
}

void createpixel(t_img *img, t_line *line){
	line->color = 0x00FF00;
	line->width = 1;
	line->height = 1;
	line->image = mlx_new_image(img->mlx, line->width, line->height);
	line->buffer = mlx_get_data_addr(line->image, &line->pixel_bits, &line->line_bytes, &line->endian);
}

void makemap(t_img *img)
{
	int black = 0xFFA500;
	int white = 0xFFC0CB;
	for (int i = 0; i < 64; i++)
	{
		img->map[i].image = mlx_new_image(img->mlx, 64 - 1, 64 - 1);
		img->map[i].buffer = mlx_get_data_addr(img->map[i].image, &img->map[i].pixel_bits, &img->map[i].line_bytes, &img->map[i].endian);
	}
	for (int j = 0; j < 64; j++)
	{
		for(int y = 0; y < 64; ++y){
			for(int x = 0; x < 64; ++x)
			{
				int pixel = (y * img->map[j].line_bytes) + (x * 4);
				if (mapq[j] == 1)
				{
					img->map[j].buffer[pixel + 0] = (black) & 0xFF;
					img->map[j].buffer[pixel + 1] = (black >> 8) & 0xFF;
					img->map[j].buffer[pixel + 2] = (black >> 16) & 0xFF;
					img->map[j].buffer[pixel + 3] = (black >> 24);
				} else
				{
					img->map[j].buffer[pixel + 0] = (white) & 0xFF;
					img->map[j].buffer[pixel + 1] = (white >> 8) & 0xFF;
					img->map[j].buffer[pixel + 2] = (white >> 16) & 0xFF;
					img->map[j].buffer[pixel + 3] = (white >> 24);
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

void create3d(t_img *img)
{
	img->d3.color = 0x9400D3;
	img->d3.height = 8;
	img->d3.width = 8;
	img->d3.image = mlx_new_image(img->mlx, img->d3.width, img->d3.height);
	img->d3.buffer = mlx_get_data_addr(img->d3.image, &img->d3.pixel_bits, &img->d3.line_bytes, &img->d3.endian);
	makecolor(&img->d3);
}

int main()
{

	t_img img;
	img.px = 300;
	img.py = 300;
	img.pa = 0;
	img.pdx = cos(img.pa) * 5;
	img.pdy = sin(img.pa) * 5;


	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1024, 512, "Tutorial Window - Create Image");

	createpixel(&img, &img.line);
	create3d(&img);
	makecolor(&img.line);
	img.image = mlx_new_image(img.mlx, 10, 10);
	makemap(&img);

	img.buffer = mlx_get_data_addr(img.image, &img.pixel_bits, &img.line_bytes, &img.endian);

	int color = 0xABCDEF;

	if (img.pixel_bits != 32)
		color = mlx_get_color_value(img.mlx, color);

	for(int y = 0; y < 10; ++y)
		for(int x = 0; x < 10; ++x)
		{
			int pixel = (y * img.line_bytes) + (x * 4);
			img.buffer[pixel + 0] = (color) & 0xFF;
			img.buffer[pixel + 1] = (color >> 8) & 0xFF;
			img.buffer[pixel + 2] = (color >> 16) & 0xFF;
			img.buffer[pixel + 3] = (color >> 24);
		}
	mlx_put_image_to_window(img.mlx, img.win, img.image, img.px, img.py);
	drawMap(&img);
	mlx_hook(img.win, 2, 1L << 0, pressButton, &img);
	mlx_loop(img.mlx);
}