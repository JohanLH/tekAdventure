/*
** free_graph.c for graph in /home/johan/Thing/tekadvanture/src/graph
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 13:56:15 2017 johan
** Last update Fri May 26 14:25:58 2017 Jack
*/

#include <stdlib.h>
#include "graph.h"

void		graph_free_data(void *ptr)
{
  t_link	*link;

  link = (t_link *)ptr;
  free(link->name);
  free(link);
}

void		graph_free_room(void *ptr)
{
  t_room	*room;

  room = (t_room *)ptr;
  list_delete_all(room->link);
  free(room->name);
  free(room);
}
