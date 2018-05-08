/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:50:45 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 17:50:46 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

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
	if (ret < 0)
		exit(0);
	free(p->line);
	p->total_chars = (p->nb_chars) * (p->nb_lines);
	return (0);
}

void	display_init(t_param *p)
{
	char	**tab;
	int		nb;
	int		nb2;

	nb = 0;
	if (!(p->map = (int **)malloc(sizeof(int *) * p->total_chars + 1)))
		ft_putendl("Impossible action - Malloc initialisation issue");
	while (get_next_line(p->fd, &(p->line)))
	{
		p->i = 0;
		nb2 = 0;
		p->map[nb] = (int *)malloc(sizeof(int) * p->nb_chars + 1);
		tab = ft_strsplit(p->line, ' ');
		while (tab[p->i] != NULL)
		{
			p->map[nb][nb2] = ft_atoi(tab[p->i]);
			if (p->position == 0 && p->map[nb][nb2] == 0)
				pos_init(p, nb, nb2);
			free(tab[p->i]);
			p->i++;
			nb2++;
		}
		nb++;
		free_parsing(p, tab);
	}
}

int		parsing(t_param *p)
{
	if ((p->fd = open(p->argv, O_RDONLY)) == -1)
		exit(0);
	if (check_file(p) == -1)
		return (-1);
	close(p->fd);
	if ((p->fd = open(p->argv, O_RDONLY)) == -1)
		exit(0);
	display_init(p);
	map_control(p);
	close(p->fd);
	free(p->line);
	return (0);
}
