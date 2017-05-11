/*
** action_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 17:03:15 2017 johan
** Last update Thu May 11 17:35:11 2017 johan
*/

#include "printf.h"
#include "window.h"
#include "graph.h"

int		action_window(t_window *window)
{
  t_node	*node;
  t_room	*room;

  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    {
      window->mouse_pos = sfMouse_getPosition((sfWindow *)window->window);
      my_printf(1, "x = %d y = %d\n", window->mouse_pos.x,
		window->mouse_pos.y);
      node = find_elem_graph_coor(window->game->map.graph, window->mouse_pos.x,
				  window->mouse_pos.y);
      room = (t_room *)node->data;
      my_printf(1, "Node Position :\tx = %d\n\t\ty = %d\n\t\tName : %s\n",
		room->coor.x, room->coor.y, room->name);
    }
  return (0);
}
