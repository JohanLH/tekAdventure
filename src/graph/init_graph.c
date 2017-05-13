/*
** init_graph.c for graph in /home/johan/Thing/tekadvanture/src/graph
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 12:53:27 2017 johan
** Last update Sat May 13 01:02:37 2017 johan
*/

#include <stdlib.h>
#include "my_string.h"
#include "graph.h"

int		add_node_graph(t_root *root, char **data, char *name)
{
  t_room	*room;
  int		error;

  error = 0;
  if ((room = malloc(sizeof(*room))) == NULL
      || (room->link = list_init(&graph_free_data)) == NULL)
    return (1);
  if ((room->name = my_strdup(name)) == NULL)
    return (1);
  if ((room->coor.x = my_atoi(data[0], &error)) < 0
      || (room->coor.y = my_atoi(data[1], &error)) < 0
      || (room->coor.z = my_atoi(data[2], &error)) < 0
      || error < 0)
    return (1);
  if (list_prepend(root, room))
    return (1);
  return (0);
}

int		add_data_graph(t_root *root, char *name1, char *name2)
{
  t_link	*link1;
  t_link	*link2;
  t_node	*room1;
  t_node	*room2;
  t_room	*roomptr1;
  t_room	*roomptr2;

  if ((room1 = find_elem_graph(root, name1)) == NULL
      || (room2 = find_elem_graph(root, name2)) == NULL
      || (link1 = malloc(sizeof(*link1))) == NULL
      || (link2 = malloc(sizeof(*link2))) == NULL)
    return (1);
  if ((link1->name = my_strdup(name1)) == NULL
      || (link2->name = my_strdup(name2)) == NULL)
    return (1);
  link1->room = room2;
  link2->room = room1;
  roomptr1 = (t_room *)room1->data;
  roomptr2 = (t_room *)room2->data;
  link1->dist = my_abs(roomptr1->coor.x - roomptr2->coor.x) +
    my_abs(roomptr1->coor.y - roomptr2->coor.y);
  link2->dist = link1->dist;
  if (list_prepend(roomptr1->link, link2) == 84
      || list_prepend(roomptr2->link, link1) == 84)
    return (1);
  return (0);
}
