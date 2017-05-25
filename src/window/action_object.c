/*
** action_object.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May 16 22:15:44 2017 johan
** Last update Thu May 25 19:29:10 2017 johan
*/

#include "window.h"
#include "graph.h"
#include "my_string.h"

static int	player_near_object(t_window *window, t_obj *obj)
{
  t_room        *room;
  int           i;

  i = 0;
  room = (t_room *)window->game->player.position->data;
  if (!obj->anim.node)
    return (0);
  while (obj->anim.node[i])
    {
      if (!my_strcmp(room->name, obj->anim.node[i]))
	return (1);
      i++;
    }
  return (0);
  
}

static int	move_obj_to_inventory(t_window *window, t_node *node,
				      t_click *click, t_obj *object)
{
  sfClock	*clock;
  sfTime	time;

  clock = sfClock_create();
  time = sfSeconds(0);
  object->image.scale.x = 1;
  object->image.scale.y = 1;
  sfSprite_setScale(object->image.sprite, object->image.scale);
  object->image.pos.x = INVENTORY_SIZE * window->inventory->nbr_elem;
  object->image.pos.y = 0;
  sfSprite_setPosition(object->image.sprite, object->image.pos);
  while ((int)time.microseconds < object->anim.interval)
    {
      if (object->anim.image)
	sfRenderWindow_drawSprite(window->window,
				  object->anim.image->sprite, NULL);
      sfRenderWindow_display(window->window);
      time = sfClock_getElapsedTime(clock);
    }
  list_delink_elem(window->game->object, click->obj);
  list_delete_elem(window->click, node);
  if (list_prepend(window->inventory, object))
    return (1);
  return (0);
}

void		action_object(t_window *window, t_node *node)
{
  t_obj		*obj;
  t_click	*click;

  if (node)
    {
      click = (t_click *)node->data;
      obj = (t_obj *)click->obj->data;
      if (player_near_object(window, obj))
	{
	  if (obj->anim.load && obj->anim.lock == 0)
	    {
	      obj->anim.load_image = 1;
	      obj->anim.time = sfClock_restart(obj->anim.clock);
	    }
	  if (obj->anim.is_action && !my_strcmp(obj->anim.action, INVENTORY)
	      && !obj->anim.lock)
	    move_obj_to_inventory(window, node, click, obj);
	  if (obj->anim.is_action && !my_strcmp(obj->anim.action, DELETE))
	    {
	      list_delete_elem(window->game->object, click->obj);
	      list_delete_elem(window->click, node);
	    }
	}
    }
}
