/*
** pathfinding.c for graph in /home/johan/Thing/tekAdventure/src/graph
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 15:07:14 2017 johan
** Last update Sat May 27 23:50:32 2017 johan
*/

#include <stdlib.h>
#include <limits.h>
#include "graph.h"

static void	init_path(void *ptr)
{
  t_room	*room;

  room = (t_room *)ptr;
  room->weigth = SHRT_MAX;
  room->prev = NULL;
  room->visited = 0;
}

static t_node	*find_unvisited_room(t_root *root)
{
  t_node	*node;
  t_room	*room;
  t_node	*near;
  t_room	*room_near;

  near = NULL;
  node = root->first;
  while (node)
    {
      room = (t_room *)node->data;
      if (room->visited == 0 && (near == NULL ||
				 room->weigth < room_near->weigth))
	{
	  room_near = room;
	  near = node;
	}
      node = node->next;
    }
  return (near);
}

static void	check_new_node(t_node *actual)
{
  t_link	*link;
  t_room	*room;
  t_room	*room2;
  t_node	*node;
  int		value;

  room = (t_room *)actual->data;
  room->visited = 1;
  node = room->link->first;
  while (node)
    {
      link = (t_link *)node->data;
      value = room->weigth + link->dist;
      room2 = (t_room *)link->room->data;
      if (value < room2->weigth)
	{
	  room2->weigth = value;
	  room2->prev = actual;
	}
      node = node->next;
    }
}

static void	free_path(void *ptr)
{
  t_path	*path;

  path = (t_path *)ptr;
  free(path);
}

t_root		*path_finding(t_root *graph, t_node *start, t_node *end)
{
  t_root	*path;
  t_room	*room;
  t_node	*node;
  t_path	*new_path;

  if ((path = list_init(free_path)) == NULL)
    return (NULL);
  list_for_each(graph, &init_path);
  room = (t_room *)start->data;
  room->weigth = 0;
  while ((node = find_unvisited_room(graph)))
    check_new_node(node);
  while (end)
    {
      if ((new_path = malloc(sizeof(*new_path))) == NULL)
	return (NULL);
      new_path->node = end;
      if (list_prepend(path, new_path))
	return (NULL);
      room = (t_room *)end->data;
      end = room->prev;
    }
  return (path);
}
