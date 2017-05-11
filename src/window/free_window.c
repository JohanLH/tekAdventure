/*
** free_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:45:55 2017 johan
** Last update Thu May 11 16:50:18 2017 johan
*/

#include "window.h"

void	free_window(t_window *window)
{
  sfRenderWindow_destroy(window->window);
}
