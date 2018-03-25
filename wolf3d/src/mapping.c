#include "../include/wolf3d.h"

void mapping_init(t_param *p)
{
 p->init_posX = 10; // TO_DO definir position en fonction de la map(centre)
	p->init_posY = 10; // TO_DO definir position en fonction de la map(centre)
	p->dirX = -1;
	p->dirY = 0;
	p->planeX = 0;
	p->planeY = 0.66;
 p->view = 0;
 p->rayPosX = 0;
 p->rayPosY = 0;
 p->rayDirX = 0;
 p->rayDirY = 0;
 p->wallDistX = 0;
 p->wallDistY = 0;
 p->square_initX = 0;
 p->square_initY = 0;
 p->stepX = 0;
 p->stepY = 0;
 p->wallDetect = 0;
 p->compas = 0;
 p->correc_dist = 0;
 p->wall_height = 0;
 p->draw_start = 0;
 p->draw_end = 0;
 p->deltaDistX = 0;
 p->deltaDistY = 0;
}


void find_a_wall(t_param *p)
{
 if (p->rayDirX < 0) /// Si le rayon est oriente vers la gauche
 {
   p->stepX = -1;
   p->wallDistX = (p->rayPosX - p->square_initX) * p->deltaDistX; ///  On calcule la distance entre joueur et 1e prochain mur vertical
 }
 else ///Si le rayon est oriente vers la droite
 {
   p->stepX = 1;
   p->wallDistX = (p->square_initX + 1.0 - p->rayPosX) * p->deltaDistX; /// On calcule la distance entre joueur et 1e prochain mur vertical
 }
 ///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur horizontal le plus proche en fonction de la prochaine etape y
 if (p->rayDirY < 0)
 {
   p->stepY = -1;///  On recule
   p->wallDistY = (p->rayPosY - p->square_initY) * p->deltaDistY;///  On calcule la distance entre le joueur et 1e prochain mur horizontal
 }
 else
 {
   p->stepY = 1;///  On avance
   p->wallDistY = (p->square_initY + 1.0 - p->rayPosY) * p->deltaDistY;/// On calcule la distance entre joueur et 1e prochain mur horizontal
 }
 ///lance de DDA = Digital Differential Analysis (algorithme de detection des murs)
 while (p->wallDetect == 0)
 {
   ///Saute au prochain carre de la map soit vers la  direction x, soit vers la direction y en fonction du mur le plus proche
   if (p->wallDistX < p->wallDistY)
   {
     p->wallDistX += p->deltaDistX;
     p->square_initX += p->stepX;
     p->compas = 0; ///Mur vertical
   }
   else
   {
     p->wallDistY += p->deltaDistY;
     p->square_initY += p->stepY;
     p->compas = 1; ///Mur vertical
   }
   ///Verifier si le rayon a detecte un mur
   if (p->map[p->square_initX][p->square_initY] > 0)
    p->wallDetect = 1;
  }
}

int		rgb(char r, char g, char b)
{
 return ((r & 0xFF << 16) + (g & 0xFF << 8) + (b & 0xff));
}

void draw_a_wall(int x, t_param *p)
{
  // Calcule la distance corrigée pour la projection
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
  p->wall_height = p->height / (int)p->correc_dist;
  p->draw_start = (p->height - p->wall_height) / 2;
  p->draw_end = p->height - p->draw_start;
  if (p->draw_start < 0)
   p->draw_start = 0;
  if (p->draw_end >= p->height)
   p->draw_end = p->height; // a verifier si bug d'affichage
   color_a_wall(x, p);
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

static int	color_wall(t_param *p)
{
	int		color;

	if (p->compas == 0 && p->dirX >= 0)
		color = 0x00B2FE;
	else if (p->compas == 0 && p->rayDirX < 0)
		color = 0xFE7700;
	else if (p->compas == 1 && p->rayDirY >= 0)
		color = 0xFE0000;
	else
		color = 0xFEFE00;
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

// void color_a_wall(int x, t_param *p, int color)
// {
//  int  input;
//  double y;
//
//  y = 0;
//  p->data =(char *)malloc((sizeof(char) * 1000));
//  if (p->map[p->square_initX][p->square_initY] != 0)
//  {
//   y = p->draw_start;
//   while (y <= p->draw_end)
//   {
//    input = ((255 << 16) + (170 << 8) + (255));
//    p->data[((int)x * 4) + ((int)y * 4 * 1000)] = input >> 16 & 0xff;
//    p->data[((int)x * 4)	+ ((int)y * 4 * 1000) + 1] = input >> 8 & 0xff;
//    p->data[((int)x * 4) + ((int)y * 4 * 1000) + 2] = input & 0xff;
//    y++;
//   }
//  }
// }

void mapping(t_param *p)
{
 int x;

 x = 0;
 mapping_init(p);
 p->square_initX = (int)p->init_posX;
 p->square_initY = (int)p->init_posY;
 while (x < p->width)
 {
  p->rayPosX = p->init_posX;
  p->rayPosY = p->init_posY;
  p->view = 2 * x / (double)p->width - 1;
  p->rayDirX = p->dirX + p->planeX * p->view;
  p->rayDirY = p->dirY + p->planeY * p->view;
  p->deltaDistX = sqrt(pow(1, 2) + (pow(p->rayDirY, 2) / pow(p->rayDirX, 2)));
  p->deltaDistY = sqrt(pow(1, 2) + (pow(p->rayDirX, 2) / pow(p->rayDirY, 2)));
  find_a_wall(p);
  draw_a_wall(x, p);
  x++;
 }
}
