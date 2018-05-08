/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:43:44 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 14:49:37 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	mlx_stuff(t_param *p)
{
	if (!(p->mlx = mlx_init()))
		exit(EXIT_FAILURE);
	p->win = mlx_new_window(p->mlx, p->width, p->height, "WOLF3D");
	refresh(p);
	mlx_hook(p->win, 2, 0, keycool, p);
	mlx_hook(p->win, 17, 17, closing, p);
	mlx_hook(p->win, 4, (1L << 2), &mouse_event, p);
	mlx_loop(p->mlx);
}

void	refresh(t_param *p)
{
	p->img = mlx_new_image(p->mlx, p->width, p->height);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sz_ln, &p->endian);
	mapping(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
	mlx_string_put(p->mlx, p->win, 40, 72, 0x0042bff4,
			"|-------USER GUIDE-------|");
	mlx_string_put(p->mlx, p->win, 40, 112, 0xffffff,
			"|    ESC     : QUIT      |");
	mlx_string_put(p->mlx, p->win, 40, 132, 0xffffff,
			"|  ARROWS    : MOVING    |");
	mlx_string_put(p->mlx, p->win, 40, 152, 0xffffff,
			"|LEFT SHIFT  : RUN       |");
	mlx_string_put(p->mlx, p->win, 40, 172, 0xffffff,
			"|LEFT CLICK  : EXTEND WDW|");
	mlx_string_put(p->mlx, p->win, 40, 192, 0xffffff,
			"|grey circle  (top left) |");
	mlx_string_put(p->mlx, p->win, 40, 212, 0xffffff,
			"|RIGHT CLICK : SHRINK WDW|");
	mlx_string_put(p->mlx, p->win, 40, 232, 0xffffff,
			"|grey circle  (top left) |");
	mlx_string_put(p->mlx, p->win, 40, 252, 0xffffff,
			"|     M      : SURPRISE  |");
	mlx_string_put(p->mlx, p->win, 40, 272, 0xffffff,
			"|________________________|");
}
