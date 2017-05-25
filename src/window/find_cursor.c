/*
** find_cursor.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 20:01:26 2017 johan
** Last update Sat May 20 01:38:54 2017 johan
*/

#include "my_string.h"
#include "parsing.h"

t_node		*find_cursor(t_root *object)
{
  t_node	*tmp;
  t_obj		*obj;

  tmp = object->first;
  while (tmp)
    {
      obj = (t_obj*)tmp->data;
      if (obj->anim.is_type && !my_strcmp(obj->anim.type, CURSOR))
	{
	  list_delink_elem(object, tmp);
	  return (tmp);
	}
      tmp = tmp->next;
    }
  return (NULL);
}
