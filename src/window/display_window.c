/*
** display_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:40:06 2017 johan
** Last update Thu May 11 17:20:49 2017 johan
*/

#include "window.h"

static void	display_window(t_window *window)
{
  sfRenderWindow_display(window->window);
  sfRenderWindow_clear(window->window, sfBlack);
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
