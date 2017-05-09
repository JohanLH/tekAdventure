/*
** loading_function2.c for parser in /home/johan/Thing/tekadvanture/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 14:23:36 2017 johan
** Last update Tue May  9 16:49:45 2017 johan
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
