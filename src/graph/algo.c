/*
** algo.c for algo in /home/jack/Documents/sem2/CPE/CPE_2016_Lemin/src
** 
** Made by Jack
** Login   <jacques.lemarchand@epitech.eu>
** 
** Started on  Tue Apr 18 12:52:03 2017 Jack
** Last update Thu May 11 15:35:18 2017 johan
*/

#include <stdlib.h>
#include "list.h"
#include "graph.h"
#include "lemin.h"
#include "my_string.h"

int		is_room_used(char *name, t_list *path)
{
  t_list	*temp;

  temp = path->next;
  while (temp != path)
    {
      if (my_strcmp(name, temp->obj.name) == 0)
	return (1);
      temp = temp->next;
    }
  return (0);
}

t_object	*find_next_room(t_list *temp, t_list *path, t_ant ant)
{
  t_link	*templ;

  templ = temp->obj.link;
  while (templ)
    {
      if (is_room_used(templ->name, path) == 0)
	return (&templ->node->obj);
      templ = templ->next;
    }
  return (NULL);
}

t_room		*find_end_room(t_node *temp, t_root *path, t_node *end)
{
  t_node	*temp2;
  t_room	*room;
  t_link	*link;
  t_room	*room_end;

  
  room = (t_room *)temp->data;
  temp2 = room->link->first;
  while (temp2)
    {
      link = (t_link *)temp2->data;
      if (my_strcmp(link->name, ant.end->obj.name) == 0)
	return (&temp2->node->obj);
      temp2 = temp2->next;
    }
  return (NULL);
}

int		find_path(t_root *path, t_ant ant)
{
  t_node	*temp;
  t_room	*next_room;

  next_room = NULL;
  temp = path->first;
  while (temp->next)
    temp = temp->next;
  if ((next_room = find_end_room(temp, path, ant)) == NULL)
    {
      if ((next_room = find_next_room(temp, path, ant)) == NULL)
	return (84);
    }
  add_last_list(path, *next_room);
  return (0);
}

int		algo(t_root *root, t_node *start, t_node *end)
{
  t_root	*path;

  path = NULL;
  if ((path = list_init(NULL)) == NULL)
    return (84);
  if (list_prepend(path, ant.start->obj) == -1)
    return (84);
  while (is_arrived(path, ant) == 0)
    {
      if (find_path(path, ant) == 84)
	{
	  path = NULL;
	  output(path, root, ant);
	  return (84);
	}
    }
  output(path, root, ant);
  if (path == NULL)
    return (84);
  return (0);
}
