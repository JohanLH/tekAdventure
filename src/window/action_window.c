/*
** action_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 17:03:15 2017 johan
** Last update Sat May 13 19:17:21 2017 johan
*/

#include "printf.h"
#include "window.h"
#include "graph.h"
#include "my_string.h"

static t_node	*change_sprite_cursor(t_obj *obj, int value, t_node *node)
{
  if (value)
    {
      if (obj->image.status != obj->image.max)
	{
	  obj->image.status += 1;
	  obj->image.rect.left += obj->image.incre_dim.x;
	  obj->image.rect.top += obj->image.incre_dim.y;
	  sfSprite_setTextureRect(obj->image.sprite, obj->image.rect);
	}
      return (node);
    }
  if (obj->image.status == obj->image.max)
    {
      obj->image.rect.left -= obj->image.incre_dim.x;
      obj->image.rect.top -= obj->image.incre_dim.y;
      obj->image.status = 1;
      sfSprite_setTextureRect(obj->image.sprite, obj->image.rect);
    }
  return (NULL);
}

static t_node	*change_cursor(t_window *window)
{
  t_click	*click;
  t_node	*node;
  t_obj		*obj;
  
  node = window->click->first;
  obj = (t_obj *)window->cursor->data;
  while (node)
    {
      click = (t_click *)node->data;
      if (window->mouse_pos.x >= click->start.x && window->mouse_pos.x
	  <= click->end.x && window->mouse_pos.y >= click->start.y
	  && window->mouse_pos.y <= click->end.y)
	{
	  return (change_sprite_cursor(obj, 1, node));
	}
      node = node->next;
    }
  return (change_sprite_cursor(obj, 0, node));
}

static t_node	*move_cursor(t_window *window)
{
  t_obj		*obj;
  sfVector2f	pos;
  t_node	*node;
  
  pos.x = window->mouse_pos.x;
  pos.y = window->mouse_pos.y;
  if (window->cursor)
    {
      obj = (t_obj *)window->cursor->data;
      node = change_cursor(window);
      pos.x -= 10;
      pos.y -= 10;
      sfSprite_setPosition(obj->image.sprite, pos);
    }
  return (node);
}

static int	check_node(t_window *window)
{
  t_node	*node;
  t_room	*room;
  t_obj		*obj;

  my_printf(1, "x = %d y = %d\n", window->mouse_pos.x,
	    window->mouse_pos.y);
  node = find_elem_graph_coor(window->game->map.graph, window->mouse_pos.x,
			      window->mouse_pos.y);
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

int		action_window(t_window *window)
{
  t_node	*node;
  t_node	*node2;
  t_click	*click;
  t_obj		*obj;
  
  window->mouse_pos = sfMouse_getPosition((sfWindow *)window->window);
  node = move_cursor(window);
  if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
    {
      if (node)
	{
	  click = (t_click *)node->data;
	  obj = (t_obj *)click->obj->data;
	  my_printf(1, "%s\n", obj->anim.action);
	  if (obj->anim.is_action && !my_strcmp(obj->anim.action, LOAD))
	    obj->anim.load_image = 1;
	  if (obj->anim.is_action && !my_strcmp(obj->anim.action, DELETE))
	    {
	      list_delete_elem(window->game->object, click->obj);
	      list_delink_elem(window->click, node);
	      free(node);
	    }
	}
      check_node(window);
    }
  return (0);
}
