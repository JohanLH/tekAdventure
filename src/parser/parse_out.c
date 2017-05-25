/*
** parse_out.c for parser in /home/johan/Documents/MUL/tekadventure2/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May 19 20:11:37 2017 johan
** Last update Tue May 23 01:05:00 2017 johan
*/

#include <stdlib.h>
#include "printf.h"
#include "my_string.h"
#include "parsing.h"

static int	parse_data_out(char *argu, int line,
			       t_out *out, t_root *out_fct)
{
  t_parser	*parser = NULL;
  t_node	*node = NULL;
  char		**tab = NULL;

  node = out_fct->first;
  if ((tab = my_str_to_wordtab(argu, SEPARATOR_NAME)) == NULL ||
      my_strlen_wordtab(tab) != 2)
    return (error_parsing(line));
  while (node)
    {
      parser = (t_parser *)node->data;
      if (!my_strcmp(parser->cmd, tab[0]))
	{
	  if (parser->parser_function3(out, tab[1], line))
	    return (1);
	  free_tab(tab);
	  return (0);
	}
      node = node->next;
    }
  free_tab(tab);
  return (error_parsing(line));
}

static t_out	*init_out()
{
  t_out		*out;

  if ((out = malloc(sizeof(*out))) == NULL)
    return (NULL);
  out->start.x = 0;
  out->start.y = 0;
  out->end.x = 0;
  out->end.y = 0;
  out->lock = 0;
  out->all_node = NULL;
  out->object = NULL;
  out->name = NULL;
  out->is_start = 0;
  out->is_end = 0;
  return (out);
}

t_node   *parse_out(t_node *file, int *line, t_map *map)
{
  t_node        *node = NULL;
  t_out		*out = NULL;
  t_root	*out_fct;

  node = file->next;
  *line += 1;
  if ((out = init_out()) == NULL || (out_fct = init_out_function()) == NULL)
    return (NULL);
  my_printf(1, "\t\t\t[Adding out]\n");
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if (parse_data_out(node->data, *line, out, out_fct))
	return (NULL);
      *line += 1;
      node = node->next;
    }
  if (!out->name || !out->is_start || !out->is_end || !out->all_node
      || list_prepend(map->out, out))
    return (NULL);
  my_printf(1, "\t\t\t[Adding out done]\n");
  return (node);
}
