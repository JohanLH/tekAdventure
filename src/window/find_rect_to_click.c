/*
** find_rect_to_click.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May 12 11:50:43 2017 johan
** Last update Fri May 12 12:33:42 2017 johan
*/

#include <stdlib.h>
#include "my_string.h"
#include "window.h"

static void	free_click(void *ptr)
{
  t_click	*click;

  click = (t_click *)ptr;
  free(click);
}

static int	add_one_click(t_root *root, t_obj *obj)
{
  t_click	*click;
  sfIntRect	tmp;
  
  if ((click = malloc(sizeof(*click))) == NULL)
    return (1);
  click->start.x = obj->image.pos.x;
  click->start.y = obj->image.pos.y;
  click->end.x = (int)obj->image.pos.x + obj->image.rect.width;
  click->end.y = (int)obj->image.pos.y + obj->image.rect.height;
  if (list_prepend(root, click))
    return (1);
  return (0);
}

t_root		*find_rect_to_click(t_root *object)
{
  t_root	*root;
  t_node	*node;
  t_obj		*obj;

  if ((root = list_init(&free_click)) == NULL)
    return (NULL);
  node = object->first;
  while (node)
    {
      obj = (t_obj *)node->data;
      if (obj->anim.is_type && !my_strcmp(obj->anim.type, CLICK))
	{
	  if (add_one_click(root, obj))
	    return (NULL);
	}
      node = node->next;
    }
  return (root);
}
