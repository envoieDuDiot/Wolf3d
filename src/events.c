#include "../include/wolf3d.h"

int closing(t_param *p)
{
	exit(0);
	return (0);
}

void resize(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_destroy_window(p->mlx, p->win);
	mlx_stuff(p);
}

int keycool(int k, t_param *p)
{
 printf("k[%d]\t", k);
 if (k == ESC)
  exit(0);
	// if (k = FRONT)
	// {
	// 	p->stepX = 1;
	// 	p->wallDistX = (p->square_initX + 1 - p->init_posX) * p->deltaDistX;
	// }
	// if (k == BACK)
	// {
	// 	if (p->rayDirX < 0)
	// 	{
	// 		p->stepX = -1;
	// 		p->wallDistX = (p->init_posX - p->square_initX) * p->deltaDistX;
	// 	}
	// }
	// if (k == MOVE_LEFT)
	// {
 //
	// }
 return (0);
}

int mouse_event(int k, int x, int y, t_param *p)
{
	if (k == 1 && (x >= 50 && x <= 60) && (y >= -14 && y <= -4) && p->height < 1200)
		{
			p->width += 1350;
			p->height += 200;
			p->sz_ln = 4 * p->width;
		}
		else if (k == 2 && (x >= 50 && x <= 60) && (y >= -14 && y <= -4) && p->height > 1000)
			{
				p->width -= 1350;
				p->height -= 200;
				p->sz_ln = 4 * p->width;
			}
			printf("height[%d], widht[%d]\n", p->height, p->width);
			resize(p);
		return (0);
}
