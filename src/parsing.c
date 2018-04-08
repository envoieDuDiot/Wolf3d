#include "../include/wolf3d.h"

 void map_control(t_param *p)
 {
 	int x;
 	int y;

 	x = 0;
 	y = 0;
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
	x = 0;
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
	// if (!(p->map = malloc(sizeof(t_pt) * (p->total_chars + 1))))
	// 	return (-1);
	return (0);
}

t_param	*display_init(t_param *p)
{
	char	**tab;
	int		i;
	int		nb;
	int nb2;

	i = 0;
	nb = 0;
	nb2 = 0;
	if (!(p->map = (int **)malloc(sizeof(int *)	* p->total_chars + 1)))
		ft_putendl("Impossible action - Malloc initialisation issue");
	while (get_next_line(p->fd, &(p->line)))
	{
		p->map[nb] = (int *)malloc(sizeof(int)	* p->nb_chars + 1);
		tab = ft_strsplit(p->line, ' ');
		while (tab[i] != NULL)
		{
			p->map[nb][nb2] = ft_atoi(tab[i]);
			if (p->position == 0 && p->map[nb][nb2] == 0)
			{
				p->init_posX = nb; // TO_DO definir position en fonction de la map(centre)
				p->init_posY = nb2; // TO_DO definir position en fonction de la map(centre)
				p->position = 1;
			}
			// printf("tab[i] = %s\t", tab[i]);
			// printf("map = %d   -- \n", p->map[nb][nb2]);
			i++;
			nb2++;
		}
		nb2 = 0;
		nb++;
		i = 0;
		free(tab);
		free(p->line);
	}
	map_control(p);
	return (p);
}

int		parsing(t_param *p)
{
	if ((p->fd = open(p->argv, O_RDONLY)) == -1)
		return (-1);
	if (check_file(p) == -1)
		return (-1);
	close(p->fd);
	p->fd = open(p->argv, O_RDONLY);
	display_init(p);
	close(p->fd);
	free(p->line);
	return (0);
}
