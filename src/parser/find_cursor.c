/*
** find_cursor.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 20:01:26 2017 johan
** Last update Fri May 12 00:54:56 2017 johan
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
	  if (object->first == tmp)
	    object->first = tmp->next;
	  if (object->last == tmp)
	    object->last = tmp->prev;
	  if (tmp->prev)
	    tmp->prev->next = tmp->next;
	  if (tmp->next)
	    tmp->next->prev = tmp->prev;
	  return (tmp);
	}
      tmp = tmp->next;
    }
  return (NULL);
}
