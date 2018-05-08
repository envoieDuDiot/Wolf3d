/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:18:48 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 11:20:37 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_param(t_param *p)
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
	p->position = 0;
	p->i = 0;
}

void	mapping_init2(t_param *p)
{
	p->move_speed = 0.2;
	p->rot_speed = 0.12;
	p->old_dirx = 0;
	p->old_diry = 0;
}

void	mapping_init(t_param *p)
{
	p->m = 0;
	p->dirx = -1;
	p->diry = 0;
	p->planex = 0;
	p->planey = 0.66;
	p->view = 0;
	p->rayposx = 0;
	p->rayposy = 0;
	p->raydirx = 0;
	p->raydiry = 0;
	p->walldistx = 0;
	p->walldisty = 0;
	p->square_initx = 0;
	p->square_inity = 0;
	p->stepx = 0;
	p->stepy = 0;
	p->walldetect = 0;
	p->compas = 0;
	p->correc_dist = 0;
	p->wall_height = 0;
	p->draw_start = 0;
	p->draw_end = 0;
	p->deltadistx = 0;
	p->deltadisty = 0;
	mapping_init2(p);
}
