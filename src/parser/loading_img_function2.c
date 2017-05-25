/*
** loading_img_function2.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 13 17:46:05 2017 johan
** Last update Tue May 23 00:51:58 2017 johan
*/

#include "printf.h"
#include "parsing.h"
#include "my_string.h"

int	load_incre_scale(t_image *image, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading incre-scale]\n");
  if (parse_coor_float(argu, line, &image->incre_scale, 0))
    return (1);
  return (0);
}

int	load_max_dimension(t_image *image, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading max]\n");
  if ((parse_integer(argu, line, &image->max, 1)))
    return (1);
  return (0);
}

int	load_incre_dim(t_image *image, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading incre-dim]\n");
  if (parse_coor_integer(argu, line, &image->incre_dim, 0))
    return (1);
  return (0);
}

int		load_start_img(t_image *image, char *argu, int line)
{
  sfVector2i	tmp;

  my_printf(1, "\t\t\t[Loading start]\n");
  if (parse_coor_integer(argu, line, &tmp, 1))
    return (1);
  image->rect.left = tmp.x;
  image->rect.top = tmp.y;
  return (0);
}

int	load_interval(t_image *image, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading interval]\n");
  if (parse_integer(argu, line, &image->interval, 1))
    return (1);
  return (0);
}
