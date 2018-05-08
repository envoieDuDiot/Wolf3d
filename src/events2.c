/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:21:29 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 11:54:26 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		closing(t_param *p)
{
	if (p)
		exit(0);
	return (0);
}

void	resize(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_destroy_window(p->mlx, p->win);
	mlx_stuff(p);
}
