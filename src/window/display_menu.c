/*
** display_menu.c for window in /home/johan/Documents/MUL/tekadventure2/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 27 20:04:42 2017 johan
** Last update Mon May 29 12:48:20 2017 johan
*/

#include <stdlib.h>
#include "window.h"

static void	display_menu(t_window *window)
{
  t_node	*node;
  t_image	*image;
  t_obj		*obj;

  node = window->menu->first;
  sfRenderWindow_clear(window->window, sfBlack);
  while (node)
    {
      image = (t_image *)node->data;
      reload_time(image, image->clock, image->interval, &image->time);
      sfRenderWindow_drawSprite(window->window, image->sprite, NULL);
      node = node->next;
    }
  if (window->cursor)
    {
      obj = (t_obj *)window->cursor->data;
      sfRenderWindow_drawSprite(window->window, obj->image.sprite, NULL);
    }
  sfRenderWindow_display(window->window);
}

static int	pos_cursor(t_window *window)
{
  window->mouse_pos = sfMouse_getPosition((sfWindow *)window->window);
  if (window->mouse_pos.x > 175 && window->mouse_pos.y > 249 &&
      window->mouse_pos.x < 376 && window->mouse_pos.y < 335)
    return (1);
  if (window->mouse_pos.x > 175 && window->mouse_pos.y > 384 &&
      window->mouse_pos.x < 384 && window->mouse_pos.y < 465)
    return (2);
  return (0);
}

static void	check_cursor(t_window *window)
{
  t_obj		*obj;
  sfVector2f	pos;

  pos.x = window->mouse_pos.x;
  pos.y = window->mouse_pos.y;
  obj = window->cursor->data;
  if (pos_cursor(window))
    change_sprite_cursor(obj, 1, NULL, 2);
  else
    change_sprite_cursor(obj, 0, NULL, 2);
  sfSprite_setPosition(obj->image.sprite, pos);
}

int     menu_loop(t_window *window)
{
  if (window->music)
    sfMusic_pause(window->music);
  if (window->music_menu)
    sfMusic_play(window->music_menu);
  while (sfRenderWindow_isOpen(window->window))
    {
      display_menu(window);
      while (sfRenderWindow_pollEvent(window->window, &window->event))
	{
	  check_cursor(window);
	  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
	    {
	      if (pos_cursor(window) == 1)
		{
		  window->print_menu = 0;
		  return (0);
		}
	      if (pos_cursor(window) == 2)
		return (1);
	    }
	  if (window->event.type == sfEvtClosed)
	    return (1);
	}
    }
  return (0);
}
