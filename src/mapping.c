#include "../include/wolf3d.h"

void mapping(t_param *p)
{
 int x;

 x = 0;
 mapping_init(p);
 p->square_initX = (int)p->init_posX;
 p->square_initY = (int)p->init_posY;
 while (x < p->width)
 {
  p->rayPosX = p->init_posX;
  p->rayPosY = p->init_posY;
  p->view = 2 * x / (double)p->width - 1;
  p->rayDirX = p->dirX + p->planeX * p->view;
  p->rayDirY = p->dirY + p->planeY * p->view;
  p->deltaDistX = sqrt(pow(1, 2) + (pow(p->rayDirY, 2) / pow(p->rayDirX, 2)));
  p->deltaDistY = sqrt(pow(1, 2) + (pow(p->rayDirX, 2) / pow(p->rayDirY, 2)));
  find_a_wall(p);
  draw_a_wall(x, p);
  x++;
 }
}
