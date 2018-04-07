#include "../include/wolf3d.h"

void init_param(t_param *p)
{
 p->ud = 0;
 p->lr = 0;
 p->run = 0;
 p->alt = 1;
 p->nb_lines = 0;
 p->nb_chars = 0;
 p->total_chars = 0;
 p->fd = 0;
 p->ret = 0;
 p->line = NULL;
 p->bpp = 8 * 4;
 p->height = 1000;
 p->width = 1000;
 p->sz_ln = 4 * p->width;
 p->endian = 0;
 p->patate = 0;
 p->init_posX = 5; // TO_DO definir position en fonction de la map(centre)
 p->init_posY = 5; // TO_DO definir position en fonction de la map(centre)

}

void mapping_init(t_param *p)
{
 p->dirX = -1;
 p->dirY = 0;
 p->planeX = 0;
 p->planeY = 0.66;
 p->view = 0;
 p->rayPosX = 0;
 p->rayPosY = 0;
 p->rayDirX = 0;
 p->rayDirY = 0;
 p->wallDistX = 0;
 p->wallDistY = 0;
 p->square_initX = 0;
 p->square_initY = 0;
 p->stepX = 0;
 p->stepY = 0;
 p->wallDetect = 0;
 p->compas = 0;
 p->correc_dist = 0;
 p->wall_height = 0;
 p->draw_start = 0;
 p->draw_end = 0;
 p->deltaDistX = 0;
 p->deltaDistY = 0;
 p->move_speed = 0.1;
 p->rot_speed = 0.1;
 p->old_dirX = 0;
 p->old_dirY = 0;
}
