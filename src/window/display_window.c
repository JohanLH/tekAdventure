/*
** display_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:40:06 2017 johan
** Last update Fri May 12 00:56:41 2017 johan
*/

#include "window.h"

static void	display_window(t_window *window)
{
  t_obj		*obj;
  t_node	*node;

  sfRenderWindow_clear(window->window, sfBlack);
  sfRenderWindow_drawSprite(window->window, window->game->map.image.sprite, NULL);
  node = window->game->object->first;
  while (node)
    {
      obj = (t_obj *)node->data;
      sfRenderWindow_drawSprite(window->window, obj->image.sprite, NULL);
      node = node->next;
    }
  if (window->cursor)
    {
      obj = (t_obj *)window->cursor->data;
      sfRenderWindow_drawSprite(window->window, obj->image.sprite, NULL);
    }
  sfRenderWindow_display(window->window);
}

int	loop_window(t_window *window)
{
  while (sfRenderWindow_isOpen(window->window))
    {
      display_window(window);
      while (sfRenderWindow_pollEvent(window->window, &window->event))
	{
	  display_window(window);
	  action_window(window);
	  if (window->event.type == sfEvtClosed)
	    {
	      free_window(window);
	      return (0);
	    }
	}
    }
  return (0);
}
