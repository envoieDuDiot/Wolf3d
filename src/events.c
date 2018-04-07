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

int rotation(int k, double dir, double plane, t_param *p)
{
	if (k == 123)
	{
		p->dirX = p->dirX * cos(p->rot_speed)	- p->dirY * sin(p->rot_speed);
		p->dirY = dir * sin(p->rot_speed)	+ p->dirY * cos(p->rot_speed);
		p->planeX = p->planeX * cos(p->rot_speed)	- p->planeY * sin(p->rot_speed);
		p->planeY = plane * sin(p->rot_speed)	+ p->planeY * cos(p->rot_speed);
	}
	if (k == 124)
	{
		p->dirX = p->dirX * cos(-p->rot_speed)	- p->dirY * sin(-p->rot_speed);
		p->dirY = dir * sin(-p->rot_speed)	+ p->dirY * cos(-p->rot_speed);
		p->planeX = p->planeX * cos(-p->rot_speed)	- p->planeY * sin(-p->rot_speed);
		p->planeY = plane * sin(-p->rot_speed)	+ p->planeY * cos(-p->rot_speed);
	}

	return (0);
}

int keycool(int k, t_param *p)
{
 printf("k[%d]\t", k);
if (k == ESC)
	exit(0);
if (k == 126 || k == 13)
{
	if (p->map[(int)(p->init_posX + p->dirX * p->move_speed)][(int)p->init_posY] != '1')
		p->init_posX += p->dirX * p->move_speed;
	if (p->map[(int)p->init_posX][(int)(p->init_posY + p->dirY * p->move_speed)] != '1')
		p->init_posY += p->dirY * p->move_speed;
	printf("map[%d][%d] = %d\n", (int)(p->init_posX), (int)p->init_posY, p->map[(int)(p->init_posX + p->dirX * p->move_speed)][(int)p->init_posY]);
	// printf("init_posX[%f], dirX[%f]\n", p->init_posX, p->dirX);
	}
if (k == 125 || k == 1)
{
	if (p->map[(int)(p->init_posX - p->dirX * p->move_speed)][(int)p->init_posY] != '1')
		p->init_posX -= p->dirX * p->move_speed;
	if (p->map[(int)p->init_posX][(int)(p->init_posY - p->dirY * p->move_speed)] != '1')
		p->init_posY -= p->dirY * p->move_speed;
}
rotation(k, p->dirX, p->planeX, p);
refresh(p);
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
			// printf("height[%d], widht[%d]\n", p->height, p->width);
			resize(p);
		return (0);
}
