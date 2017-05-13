/*
** parse_obj.c for parser in /home/iseeze92/Documents/tekAdventure/src/parser
** 
** Made by Johan Lhour
** Login   <iseeze92@epitech.net>
** 
** Started on  Sun May  7 00:11:23 2017 Johan Lhour
** Last update Sat May 13 19:00:27 2017 johan
*/

#include <stdlib.h>
#include "my_string.h"
#include "list.h"
#include "parsing.h"
#include "printf.h"

static t_node	*parse_data_obj(t_node *node, int *line, t_obj *obj)
{
  if (!my_strcmp(node->data, IMAGE_PARSING))
    {
      if (obj->is_img || (node = parse_image(node, &obj->image, line)) == NULL)
	return (NULL);
      obj->is_img = 1;
    }
  else if (!my_strcmp(node->data, ANIM_PARSING))
    {
      if (obj->is_anim || (node = parse_animation(node, line,
						  &obj->anim)) == NULL)
	return (NULL);
      obj->is_anim = 1;
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (NULL);
    }
  return (node);
}

t_node		*parse_obj(t_node *file, int *line, t_obj *obj)
{
  t_node	*node;

  node = file->next;
  obj->is_img = 0;
  obj->is_anim = 0;
  *line += 1;
  my_printf(1, "\tStart Parsing object\n");
  while (node && my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((node = parse_data_obj(node, line, obj)) == NULL)
	return (NULL);
      *line += 1;
      node = node->next;
    }
  if (!obj->is_img)
    return (NULL);
  my_printf(1, "\tParsing object done\n");
  return (node);
}
