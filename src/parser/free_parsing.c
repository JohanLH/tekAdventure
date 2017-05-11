/*
** free_parsing.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 17:45:03 2017 johan
** Last update Thu May 11 19:09:17 2017 johan
*/

#include <stdlib.h>
#include "parsing.h"

void	free_image(t_image *image)
{
  if (image->sprite)
    {
      sfSprite_destroy(image->sprite);
      sfTexture_destroy(image->texture);
    }
  if (image->music)
    {
      sfMusic_destroy(image->music);
    }
}

void		free_parsing(t_game *game)
{
  
  free_image(&game->map.image);
  free_image(&game->player.image);
  free(game->player.node);
  list_delete_all(game->map.graph);
  list_delete_all(game->object);
  free(game);
}
