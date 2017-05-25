/*
** render_sprite_animation.c for window in /home/johan/Thing/tekAdventure/src/window
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May 12 20:30:40 2017 johan
** Last update Thu May 25 17:11:42 2017 johan
*/

#include "window.h"

int	render_sprite_anim(t_image *image)
{
  if (image->status != image->max)
    {
      image->status += 1;
      image->rect.left += image->incre_dim.x;
      image->rect.top += image->incre_dim.y;
      sfSprite_setTextureRect(image->sprite, image->rect);
      return (0);
    }
  image->status = 1;
  image->rect.left = image->rect_dim.left;
  image->rect.top = image->rect_dim.top;
  sfSprite_setTextureRect(image->sprite, image->rect);
  return (0);
}
