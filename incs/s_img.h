//
// Created by John Nappa on 5/10/22.
//

#ifndef QWE_S_IMG_H
#define QWE_S_IMG_H

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

#endif //QWE_S_IMG_H
