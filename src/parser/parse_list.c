/*
** parse_list.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  9 15:48:41 2017 johan
** Last update Thu May 11 19:13:19 2017 johan
*/

#include <stdlib.h>
#include "graph.h"
#include "my_string.h"
#include "printf.h"
#include "parsing.h"

static void	free_object(void *ptr)
{
  t_obj		*object;

  object = (t_obj *)ptr;
  free_image(&object->image);
  if (object->anim.is_type)
    free(object->anim.type);
  if (object->anim.is_img)
    {
      free_image(object->anim.image);
      free(object->anim.image);
    }
  free(object);
}

static t_node	*parse_obj_list(t_node *node, t_game *game, int *line)
{
  t_obj		*object;
  t_obj		temp;

  if ((object = malloc(sizeof(*object))) == NULL ||
      (node = parse_obj(node, line, &temp)) == NULL)
    return (NULL);
  *object = temp;
  if (list_prepend(game->object, object))
    return (NULL);
  return (node);
}

static t_node	*parse_data_list(t_node *node, t_game *game, int *line)
{
  t_obj		*object;
  t_obj		temp;
  
  if (!my_strcmp(node->data, MAP_PARSING))
    {
      if (game->is_map || (node = parse_map(&game->map, node, line)) == NULL)
	return (NULL);
      game->is_map = 1;
    }
  else if (!my_strcmp(node->data, PLAYER_PARSING))
    {
      if (game->is_player ||
	  (node = parse_player(node, line, &game->player)) == NULL)
	return (NULL);
      game->is_player = 1;
    }
  else if (!my_strcmp(node->data, OBJ_PARSING))
    {
      if ((node = parse_obj_list(node, game, line)) == NULL)
	return (NULL);
    }
  else
    return (NULL);
  return (node);
}

t_game		*parse_list(t_root *root)
{
  t_node	*node;
  int		line;
  t_game	*game;

  line = 1;
  node = root->first;
  if ((game = malloc(sizeof(*game))) == NULL ||
      (game->object = list_init(&free_object)) == NULL)
    return (NULL);
  game->is_map = 0;
  game->is_player = 0;
  while (node)
    {
      if ((node = parse_data_list(node, game, &line)) == NULL)
	return (NULL);
      node = node->next;
      line++;
    }
  if (!game->is_map || !game->is_player ||
      (game->player.position =
       find_elem_graph(game->map.graph, game->player.node)) == NULL)
    return (NULL);
  return (game);
}
