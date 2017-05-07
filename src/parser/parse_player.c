/*
** parse_player.c for parser in /home/iseeze92/Documents/tekAdventure/src/parser
** 
** Made by Johan Lhour
** Login   <iseeze92@epitech.net>
** 
** Started on  Sat May  6 20:09:03 2017 Johan Lhour
** Last update Sun May  7 00:09:16 2017 Johan Lhour
*/

#include <stdlib.h>
#include "my_string.h"
#include "parsing.h"
#include "graph.h"

static t_node	*parse_spawn(t_node *file, int *line, t_player *player)
{
  t_node	*node;

  node = file->next;
  while (my_strcmp(node->data, END_PARSING))
    {
      if (player->node != NULL || player->is_position ||
	  (player->node = my_strdup(node->data)) == NULL)
	{
	  my_printf(2, "%s %d\n", ERROR_PARSING, *line);
	  return (NULL);
	}
      *line += 1;
      node = node->next;
    }
  return (node);
}

static t_node	*parse_data_player(t_node *node, int *line, t_player *player)
{
  if (!my_strcmp(node->data, IMAGE_PARSING))
    {
      if ((node = parse_image(node, &player->image, line)) == NULL
	  || player->is_image)
	return (NULL);
      player->is_image = 1;
    }
  else if (!my_strcmp(node->data, SPAWN_PARSING)) 
    {
      if ((node = parse_spawn(node, line, &player->image)) == NULL)
	return (NULL);
      player->is_position = 1;
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (NULL);
    }
  return (node);
}

t_node		*parse_player(t_node *file, int *line, t_player *player)
{
  t_node	*node = NULL;

  node = file->next;
  *line += 1;
  player->is_positon = 0;
  player->is_image = 0;
  player->node = NULL;
  while (my_strcmp(node->data, END_PARSING))
    {
      if ((node = parse_data_player(node, line, player)) == NULL)
	return (NULL);
      *line += 1;
      node = node->next;
    }
  if (player->is_position == 0 || player->is_image == 0
      || player->node == NULL)
    return (NULL);
  return (node);
}
