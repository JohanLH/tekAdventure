/*
** parse_animation.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  9 13:49:55 2017 johan
** Last update Tue May  9 18:06:48 2017 johan
*/

#include <stdlib.h>
#include "parsing.h"
#include "list.h"
#include "my_string.h"
#include "printf.h"

static int	parse_interaction(char **temp, int *line, t_anim *anim)
{
  my_lower_case(temp[1]);
  if (!my_strcmp(temp[1], INTERACTION_ON))
    {
      anim->interaction = 1;
    }
  else if (!my_strcmp(temp[1], INTERACTION_OFF))
    {
      anim->interaction = 0;
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (1);
    }
  return (0);
}

static int	parse_data_action(t_node *node, int *line, t_anim *anim)
{
  char		**temp;

  if ((temp = my_str_to_wordtab(node->data, ':')) == NULL ||
      my_strlen_wordtab(temp) != 2)
    return (1);
  if (!my_strcmp(temp[0], ACTION_TYPE))
    {
      my_printf(1, "\t\t\t[Loading type]\n");
      if (anim->type != NULL || (anim->type = my_strdup(temp[1])) == NULL)
	return (1);
    }
  else if (!my_strcmp(temp[0], ACTION_INTERACTION))
    {
      my_printf(1, "\t\t\t[Loading interaction]\n");
      if (parse_interaction(temp, line, anim))
	return (1);
    }
  else
    {
      free_tab(temp);
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (1);
    }
  free_tab(temp);
  return (0);
}

static t_node	*parse_action(t_node *file, int *line, t_anim *anim)
{
  t_node	*node;

  node = file->next;
  *line += 1;
  my_printf(1, "\t\tStart Parsing action:\n", *line);
  while (my_strcmp(node->data, END_PARSING) != 0 && node)
    {
      if (parse_data_action(node, line, anim))
	return (NULL);
      node = node->next;
      *line += 1;
    }
  my_printf(1, "\t\tParsing action done\n");
  return (node);
}

static t_node	*parse_data_animation(t_node *node, int *line, t_anim *anim)
{
  if (!my_strcmp(node->data, ACTION_PARSING))
    {
      if ((node = parse_action(node, line, anim)) == NULL)
	return (NULL);
    }
  else if (!my_strcmp(node->data, IMAGE_PARSING))
    {
      if (anim->image != NULL || (node = malloc(sizeof(*anim->image))) == NULL)
	return (NULL);
      if ((node = parse_image(node, anim->image, line)) == NULL)
	return (NULL);
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (NULL);
    }
  return (node);
}

t_node		*parse_animation(t_node *file, int *line, t_anim *anim)
{
  t_node	*node;

  node = file->next;
  anim->image = NULL;
  anim->interaction = 0;
  anim->type = NULL;
  *line += 1;
  my_printf(1, "\t\tStart parsing animation:\n");
  while (node && my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((node = parse_data_animation(node, line, anim)) == NULL)
	return (NULL);
      node = node->next;
      *line += 1;
    }
  if (anim->type == NULL)
    return (NULL);
  my_printf(1, "\t\tParsing animation done\n");
  return (node);
}
