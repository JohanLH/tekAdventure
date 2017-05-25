/*
** init_window.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:36:42 2017 johan
** Last update Thu May 25 14:19:31 2017 johan
*/

#include "window.h"
#include "graph.h"

static void	init_pos_player(t_window *window)
{
  t_room	*room;
  sfVector2f	pos;
  sfVector2f	or;
  
  room = (t_room *)window->game->player.position->data;
  sfSprite_setScale(window->game->player.image.sprite,
		    window->game->player.image.scale);
  if (window->game->init == 0)
    {
      or.x = window->game->player.image.rect_dim.width / 2
	/ window->game->player.image.scale.x;
      or.y = window->game->player.image.rect_dim.height
	/ window->game->player.image.scale.y;
      sfSprite_setOrigin(window->game->player.image.sprite, or);
    }
  window->game->init = 1;
  pos.x = room->coor.x;
  pos.y = room->coor.y;
  window->game->player.image.pos = pos;
  sfSprite_setPosition(window->game->player.image.sprite, pos);
}

int		init_window(char *name, t_window *window, int init)
{
  sfVideoMode	mode;

  if (init)
    {
      mode.width = WIDTH;
      mode.height = HEIGHT;
      mode.bitsPerPixel = 32;
      if (!(window->window =
	    sfRenderWindow_create(mode, name, sfResize | sfClose, NULL)))
	return (1);
      if ((window->inventory = list_init(window->game->object->my_free)) == NULL)
	return (1);
    }
  if ((window->cursor = find_cursor(window->game->object)) != NULL)
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
  if ((window->click = find_rect_to_click(window->game->object)) == NULL)
    return (1);
  window->clock = sfClock_create();
  window->time = sfSeconds(0);
  window->move = 0;
  init_pos_player(window);
  return (0);
}
