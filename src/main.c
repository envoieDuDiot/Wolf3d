/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:59:12 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/25 16:38:40 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int main(int ac, char **av)
{
  t_param *p;
  if (!(p = malloc(sizeof(t_param) + 1)))
   return (0);
  init_param(p);
  p->argv = av[1];
  if (parsing(p) == (-1))
   return (EXIT_FAILURE);
  mlx_stuff(p);

  // init_bonus(p);
  free(p);
  return (0);
}
