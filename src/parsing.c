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
		p->map[nb] = malloc(sizeof(int)	* p->nb_chars + 1);
		tab = ft_strsplit(p->line, ' ');
		while (tab[i] != NULL)
		{
			p->map[nb][nb2] = ft_atoi(tab[i]);
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
