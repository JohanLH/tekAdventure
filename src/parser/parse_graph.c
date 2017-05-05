/*
** parse_graph.c for parser in /home/johan/Thing/tekadvanture/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 14:14:56 2017 johan
** Last update Fri May  5 15:35:10 2017 johan
*/

#include <stdlib.h>
#include "graph.h"
#include "my_string.h"
#include "parsing.h"
#include "my_string.h"
#include "printf.h"

static t_node	*parse_out(t_node *file, int *line, t_map *map)
{
  t_node	*node = NULL;

  node = file->next;
  my_printf(1, "\t[Finding out]\n");
  my_printf(1, "\t[Adding out]\n");
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((map->graph_end = find_elem_graph(map->graph, node->data)) == NULL)
	{
	  my_printf(2, "%s %d\n", ERROR_PARSING, *line);
	  return (NULL);
	}
      *line += 1;
      node = node->next;
    }
  my_printf(1, "\t[Adding out end]\n");
  return (node);
}

static t_node	*parse_link(t_node *file, int *line, t_map *map)
{
  t_node	*node = NULL;
  char		**temp = NULL;

  my_printf(1, "\t[Start parsing link]\n");
  my_printf(1, "\t[Adding link]\n");
  node = file->next;
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((temp = my_str_to_wordtab(node->data, '-')) == NULL
	  || my_strlen_wordtab(temp) != 2
	  || add_data_graph(map->graph, temp[0], temp[1]))
	{
	  my_printf(2, "%s %d\n", ERROR_PARSING, *line);
	  return (NULL);
	}
      node = node->next;
      *line += 1;
    }
  my_printf(1, "\t[Adding link end]\n");
  return (node);
}
  
static t_node	*parse_room(t_node *file, int *line, t_map *map)
{
  char		**temp = NULL;
  char		**temp2 = NULL;
  t_node	*node = NULL;

  node = file->next;
  my_printf(1, "\t[Start parsing room]\n");
  my_printf(1, "\t[Adding room]\n");
  if ((map->graph = list_init(&graph_free_room)) == NULL)
    return (NULL);
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((temp = my_str_to_wordtab(node->data, ':')) == NULL
	  || my_strlen_wordtab(temp) != 2
	  || (temp2 = my_str_to_wordtab(temp[1], ',')) == NULL
	  || my_strlen_wordtab(temp2) != 3
	  || add_node_graph(map->graph, temp2, temp[0]))
	{
	  my_printf(2, "%s %d\n", ERROR_PARSING, *line);
	  return (NULL);
	}
      *line += 1;
      node = node->next;
    }
  my_printf(1, "\t[Adding room end]\n");
  return (node);
}

static t_node	*parse_data_graph(t_node *node, int *line, t_map *map)
{
  if (my_strcmp(node->data, ROOM_PARSING) == 0)
	{
	  if ((node = parse_room(node, line, map)) == NULL)
	    return (NULL);
	}
  else if (my_strcmp(node->data, LINK_PARSING) == 0)
    {
      if ((node = parse_link(node, line, map)) == NULL)
	return (NULL);
    }
  else if (my_strcmp(node->data, OUT_PARSING) == 0)
    {
      if ((node = parse_out(node, line, map)) == NULL)
	return (NULL);
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (NULL);
    }
  return (node);
}

t_node		*parse_graph(t_node *file, int *line, t_map *map)
{
  char		*data;
  t_node	*node;
  
  node = file->next;
  my_printf(1, "Start parsing graph:\n");
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((node = parse_data_graph(node, line, map)) == NULL)
	return (NULL);
      *line += 1;
      node = node->next;
    }
  return (node);
}
