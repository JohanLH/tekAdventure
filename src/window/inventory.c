/*
** inventory.c for window in /home/johan/Documents/MUL/tekadventure2
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May 23 15:13:41 2017 johan
** Last update Thu May 25 19:07:43 2017 johan
*/

#include "window.h"
#include "my_string.h"

void    check_inventory_door(t_window *window)
{
  t_out         *out;
  t_node        *node;
  t_node        *tmp;
  t_obj         *obj;

  node = window->game->map.out->first;
  while (node)
    {
      out = (t_out *)node->data;
      if (out->lock && out->object)
	{
	  tmp = window->inventory->first;
	  while (tmp)
	    {
	      obj = (t_obj *)tmp->data;
	      if (obj->is_anim && !my_strcmp(obj->anim.name, out->object))
		{
		  out->lock = 0;
		  return (list_delete_elem(window->inventory, tmp));
		}
	      tmp = tmp->next;
	    }
	}
      node = node->next;
    }
}

void    check_inventory_object(t_window *window)
{
  t_node        *node;
  t_node        *tmp;
  t_obj         *obj;
  t_obj         *o2;

  node = window->game->object->first;
  while (node)
    {
      obj = (t_obj *)node->data;
      if (obj->anim.lock && obj->anim.unlock)
	{
	  tmp = window->inventory->first;
	  while (tmp)
	    {
	      o2 = (t_obj *)tmp->data;
	      if (o2->is_anim && !my_strcmp(o2->anim.name, obj->anim.unlock))
		{
		  obj->anim.lock = 0;
		  return (list_delete_elem(window->inventory, tmp));
		}
	      tmp = tmp->next;
	    }
	}
      node = node->next;
    }
}

