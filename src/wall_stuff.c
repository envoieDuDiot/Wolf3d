/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:57:30 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 12:05:46 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	wall_verif(t_param *p)
{
	if (p->raydirx < 0)
	{
		p->stepx = -1;
		p->walldistx = (p->rayposx - (double)p->square_initx) * p->deltadistx;
	}
	else
	{
		p->stepx = 1;
		p->walldistx = ((double)p->square_initx + 1.0 - p->rayposx)
			* p->deltadistx;
	}
	if (p->raydiry < 0)
	{
		p->stepy = -1;
		p->walldisty = (p->rayposy - (double)p->square_inity)
			* p->deltadisty;
	}
	else
	{
		p->stepy = 1;
		p->walldisty = ((double)p->square_inity + 1.0 - p->rayposy)
			* p->deltadisty;
	}
}

void	find_a_wall(t_param *p)
{
	wall_verif(p);
	while (p->walldetect != 1 && p->square_inity > 0 &&
			p->square_inity < p->nb_chars &&
			p->square_initx > 0 && p->square_initx <= p->nb_lines)
	{
		if (p->walldistx < p->walldisty)
		{
			p->walldistx += p->deltadistx;
			p->square_initx += p->stepx;
			p->compas = 0;
		}
		else
		{
			p->walldisty += p->deltadisty;
			p->square_inity += p->stepy;
			p->compas = 1;
		}
		if (p->map[p->square_initx][p->square_inity] == 1)
			p->walldetect = 1;
	}
}

void	draw_a_wall(int x, t_param *p)
{
	if (p->compas == 0)
	{
		p->correc_dist = fabs((p->square_initx - p->rayposx
					+ (1 - p->stepx) / 2) / p->raydirx);
	}
	else
	{
		p->correc_dist = fabs((p->square_inity - p->rayposy
					+ (1 - p->stepy) / 2) / p->raydiry);
	}
	p->wall_height = fabs(p->height / p->correc_dist);
	p->draw_start = (p->height - p->wall_height) / 2;
	if (p->draw_start < 0)
		p->draw_start = 0;
	p->draw_end = p->wall_height / 2 + p->height / 2;
	if (p->draw_end >= p->height)
		p->draw_end = p->height - 1;
	color_a_wall(x, p);
}

int		color_wall(t_param *p)
{
	int		color;

	if (p->compas == 0 && p->raydirx >= 0)
		color = 0x00B2FE;
	else if (p->compas == 0 && p->raydirx < 0)
		color = 0xFE7700;
	else if (p->compas == 1 && p->raydiry >= 0)
		color = 0xFE0000;
	else
		color = 0xFEFE00;
	if (p->compas == 1)
		color = color / 2;
	return (color);
}

void	color_a_wall(int x, t_param *p)
{
	int		y;
	int		color;

	y = 0;
	while (y < p->width)
	{
		if (y < p->draw_start)
			color = 0x5Ad4EC;
		else if (y > p->draw_end)
			color = 0x686868;
		else
		{
			if (p->walldetect == 1)
				color = color_wall(p);
		}
		put_pixel(p, x, y, color);
		y++;
	}
}
