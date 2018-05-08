/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:50:13 by gbryon            #+#    #+#             */
/*   Updated: 2018/05/08 12:30:49 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
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
# include <math.h>

typedef struct	s_param
{
	int			i;
	double		init_posx;
	double		init_posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		view;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		walldistx;
	double		walldisty;
	int			square_initx;
	int			square_inity;
	int			stepx;
	int			stepy;
	int			walldetect;
	int			compas;
	double		correc_dist;
	double		wall_height;
	double		draw_start;
	double		draw_end;
	double		deltadistx;
	double		deltadisty;
	int			patate;

	int			ud;
	int			lr;
	int			run;
	int			alt;
	double		move_speed;
	double		rot_speed;
	double		old_dirx;
	double		old_diry;

	int			nb_lines;
	int			nb_chars;
	int			total_chars;
	int			position;
	int			m;

	char		*argv;
	int			fd;
	int			ret;
	char		*line;
	int			**map;

	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			endian;
	int			sz_ln;
	char		*data;
	int			height;
	int			width;

	int			r;
	int			g;
	int			b;

}				t_param;

/*
** ######################   init.c   ######################
*/

void			init_param(t_param *p);
void			mapping_init(t_param *p);

/*
** ________________________________________________________
** ###################   mlx_stuff.c   ####################
*/

void			refresh(t_param *p);
void			mlx_stuff(t_param *p);

/*
** ________________________________________________________
** #####################   events.c   #####################
*/

int				mouse_event(int k, int x, int y, t_param *p);
int				keycool(int k, t_param *p);
int				closing(t_param *p);
void			resize(t_param *p);

/*
** ________________________________________________________
** #####################   events2.c   ####################
*/

int				closing(t_param *p);
void			resize(t_param *p);

/*
** ________________________________________________________
** ####################   parsing.c   #####################
*/

void			free_parsing(t_param *p, char **tab);
void			pos_init(t_param *p, int nb, int nb2);
int				count_chars(char *line);
int				check_file(t_param *p);
void			display_init(t_param *p);
int				parsing(t_param *p);

/*
** ________________________________________________________
** ################   parsing_control.c   #################
*/

void			first_control(t_param *p, int x);
void			second_control(t_param *p, int y);
void			map_control(t_param *p);
void			free_parsing(t_param *p, char **tab);
void			pos_init(t_param *p, int nb, int nb2);

/*
** ________________________________________________________
** ####################   usefull.c   #####################
*/

int				rgb(char r, char g, char b);
void			put_pixel(t_param *p, int x, int y, int color);

/*
** ________________________________________________________
** ##################   wall_stuff.c   ####################
*/
void			wall_verif(t_param *p);
void			find_a_wall(t_param *p);
void			draw_a_wall(int x, t_param *p);
int				color_wall(t_param *p);
void			color_a_wall(int x, t_param *p);

/*
** ________________________________________________________
** ####################   mapping.c   #####################
*/

void			mapping(t_param *p);

/*
** ________________________________________________________
*/
#endif
