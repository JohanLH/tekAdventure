/*
** find_elem_graph.c for graph in /home/johan/Thing/tekadvanture/src/graph
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 12:56:11 2017 johan
** Last update Sat May 13 00:46:06 2017 johan
*/

#include <stdlib.h>
#include "my_string.h"
#include "graph.h"

int	my_abs(int value)
{
  if (value < 0)
    return (-value);
  return (value);
}

t_node		*find_elem_graph(t_root *root, char *name)
{
  t_node	*temp;
  t_room	*room;
  
  temp = root->first;
  while (temp)
    {
      room = (t_room *)temp->data;
      if (my_strcmp(room->name, name) == 0)
	return (temp);
      temp = temp->next;
    }
  return (NULL);
}

t_node		*find_elem_graph_coor(t_root *root, int x, int y)
{
  t_node	*value;
  t_node	*tmp;
  t_room	*room_value;
  t_room	*room_tmp;

  value = root->first;
  tmp = value->next;
  while (tmp)
    {
      room_value = (t_room *)value->data;
      room_tmp = (t_room *)tmp->data;
      if (my_abs(room_tmp->coor.x - x) < my_abs(room_value->coor.x - x)
	  && my_abs(room_tmp->coor.x - x) + my_abs(room_tmp->coor.y - y)
	  < my_abs(room_value->coor.x - x) + my_abs(room_value->coor.y - y))
	value = tmp;
      if (my_abs(room_tmp->coor.y - y) < my_abs(room_value->coor.y - y)
	  && my_abs(room_tmp->coor.x - x) + my_abs(room_tmp->coor.y - y)
	  < my_abs(room_value->coor.x - x) + my_abs(room_value->coor.y - y))
	value = tmp;
      tmp = tmp->next;
    }
  return (value);
}

