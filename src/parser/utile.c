/*
** utile.c for parser in /home/johan/Documents/MUL/tekadventure2/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May 19 20:13:09 2017 johan
** Last update Tue May 23 01:09:45 2017 johan
*/

#include "my_string.h"
#include "printf.h"
#include "parsing.h"

int	parse_coor_integer(char *argu, int line, sfVector2i *coor, int neg)
{
  int		error;
  char		**tab;

  error = 1;
  if ((tab = my_str_to_wordtab(argu, SEPARATOR_DATA)) == NULL)
    return (1);
  if (my_strlen_wordtab(tab) != 2)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      free_tab(tab);
      return (1);
    }
  coor->x = my_atoi(tab[0], &error);
  coor->y = my_atoi(tab[1], &error);
  if (error < 0 || (neg && (coor->x < 0 || coor->y < 0)))
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      free_tab(tab);
      return (1);
    }
  free_tab(tab);
  return (0);
}

int	parse_coor_float(char *argu, int line, sfVector2f *coor, int neg)
{
  int		error;
  char		**tab;

  error = 1;
  if ((tab = my_str_to_wordtab(argu, SEPARATOR_DATA)) == NULL)
    return (1);
  if (my_strlen_wordtab(tab) != 2)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      free_tab(tab);
      return (1);
    }
  coor->x = my_get_float(tab[0], &error);
  coor->y = my_get_float(tab[1], &error);
  if (error < 0 || (neg && (coor->x < 0 || coor->y < 0)))
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      free_tab(tab);
      return (1);
    }
  free_tab(tab);
  return (0);
}

int	parse_integer(char *argu, int line, int *value, int neg)
{
  int		error;

  error = 1;
  *value = my_atoi(argu, &error);
  if (error < 0|| (neg && *value < 0))
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  return (0);
}

int	parse_float(char *argu, int line, float *value, int neg)
{
  int		error;

  error = 1;
  *value = my_get_float(argu, &error);
  if (error < 0 || (neg && *value < 0))
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  return (0);
}
