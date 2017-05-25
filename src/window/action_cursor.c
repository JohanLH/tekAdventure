/*
** action_cursor.c for window in /home/johan/Documents/MUL/tekadventure2
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 20 01:01:16 2017 johan
** Last update Thu May 25 14:14:41 2017 johan
*/

#include "printf.h"
#include "window.h"
#include "graph.h"
#include "my_string.h"

static t_node   *change_sprite_cursor(t_obj *obj, int value,
				      t_node *node, int power)
{
  int		max;

  max = obj->image.max * power;
  if (max > 2)
    max -= 1;
  if (value)
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

static t_node   *change_cursor(t_window *window)
{
  t_click       *click;
  t_node        *node;
  t_obj         *obj;
  t_obj		*obj2;
  
  node = window->click->first;
  obj = (t_obj *)window->cursor->data;
  while (node)
    {
      click = (t_click *)node->data;
      if (window->mouse_pos.x >= click->start.x && window->mouse_pos.x
	  <= click->end.x && window->mouse_pos.y >= click->start.y
	  && window->mouse_pos.y <= click->end.y)
	{
	  obj2 = (t_obj *)click->obj->data;
	  if (obj2->anim.lock == 0)
	    return (change_sprite_cursor(obj, 1, node, 2));
	  else
	    return (change_sprite_cursor(obj, 1, node, 1));
	}
      node = node->next;
    }
  return (change_sprite_cursor(obj, 0, node, 1));
}

static t_node	*change_cursor_door(t_window *window)
{
  t_out		*out;
  t_node        *node;
  t_obj         *obj;

  node = window->game->map.out->first;
  obj = (t_obj *)window->cursor->data;
  while (node)
    {
      out = (t_out *)node->data;
      if (window->mouse_pos.x >= out->start.x && window->mouse_pos.x
	  <= out->end.x && window->mouse_pos.y >= out->start.y
	  && window->mouse_pos.y <= out->end.y)
	{
	  if (!out->lock)
	    return (change_sprite_cursor(obj, 1, node, 2));
	  else
	    return (change_sprite_cursor(obj, 1, node, 1));
	}
      node = node->next;
    }
  return (change_sprite_cursor(obj, 0, node, 2));
}

void		move_cursor(t_window *window, t_node **obj, t_node **door)
{
  t_obj         *object;
  sfVector2f    pos;

  pos.x = window->mouse_pos.x;
  pos.y = window->mouse_pos.y;
  if (window->cursor)
    {
      object = (t_obj *)window->cursor->data;
      if ((obj[0] = change_cursor(window)) == NULL)
	door[0] = change_cursor_door(window);
      pos.x -= 10;
      sfSprite_setPosition(object->image.sprite, pos);
    }
}

int      check_node(t_window *window)
{
  t_node        *node;
  t_room        *room;
  t_obj         *obj;

  my_printf(1, "x = %d y = %d\n", window->mouse_pos.x, window->mouse_pos.y);
  node = find_elem_graph_coor(window->game->map.graph, window->mouse_pos.x,
			      window->mouse_pos.y);
  if (window->move == 0)
    {
      window->path = path_finding(window->game->map.graph,
				  window->game->player.position, node);
      window->move = 1;
      window->game->player.position = window->path->last;
    }
  if (window->cursor)
    {
      obj = (t_obj *)window->cursor->data;
      if (obj->image.music)
	sfMusic_play(obj->image.music);
    }
  room = (t_room *)node->data;
  my_printf(1, "Node Position :\tx = %d\n\t\ty = %d\n\t\tName : %s\n",
	    room->coor.x, room->coor.y, room->name);
  return (0);
}
