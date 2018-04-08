#include "../include/wolf3d.h"

void find_a_wall(t_param *p)
{
 if (p->rayDirX < 0)  {
   p->stepX = -1;
   p->wallDistX = (p->rayPosX - (double)p->square_initX) * p->deltaDistX;
 }
 else
 {
   p->stepX = 1;
   p->wallDistX = ((double)p->square_initX + 1.0 - p->rayPosX) * p->deltaDistX;
 }
 if (p->rayDirY < 0)
 {
   p->stepY = -1;
   p->wallDistY = (p->rayPosY - (double)p->square_initY) * p->deltaDistY;
 }
 else
 {
   p->stepY = 1;
   p->wallDistY = ((double)p->square_initY + 1.0 - p->rayPosY) * p->deltaDistY;
 }
 while (p->wallDetect != 1 && p->square_initY > 0 && \
			p->square_initY < p->nb_chars && \
			p->square_initX > 0 && p->square_initX <= p->nb_lines)
 {
   if (p->wallDistX < p->wallDistY)
   {
     p->wallDistX += p->deltaDistX;
     p->square_initX += p->stepX;
     p->compas = 0;
   }
   else
   {
     p->wallDistY += p->deltaDistY;
     p->square_initY += p->stepY;
     p->compas = 1;
   }
   if (p->map[p->square_initX][p->square_initY] == 1)
    p->wallDetect = 1;
  }
}


void draw_a_wall(int x, t_param *p)
{
  if (p->compas == 0)
  {
	  p->correc_dist = fabs((p->square_initX - p->rayPosX + (1 - p->stepX) / 2)
   / p->rayDirX);
  }
  else
  {
	  p->correc_dist = fabs((p->square_initY - p->rayPosY + (1 - p->stepY) / 2)
   / p->rayDirY);
  }
//  if (p->correc_dist <= 0.05)
//    p->correc_dist = 0.05;
  p->wall_height = fabs(p->height / p->correc_dist);
  p->draw_start = (p->height - p->wall_height) / 2;
  if (p->draw_start < 0)
   p->draw_start = 0;
  p->draw_end = p->wall_height / 2 + p->height / 2;
  if (p->draw_end >= p->height)
   p->draw_end = p->height - 1;
   color_a_wall(x, p);
}


static int	color_wall(t_param *p)
{
	int		color;

	if (p->compas == 0 && p->rayDirX >= 0)
		color = 0x00B2FE; // bleu
	else if (p->compas == 0 && p->rayDirX < 0)
		color = 0xFE7700; // orange
	else if (p->compas == 1 && p->rayDirY >= 0)
		color = 0xFE0000; //rouge
	else
		color = 0xFEFE00; // jaune
	if (p->compas == 1)
		color = color / 2;
	return (color);
}

static void	color_a_wall(int x, t_param *p)
{
	int		y;
	int		color;

	y = 0;
	while (y < p->width)
	{
		if (y < p->draw_start)
			color = 0x5AD4EC;
		else if (y > p->draw_end)
			color = 0x686868;
		else
		{
			if (p->wallDetect == 1)
				color = color_wall(p);
		}
		put_pixel(p, x, y, color);
		y++;
	}
}
