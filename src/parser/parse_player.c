/*
** parse_player.c for parser in /home/johan/Thing/tekAdventure/src
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 13 19:52:29 2017 johan
** Last update Sat May 13 19:52:31 2017 johan
*/

#include <stdlib.h>
#include "my_string.h"
#include "parsing.h"
#include "graph.h"
#include "printf.h"

static t_node	*parse_spawn(t_node *file, int *line, t_player *player)
{
  t_node	*node;

  node = file->next;
  my_printf(1, "\t\tStart parsing spawn\n");
  while (my_strcmp(node->data, END_PARSING))
    {
      my_printf(1, "\t\t\t[Loading spawn]\n");
      if (player->node != NULL || player->is_position ||
	  (player->node = my_strdup(node->data)) == NULL)
	{
	  my_printf(2, "%s %d\n", ERROR_PARSING, *line);
	  return (NULL);
	}
      *line += 1;
      node = node->next;
    }
  my_printf(1, "\t\tParsing spawn done\n");
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
      if ((node = parse_spawn(node, line, player)) == NULL)
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
  player->is_position = 0;
  player->is_image = 0;
  player->node = NULL;
  my_printf(1, "\tStart parsing player\n");
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
  my_printf(1, "\tParsing player done\n");
  return (node);
}
