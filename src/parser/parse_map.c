/*
** parse_map.c for parser in /home/johan/Thing/tekadvanture/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 15:44:47 2017 johan
** Last update Fri May  5 16:27:37 2017 johan
*/

#include "parsing.h"

static void	init_parse_map(t_map *map)
{
  map->graph_end = NULL;
  map->graph = NULL;
  map->is_image = 0;
  map->is_graph = 0;
}

static int	parse_data_map(t_map *map, t_node *node, int *line)
{
  if (my_strcmp(node->data, IMAGE_PARSING) == 0)
    {
      if (map->is_image)
	return (84);
      if (!(node = parse_image(node, map->image, line)))
	return (84);
      map->is_image = 1;
    }
  else if (my_strcmp(node->data, GRAPH_PARSING) == 0)
    {
      if (map->is_graph)
	return (84);
      if (!(node = parse_graph(node, line, map)))
	return (84);
      map->is_graph = 1;
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSGIN, *line);
      return (84);
    }
  return (0);
}

t_node		*parse_map(t_map *map, t_node *file, int *line)
{
  t_node	*node;
  
  init_parse_map(map);
  node = file->next;
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if (parse_data_map(map, node, line))
	return (84);
      *line += 1;
      node = node->next;
    }
  return (node);
}
