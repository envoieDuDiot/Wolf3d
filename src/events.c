/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:21:29 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 11:39:26 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		rotation(int k, double dir, double plane, t_param *p)
{
	if (k == 123)
	{
		p->dirx = p->dirx * cos(p->rot_speed) - p->diry * sin(p->rot_speed);
		p->diry = dir * sin(p->rot_speed) + p->diry * cos(p->rot_speed);
		p->planex = p->planex * cos(p->rot_speed)
			- p->planey * sin(p->rot_speed);
		p->planey = plane * sin(p->rot_speed) + p->planey * cos(p->rot_speed);
	}
	if (k == 124)
	{
		p->dirx = p->dirx * cos(-p->rot_speed) - p->diry * sin(-p->rot_speed);
		p->diry = dir * sin(-p->rot_speed) + p->diry * cos(-p->rot_speed);
		p->planex = p->planex * cos(-p->rot_speed)
			- p->planey * sin(-p->rot_speed);
		p->planey = plane * sin(-p->rot_speed) + p->planey * cos(-p->rot_speed);
	}
	return (0);
}

int		keycool2(int k, t_param *p)
{
	if (k == 46)
	{
		if (p->m != 1)
		{
			system("afplay ./bonus/music.mp3 & ");
			p->m = 1;
		}
		else
		{
			system("killall afplay");
			p->m = 0;
		}
	}
	if (k == 257)
	{
		if (p->move_speed == 0.2)
			p->move_speed = 0.5;
		else
			p->move_speed = 0.2;
	}
	if (k == ESC)
		exit(0);
	return (0);
}

int		keycool(int k, t_param *p)
{
	if (k == 126 || k == 13)
	{
		if (p->map[(int)(p->init_posx + p->dirx *
					p->move_speed)][(int)p->init_posy] != 1)
			p->init_posx += p->dirx * p->move_speed;
		if (p->map[(int)p->init_posx][(int)(p->init_posy +
					p->diry * p->move_speed)] != 1)
			p->init_posy += p->diry * p->move_speed;
	}
	if (k == 125 || k == 1)
	{
		if (p->map[(int)(p->init_posx - p->dirx *
					p->move_speed)][(int)p->init_posy] != 1)
			p->init_posx -= p->dirx * p->move_speed;
		if (p->map[(int)p->init_posx][(int)(p->init_posy -
					p->diry * p->move_speed)] != 1)
			p->init_posy -= p->diry * p->move_speed;
	}
	keycool2(k, p);
	rotation(k, p->dirx, p->planex, p);
	refresh(p);
	return (0);
}

int		mouse_event(int k, int x, int y, t_param *p)
{
	if (k == 1 && (x >= 50 && x <= 60)
			&& (y >= -14 && y <= -4) && p->height < 1200)
	{
		p->width = 1250;
		p->height = 1250;
		p->sz_ln = 4 * p->width;
	}
	else if (k == 2 && (x >= 50 && x <= 60)
			&& (y >= -14 && y <= -4) && p->height > 1000)
	{
		p->width = 1000;
		p->height = 1000;
		p->sz_ln = 4 * p->width;
	}
	resize(p);
	return (0);
}
