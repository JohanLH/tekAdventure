/*
** parse_animation.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  9 13:49:55 2017 johan
** Last update Sat May 13 19:50:13 2017 johan
*/

#include <stdlib.h>
#include "parsing.h"
#include "list.h"
#include "my_string.h"
#include "printf.h"

static int	parse_data_action(char *data, int *line, t_anim *anim,
				  t_node *node)
{
  char		**temp;
  t_parser	*parser;

  if ((temp = my_str_to_wordtab(data, ':')) == NULL ||
      my_strlen_wordtab(temp) != 2)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line);
      return (1);
    }
  my_lower_case(temp[0]);
  while (node)
    {
      parser = (t_parser *)node->data;
      if (!my_strcmp(temp[0], parser->cmd))
	{
	  if (parser->parser_function2(anim, temp[1], *line))
	    return (1);
	  free_tab(temp);
	  return (0);
	}
      node = node->next;
    }
  free_tab(temp);
  my_printf(2, "%s %d\n", ERROR_PARSING, *line);
  return (1);
}

static t_node	*parse_action(t_node *file, int *line, t_anim *anim,
			      t_root *ptr_fct)
{
  t_node	*node;

  node = file->next;
  *line += 1;
  my_printf(1, "\t\tStart Parsing action:\n", *line);
  while (my_strcmp(node->data, END_PARSING) != 0 && node)
    {
      if (parse_data_action(node->data, line, anim, ptr_fct->first))
	return (NULL);
      node = node->next;
      *line += 1;
    }
  my_printf(1, "\t\tParsing action done\n");
  return (node);
}

static t_node	*parse_data_animation(t_node *node, int *line, t_anim *anim,
				      t_root *ptr_fct)
{
  t_image	temp;

  if (!my_strcmp(node->data, ACTION_PARSING))
    {
      if ((node = parse_action(node, line, anim, ptr_fct)) == NULL)
	return (NULL);
    }
  else if (!my_strcmp(node->data, IMAGE_PARSING))
    {
      if (anim->is_img || (anim->image = malloc(sizeof(*anim->image))) == NULL
	  || (node = parse_image(node, &temp, line)) == NULL)
	return (NULL);
      *anim->image = temp;
      anim->is_img = 1;
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, *line, node->data);
      return (NULL);
    }
  return (node);
}

static void	init_anim(t_anim *anim)
{
  anim->interaction = 0;
  anim->is_img = 0;
  anim->is_action = 0;
  anim->is_type = 0;
  anim->load_image = 0;
  anim->action = NULL;
  anim->type = NULL;
  anim->image = NULL;
}

t_node		*parse_animation(t_node *file, int *line, t_anim *anim)
{
  t_node	*node;
  t_root	*ptr_fct;

  node = file->next;
  *line += 1;
  if ((ptr_fct = init_anim_function()) == NULL)
    return (NULL);
  init_anim(anim);
  my_printf(1, "\t\tStart parsing animation:\n");
  while (node && my_strcmp(node->data, END_PARSING) != 0)
    {
      if ((node = parse_data_animation(node, line, anim, ptr_fct)) == NULL)
	return (NULL);
      node = node->next;
      *line += 1;
    }
  if (!anim->is_type)
    return (NULL);
  list_delete_all(ptr_fct);
  my_printf(1, "\t\tParsing animation done\n");
  return (node);
}
