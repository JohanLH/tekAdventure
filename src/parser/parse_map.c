/*
** parse_map.c for parser in /home/johan/Thing/tekadvanture/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 15:44:47 2017 johan
** Last update Sun May  7 00:05:51 2017 Johan Lhour
*/

#include <stdlib.h>
#include "printf.h"
#include "parsing.h"
#include "my_string.h"

static void	init_parse_map(t_map *map)
{
  map->graph_end = NULL;
  map->graph = NULL;
  map->is_image = 0;
  map->is_graph = 0;
}

static t_node	*parse_data_map(t_map *map, t_node *node, int *line)
{
  if (my_strcmp(node->data, IMAGE_PARSING) == 0)
    {
      if (!(node = parse_image(node, &map->image, line))
	  || map->is_image)
	return (NULL);
      map->is_image = 1;
    }
  else if (my_strcmp(node->data, GRAPH_PARSING) == 0)
    {
      if (!(node = parse_graph(node, line, map)) || map->is_graph)
	return (NULL);
      map->is_graph = 1;
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (NULL);
    }
  return (node);
}

t_node		*parse_map(t_map *map, t_node *file, int *line)
{
  t_node	*node;
  
  init_parse_map(map);
  node = file->next;
  *line += 1;
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((node = parse_data_map(map, node, line)) == NULL)
	return (NULL);
      *line += 1;
      node = node->next;
    }
  if (map->is_image == 0 || map->is_graph == 0
      || map->graph_enn == NULL || map->graph == NULL)
    return (NULL);
  return (node);
}
