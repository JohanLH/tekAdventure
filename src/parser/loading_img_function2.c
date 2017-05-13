/*
** loading_img_function2.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 13 17:46:05 2017 johan
** Last update Sat May 13 17:46:07 2017 johan
*/

#include "printf.h"
#include "parsing.h"
#include "my_string.h"

int	load_incre_scale(t_image *image, char *argu, int line)
{
  char  **temp = NULL;
  int   error;

  error = 1;
  my_printf(1, "\t\t\t[Loading incre-scale]\n");
  if ((temp = my_str_to_wordtab(argu, ',')) == NULL)
    return (1);
  if (my_strlen_wordtab(temp) != 2)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  image->pos.x = my_get_float(temp[0], &error);
  image->pos.y = my_get_float(temp[1], &error);
  if (error < 0)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  free_tab(temp);
  return (0);
}

int	load_max_dimension(t_image *image, char *argu, int line)
{
  int	error;

  error = 1;
  my_printf(1, "\t\t\t[Loading max]\n");
  if ((image->max = my_atoi(argu, &error)) <= 0 || error < 0)
    return (1);
  return (0);
}

int	load_incre_dim(t_image *image, char *argu, int line)
{
  char  **temp = NULL;
  int   error;

  error = 1;
  my_printf(1, "\t\t\t[Loading incre-dim]\n");
  if ((temp = my_str_to_wordtab(argu, ',')) == NULL)
    return (1);
  if (my_strlen_wordtab(temp) != 2)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  if ((image->incre_dim.x = my_atoi(temp[0], &error)) < 0 ||
      (image->incre_dim.y = my_atoi(temp[1], &error)) < 0 ||
      (error < 0))
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  free_tab(temp);
  return (0);
}
