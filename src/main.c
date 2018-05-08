/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:59:12 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 09:47:16 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int	main(int ac, char **av)
{
	t_param *p;

	if (ac != 2)
	{
		ft_putendl("Impossible action - Wrong param");
		exit(0);
	}
	if (!(p = malloc(sizeof(t_param) + 1)))
		return (0);
	init_param(p);
	mapping_init(p);
	p->argv = av[1];
	if (parsing(p) == (-1))
		return (EXIT_FAILURE);
	mlx_stuff(p);
	free(p->map);
	free(p);
	return (0);
}
