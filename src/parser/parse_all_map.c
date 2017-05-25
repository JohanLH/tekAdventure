/*
** parse_all_map.c for parser in /home/johan/Documents/MUL/tekadventure2/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May 19 21:29:33 2017 johan
** Last update Mon May 22 23:27:20 2017 johan
*/

#include <stdlib.h>
#include "parsing.h"
#include "my_string.h"
#include "printf.h"

static int	parse_type_conf(char **data, int *line,
				 char **name, t_root *all_map)
{
  t_root	*file_data = NULL;
  t_game	*game = NULL;

  if (!my_strcmp(data[0], FILE_NAME))
    {
      if ((name[0] = my_strdup(data[1])) == NULL)
	return (1);
    }
  else if (!my_strcmp(data[0], FILE_PATH))
    {
      if (name[0] == NULL || (file_data = parse_file(data[1])) == NULL)
	return (1);
      if ((game = parse_list(file_data, name[0])) == NULL
	  || list_append(all_map, game))
	return (1);
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (1);
    }
  return (0);
}

static t_node	*parse_data_file_conf(t_node *node, int *line, t_root *all_map)
{
  char		**tab = NULL;
  char		*name = NULL;

  *line += 1;
  while (node && my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((tab = my_str_to_wordtab(node->data, SEPARATOR_NAME)) == NULL ||
	  my_strlen_wordtab(tab) != 2)
	{
	  my_printf(2, "%s %d\n", ERROR_PARSING, *line);
	  return (NULL);
	}
      if (parse_type_conf(tab, line, &name, all_map))
	return (NULL);
      *line += 1;
      node = node->next;
      free_tab(tab);
    }
  free(name);
  return (node);
}

t_root		*parse_all_map(char *file)
{
  t_root	*all_map = NULL;
  t_root	*conf_file = NULL;
  t_node	*node = NULL;
  int		line;

  line = 1;
  if ((all_map = list_init(&free_parsing)) == NULL
      || (conf_file = parse_file(file)) == NULL)
    return (NULL);
  node = conf_file->first;
  while (node)
    {
      if (!my_strcmp(node->data, FILE_PARSING))
	{
	  if ((node = parse_data_file_conf(node->next, &line, all_map)) == NULL)
	    return (NULL);
	}
      else
	return (NULL);
      line++;
      node = node->next;
    }
  return (all_map);
}
