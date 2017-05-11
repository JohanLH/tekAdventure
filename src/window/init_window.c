/*
** init_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:36:42 2017 johan
** Last update Fri May 12 01:15:05 2017 johan
*/

#include "window.h"

int		init_window(char *name, t_window *window)
{
  sfVideoMode	mode;

  mode.width = WIDTH;
  mode.height = HEIGHT;
  mode.bitsPerPixel = 32;
  if (!(window->window =
	sfRenderWindow_create(mode, name, sfResize | sfClose, NULL)))
    return (1);
  if ((window->cursor = find_cursor(window->game->object)) != NULL)
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
  return (0);
}
