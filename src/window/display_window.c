/*
** display_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:40:06 2017 johan
** Last update Thu May 25 17:14:52 2017 johan
*/

#include "window.h"

static void	display_inventory(t_window *window)
{
  t_node	*node;
  t_obj		*obj;
  
  node = window->inventory->first;
  while (node)
    {
      obj = (t_obj *)node->data;
      sfRenderWindow_drawSprite(window->window, obj->image.sprite, NULL);
      node = node->next;
    }
}

static int	reload_time(t_image *image, sfClock *clock,
			    int interval, sfTime *time)
{
  if (interval)
    {
      *time = sfClock_getElapsedTime(clock);
      if ((int)time->microseconds > interval)
	{
	  if (image != NULL)
	    render_sprite_anim(image);
	  *time = sfClock_restart(clock);
	  return (1);
	}
    }
  return (0);
}

static void	display_object(t_window *window)
{
  t_obj		*obj;
  t_node	*node;

  node = window->game->object->first;
  while (node)
    {
      obj = (t_obj *)node->data;
      reload_time(&obj->image, obj->image.clock, obj->image.interval,
		  &obj->image.time);
      if (obj->anim.load_image == 1 && obj->anim.image)
	{
	  if (reload_time(obj->anim.image, obj->anim.clock, obj->anim.interval,
			  &obj->anim.time))
	    obj->anim.load_image = 0;
	  reload_time(obj->anim.image, obj->anim.image->clock,
		      obj->anim.image->interval, &obj->anim.image->time);
	  sfRenderWindow_drawSprite(window->window,
				    obj->anim.image->sprite, NULL);
	}
      if (obj->anim.visibility)
	sfRenderWindow_drawSprite(window->window, obj->image.sprite, NULL);
      node = node->next;
    }
}

static void	display_window(t_window *window)
{
  t_obj		*obj;

  sfRenderWindow_clear(window->window, sfBlack);
  sfRenderWindow_drawSprite(window->window,
			    window->game->map.image.sprite, NULL);
  reload_time(&window->game->map.image, window->game->map.image.clock,
	     window->game->map.image.interval, &window->game->map.image.time);
  if (window->move)
    {
      if (reload_time(NULL, window->clock, 1500, &window->time))
	move_player(window);
      reload_time(&window->game->player.image, window->game->player.image.clock
      		  , window->game->player.image.interval,
      		  &window->game->player.image.time);
    }
  display_object(window);
  sfRenderWindow_drawSprite(window->window,
			    window->game->player.image.sprite, NULL);
  display_inventory(window);
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
