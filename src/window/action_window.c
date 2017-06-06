/*
** action_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 17:03:15 2017 johan
** Last update Sun May 28 00:39:30 2017 johan
*/

#include "window.h"
#include "graph.h"
#include "my_string.h"

static int	reload_cursor(t_window *window)
{
  t_obj		*obj;

  if (window->cursor)
    {
      obj = (t_obj *)window->cursor->data;
      free(window->cursor);
      if (list_prepend(window->game->object, obj))
	return (1);
    }
  return (0);
}

static int	accept_door(t_window *window, t_out *out)
{
  t_room	*room;
  int		i;

  i = 0;
  room = (t_room *)window->game->player.position->data;
  if (out->lock)
    return (0);
  while (out->all_node[i])
    {
      if (!my_strcmp(room->name, out->all_node[i]))
	return (1);
      i++;
    }
  return (0);
}

static int	change_map(t_window *window, t_node *door)
{
  t_node	*node;
  t_game	*game;
  t_out		*out;

  node = window->all_map->first;
  out = (t_out *)door->data;
  while (node)
    {
      game = (t_game *)node->data;
      if (!my_strcmp(game->name, out->name))
	{
	  if (!accept_door(window, out))
	    return (0);
	  reload_cursor(window);
	  window->game = game;
	  init_window(NULL, window, 0);
	  return (0);
	}
      node = node->next;
    }
  return (0);
}

int		action_window(t_window *window)
{
  t_node	*obj;
  t_node	*door;

  door = NULL;
  obj = NULL;
  window->mouse_pos = sfMouse_getPosition((sfWindow *)window->window);
  move_cursor(window, &obj, &door);
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    window->print_menu = 1;
  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    {
      action_object(window, obj);
      if (window->move != 1)
	{
	  if (door)
	    change_map(window, door);
	}
    }
  if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
    check_node(window);
  check_inventory_door(window);
  check_inventory_object(window);
  return (0);
}
