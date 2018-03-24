/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:59:12 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/24 17:36:12 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int mouse_event(int k, int x, int y, t_param *p);


int		count_chars(char *line)
{
	int			nb_chars;

	nb_chars = 0;
	while (*line && *line == ' ')
		line++;
	while (*line)
	{
		while (*line && *line != ' ')
			line++;
		nb_chars++;
		while (*line && *line == ' ')
			line++;
	}
	return (nb_chars);
}

int		check_file(t_param *p)
{
	int		ret;

	p->line = NULL;
	p->nb_chars = 0;
	p->nb_lines = 0;
	while ((ret = get_next_line(p->fd, &(p->line))) > 0)
	{
		if (!(p->line) || p->line[0] == '\0')
			return (EXIT_FAILURE);
		if (p->nb_chars == 0)
			p->nb_chars = count_chars(p->line);
		else
		{
			if (count_chars(p->line) != p->nb_chars)
				return (-1);
		}
		p->nb_lines++;
		free(p->line);
	}
	free(p->line);
	p->total_chars = (p->nb_chars) * (p->nb_lines);
	if (!(p->pt = malloc(sizeof(t_pt) * (p->total_chars + 1))))
		return (-1);
	return (0);
}

int		fill_t_pt(t_param *p)
{
	char	**tab;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while ((p->ret = get_next_line(p->fd, &(p->line))) > 0)
	{
		x = 0;
		tab = ft_strsplit(p->line, ' ');
		while (tab[x] != NULL)
		{
			p->pt[i].x = x;
			p->pt[i].y = y;
			p->pt[i].z = ft_atoi(tab[x]);
			free(tab[x]);
			i++;
			x++;
		}
		free(tab);
		free(p->line);
		y++;
	}
	return (0);
}

int		parsing(t_param *p)
{
	if ((p->fd = open(p->argv, O_RDONLY)) == -1)
		return (-1);
	if (check_file(p) == -1)
		return (-1);
	close(p->fd);
	p->fd = open(p->argv, O_RDONLY);
	if (fill_t_pt(p) == -1)
		return (-1);
	free(p->line);
	return (0);
}

int keycool(int k, t_param *p)
{
 printf("k[%d]\t", k);
 if (k == ESC)
  exit(0);
 return (0);
}

void	refresh(t_param *p)
{
	// p->win = mlx_new_window(p->mlx, p->width, p->height, "WOLF3D");
	p->img = mlx_new_image(p->mlx, p->width, p->height);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sz_ln, &p->endian);
 mapping(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
	// mlx_stuff(p);
}

int closing(t_param *p)
{
	exit(0);
	return (0);
}

void	mlx_stuff(t_param *p)
{
	if (!(p->mlx = mlx_init()))
		exit(EXIT_FAILURE);
	p->win = mlx_new_window(p->mlx, p->width, p->height, "WOLF3D");
	refresh(p);
	mlx_hook(p->win, 2, 0, keycool, p);
	mlx_hook(p->win, 17, 17, closing,p);
	mlx_hook(p->win, 4, (1L << 2), &mouse_event, p);
	mlx_loop(p->mlx);
}

void resize(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_destroy_window(p->mlx, p->win);
	mlx_stuff(p);
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

void init_param(t_param *p)
{
	p->init_posX = 2; // TO_DO definir position en fonction de la map(centre)
	p->init_posY = 2; // TO_DO definir position en fonction de la map(centre)
	p->dirX = -1;
	p->dirY = 0;
	p->planeX = 0;
	p->planeY = 0.66; // a modif pour voir le fonctionnement

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
}

int main(int ac, char **av)
{
  t_param *p;
  if (!(p = malloc(sizeof(t_param) + 1)))
   return (0);
  init_param(p);
  p->argv = av[1];
  if (parsing(p) == (-1))
   return (EXIT_FAILURE);
  mlx_stuff(p);

  // init_bonus(p);
  free(p);
  return (0);
}
