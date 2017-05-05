/*
** find_elem_graph.c for graph in /home/johan/Thing/tekadvanture/src/graph
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 12:56:11 2017 johan
** Last update Fri May  5 14:14:24 2017 johan
*/

#include <stdlib.h>
#include <my_string.h>
#include "graph.h"

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
