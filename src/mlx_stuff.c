#include "../include/wolf3d.h"

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
