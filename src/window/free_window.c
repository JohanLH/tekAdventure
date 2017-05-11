/*
** free_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:45:55 2017 johan
** Last update Fri May 12 01:37:04 2017 johan
*/

#include "window.h"

void	free_window(t_window *window)
{
  t_obj	*obj;

  sfRenderWindow_destroy(window->window);
  if (window->cursor)
    {
      obj = (t_obj *)window->cursor->data;
      sfSprite_destroy(obj->image.sprite);
      sfTexture_destroy(obj->image.texture);
      if (obj->image.music)
	sfMusic_destroy(obj->image.music);
    }
}
