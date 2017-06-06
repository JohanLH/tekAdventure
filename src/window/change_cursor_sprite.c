/*
** change_cursor_sprite.c for window in /home/johan/Documents/MUL/tekadventure2/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 27 20:34:48 2017 johan
** Last update Sat May 27 20:37:45 2017 johan
*/

#include <stdlib.h>
#include "window.h"

static t_node	*incre_cursor_sprite(t_obj *obj, t_node *node,
				     int power, int max)
{
  if (obj->image.status != max)
    {
      obj->image.status = obj->image.status + 1 * power;
      obj->image.rect.left = obj->image.rect.left +
	(obj->image.incre_dim.x * power);
      obj->image.rect.top = obj->image.rect.top +
	(obj->image.incre_dim.y * power);
      sfSprite_setTextureRect(obj->image.sprite, obj->image.rect);
    }
  return (node);
}

t_node   *change_sprite_cursor(t_obj *obj, int value,
			      t_node *node, int power)
{
  int           max;

  max = obj->image.max * power;
  if (max > 2)
    max -= 1;
  if (value)
    return (incre_cursor_sprite(obj, node, power, max));
  if (obj->image.status == max)
    {
      obj->image.rect.left = obj->image.rect.left -
	(obj->image.incre_dim.x * power);
      obj->image.rect.top = obj->image.rect.top -
	(obj->image.incre_dim.y * power);
      obj->image.status = 1;
      sfSprite_setTextureRect(obj->image.sprite, obj->image.rect);
    }
  return (NULL);
}
