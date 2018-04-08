/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:50:13 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/25 17:32:55 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WOLF3D_H
# define WOLF3D_H

// # define HEIGHT 1000
// # define WIDTH 1000

# define ESC	53
# define FRONT 13
# define BACK	1
# define MOVE_LEFT	0
# define MOVE_RIGHT	257
# define ROT_LEFT 123
# define ROT_RIGHT 124
# define RUN 257
# define SQUAT 256

# include "../libft/libft.h"
# include "mlx.h"

// typedef struct	s_pt
// {
// 	int		x;
// 	int		y;
// 	int		z;
// }				t_pt;

typedef struct s_param
{
	double init_posX;
	double init_posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double view;
	double rayPosX;
	double rayPosY;
	double rayDirX;
	double rayDirY;
	double wallDistX;
	double wallDistY;
	int square_initX;
	int square_initY;
	int stepX;
	int stepY;
	int wallDetect;
	int compas;
	double correc_dist;
	double wall_height;
	double draw_start;
	double draw_end;
	double deltaDistX;
	double deltaDistY;
	int patate;

 int ud; //up or down, avance ou recule
 int lr; //left or right
 int run; //si run = 1, course ON, si = 0, course OFF : par defaut = 0
 int alt; //si alt = 0, accroupi, si = 1, debout : par defaut = 1
 double move_speed;
 double rot_speed;
 double old_dirX;
 double old_dirY;


 int nb_lines;
 int nb_chars;
 int total_chars;
 int position;
 int m;

 // t_pt *pt;

 char *argv;
 int fd;
 int ret;
 char *line;
	int **map;

 void         *mlx;
 void         *win;
 void *img;
 int			bpp;
 int			endian;
 int			sz_ln;
 char		*data;
	int height;  // resize la taille de la fenetre en appuyant sur le point grisé
	int width;  // resize la taille de la fenetre en appuyant sur le point grisé

	int r;
	int g;
	int b;

}              t_param;

/* ######################   init.c   ###################### */

void init_param(t_param *p);
void mapping_init(t_param *p);

/* ###################   mlx_stuff.c   #################### */

void	refresh(t_param *p);
void	mlx_stuff(t_param *p);

/* #####################   events.c   ##################### */

int mouse_event(int k, int x, int y, t_param *p);
int keycool(int k, t_param *p);
int closing(t_param *p);
void resize(t_param *p);

/* ####################   parsing.c   #################### */

int		count_chars(char *line);
int		check_file(t_param *p);
t_param	*display_init(t_param *p);
int		parsing(t_param *p);

/* ####################   usefull.c   #################### */

int		rgb(char r, char g, char b);
void	put_pixel(t_param *p, int x, int y, int color);

/* ##################   wall_stuff.c   ################## */

void find_a_wall(t_param *p);
void draw_a_wall(int x, t_param *p);
static int	color_wall(t_param *p);
static void	color_a_wall(int x, t_param *p);

/* ###################   mapping.c   ################### */

void mapping(t_param *p);

#endif
