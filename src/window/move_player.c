/*
** move_player.c for window in /home/johan/Thing/tekAdventure
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon May 15 22:40:08 2017 johan
** Last update Sun May 28 18:34:04 2017 Jack
*/

#include "window.h"
#include "graph.h"

static int	calcul_velocity(int a, int b)
{
  int		velocity;

  velocity = a - b;
  if (velocity > 0)
    return (-1);
  if (velocity < 0)
    return (1);
  return (0);
}

static void	stop_player(t_window *window, t_room *room, t_node *node)
{
  if (window->game->player.image.pos.y == room->coor.y
      && window->game->player.image.pos.x == room->coor.x)
    {
      if (window->path->first->next == NULL)
	window->game->player.position = node;
      list_delete_elem(window->path, window->path->first);
    }
}

static void	change_character(t_window *window, int x, int y)
{
  if (x < 0)
    window->game->player.image.rect.top = LEFT;
  else if (x > 0)
    window->game->player.image.rect.top = RIGHT;
  if (y < 0)
    {
      window->game->player.image.rect.top = TOP;
      window->game->player.image.scale.y -=
	window->game->player.image.incre_scale.y;
    }
  else if (y > 0)
    {
      window->game->player.image.rect.top = BOTTOM;
      window->game->player.image.scale.y +=
	window->game->player.image.incre_scale.y;
    }
  if (x < 0 && y < 0)
    window->game->player.image.rect.top = TOP_LEFT;
  else if (x < 0 && y > 0)
    window->game->player.image.rect.top = BOTTOM_LEFT;
  else if (x > 0 && y < 0)
    window->game->player.image.rect.top = TOP_RIGHT;
  else if (x > 0 && y > 0)
    window->game->player.image.rect.top = BOTTOM_RIGHT;
}

static void	change_sprite_player(t_window *window, t_room *room,
				     t_path *path)
{
  change_character(window,
		   calcul_velocity(window->game->player.image.pos.x,
				   room->coor.x),
		   calcul_velocity(window->game->player.image.pos.y,
				   room->coor.y));
  window->game->player.image.pos.x +=
    calcul_velocity(window->game->player.image.pos.x, room->coor.x);
  window->game->player.image.pos.y +=
    calcul_velocity(window->game->player.image.pos.y, room->coor.y);
  stop_player(window, room, path->node);
  sfSprite_setPosition(window->game->player.image.sprite,
		       window->game->player.image.pos);
  sfSprite_setScale(window->game->player.image.sprite,
		       window->game->player.image.scale);
}

int     move_player(t_window *window)
{
  t_room        *room;
  t_path        *path;

  if (window->move == 0 || window->path == NULL)
    return (0);
  if (window->path->first == NULL)
    {
      list_delete_all(window->path);
      window->move = 0;
      window->game->player.image.rect.left = 0;
      sfSprite_setTextureRect(window->game->player.image.sprite,
		       window->game->player.image.rect);
      return (0);
    }
  path = (t_path *)window->path->first->data;
  room = (t_room *)path->node->data;
  change_sprite_player(window, room, path);
  return (0);
}

