/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:50:13 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/24 17:58:10 by gbryon           ###   ########.fr       */
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

typedef struct	s_pt
{
	int		x;
	int		y;
	int		z;
}				t_pt;

typedef struct s_param
{
 int ud; //up or down, avance ou recule
 int lr; //left or right
 int run; //si run = 1, course ON, si = 0, course OFF : par defaut = 0
 int alt; //si alt = 0, accroupi, si = 1, debout : par defaut = 1


 int nb_lines;
 int nb_chars;
 int total_chars;

 t_pt *pt;

 char *argv;
 int fd;
 int ret;
 char *line;

 void         *mlx;
 void         *win;
 void *img;
 int			bpp;
 int			endian;
 int			sz_ln;
 char		*data;
	int height;  // resize la taille de la fenetre en appuyant sur le point grisé
	int width;  // resize la taille de la fenetre en appuyant sur le point grisé

}              t_param;

void	mlx_stuff(t_param *p);
void	refresh(t_param *p);
int keycool(int k, t_param *p);
int		parsing(t_param *p);
int		fill_t_pt(t_param *p);
int		check_file(t_param *p);
int		count_chars(char *line);


#endif
