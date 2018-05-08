/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:55:00 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 11:55:29 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	mapping(t_param *p)
{
	int x;

	x = 0;
	while (x < p->width)
	{
		p->rayposx = p->init_posx;
		p->rayposy = p->init_posy;
		p->view = 2 * x / (double)p->width - 1;
		p->raydirx = p->dirx + p->planex * p->view;
		p->raydiry = p->diry + p->planey * p->view;
		p->square_initx = (int)p->rayposx;
		p->square_inity = (int)p->rayposy;
		p->deltadistx = sqrt(pow(1, 2) +
				(pow(p->raydiry, 2) / pow(p->raydirx, 2)));
		p->deltadisty = sqrt(pow(1, 2) +
				(pow(p->raydirx, 2) / pow(p->raydiry, 2)));
		p->walldetect = 0;
		p->compas = 0;
		find_a_wall(p);
		draw_a_wall(x, p);
		x++;
	}
}
