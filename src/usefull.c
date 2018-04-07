#include "../include/wolf3d.h"

int		rgb(char r, char g, char b)
{
 return ((r & 0xFF << 16) + (g & 0xFF << 8) + (b & 0xff));
}

void	put_pixel(t_param *p, int x, int y, int color)
{
	int				i;
	unsigned int	 q;

	i = 0;
	q = x * (p->bpp / 8) + y * (p->sz_ln);
	while (i < (p->bpp / 8))
	{
		p->data[q + i] = color;
		color >>= 8;
		i++;
	}
}
