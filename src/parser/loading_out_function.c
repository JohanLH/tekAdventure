/*
** loading_out_function.c for parser in /home/johan/Documents/MUL/tekadventure2/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May 23 00:22:56 2017 johan
** Last update Tue May 23 01:10:06 2017 johan
*/

#include <stdlib.h>
#include "parsing.h"
#include "printf.h"
#include "my_string.h"

int	load_out_start(t_out *out, char *argu, int line)
{
  my_printf(1, "\t\t\t\t[Loading start]\n");
  if (out->is_start || parse_coor_integer(argu, line, &out->start, 1))
    return (1);
  out->is_start = 1;
  return (0);
}

int	load_out_end(t_out *out, char *argu, int line)
{
  my_printf(1, "\t\t\t\t[Loading end]\n");
  if (out->is_end || parse_coor_integer(argu, line, &out->end, 1))
    return (1);
  out->is_end = 1;
  return (0);
}

int	load_out_name(t_out *out, char *argu, int line)
{
  my_printf(1, "\t\t\t\t[Loading name]\n");
  if (out->name || (out->name = my_strdup(argu)) == NULL)
    return (error_parsing(line));
  return (0);
}

int	load_out_lock(t_out *out, char *argu, int line)
{
  my_printf(1, "\t\t\t\t[Loading lock]\n");
  if (!my_strcmp(argu, INTERACTION_ON))
    out->lock = 1;
  else if (!my_strcmp(argu, INTERACTION_OFF))
    out->lock = 0;
  else
    return (error_parsing(line));
  return (0);
}

int	load_out_node(t_out *out, char *argu, int line)
{
  char	**tab = NULL;

  my_printf(1, "\t\t\t\t[Loading node]\n");
  if (out->all_node ||
      (tab = my_str_to_wordtab(argu, SEPARATOR_DATA)) == NULL)
    return (error_parsing(line));
  out->all_node = tab;
  return (0);
}
