/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:18:16 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 11:18:17 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	first_control(t_param *p, int x)
{
	while (x < p->nb_chars)
	{
		if (p->map[0][x] != 1)
		{
			ft_putendl("Impossible action - Wrong Map 1");
			exit(0);
		}
		x++;
	}
	x = 0;
	while (x < p->nb_chars)
	{
		if (p->map[p->nb_lines - 1][x] != 1)
		{
			ft_putendl("Impossible action - Wrong Map 2");
			exit(0);
		}
		x++;
	}
}

void	second_control(t_param *p, int y)
{
	while (y < p->nb_lines)
	{
		if (p->map[y][0] != 1)
		{
			ft_putendl("Impossible action - Wrong Map 3 ");
			exit(0);
		}
		y++;
	}
	y = 0;
	while (y < p->nb_lines)
	{
		if (p->map[y][p->nb_chars - 1] != 1)
		{
			ft_putendl("Impossible action - Wrong Map 4 ");
			exit(0);
		}
		y++;
	}
}

void	map_control(t_param *p)
{
	int x;
	int y;

	x = 0;
	y = 0;
	first_control(p, x);
	second_control(p, y);
	y = 0;
	while (y < p->nb_lines)
	{
		while (x < p->nb_chars)
		{
			if (p->map[y][x] == 0)
				return ;
			x++;
		}
		x = 0;
		y++;
	}
	ft_putendl("Impossible action - Wrong Map - no position ");
	exit(0);
}

void	free_parsing(t_param *p, char **tab)
{
	free(tab);
	free(p->line);
}

void	pos_init(t_param *p, int nb, int nb2)
{
	p->init_posx = nb;
	p->init_posy = nb2;
	p->position = 1;
}
