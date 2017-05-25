/*
** parse_image.c for parser in /home/johan/Thing/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 20:24:55 2017 johan
** Last update Tue May 16 16:27:15 2017 johan
*/

#include "printf.h"
#include "parsing.h"
#include "list.h"
#include "my_string.h"
#include "get_next_line.h"

static void	init_image(t_image *image)
{
  image->sprite = NULL;
  image->texture = NULL;
  image->music = NULL;
  image->rect.left = 0;
  image->rect.top = 0;
  image->rect.width = 0;
  image->rect.height = 0;
  image->rect_dim = image->rect;
  image->max = 1;
  image->pos.x = 0;
  image->pos.y = 0;
  image->incre_dim.x = 0;
  image->incre_dim.y = 0;
  image->status = 1;
  image->scale.x = 1;
  image->scale.y = 1;
  image->incre_scale.x = 0;
  image->incre_scale.y = 0;
  image->interval = 0;
}

static int	parse_image2(char *temp, t_image *image,
			     t_node *node, int line)
{
  char		**temp2 = NULL;
  t_parser	*parser;

  if ((temp2 = my_str_to_wordtab(temp, ':')) == NULL)
    return (1);
  if (my_strlen_wordtab(temp2) != 2)
    {
      my_printf(2, "%s %d\n--> %s\n", ERROR_PARSING, line, temp);
      return (1);
    }
  my_lower_case(temp2[0]);
  while (node)
    {
      parser = (t_parser*)node->data;
      if (my_strcmp(temp2[0], parser->cmd) == 0)
	{
	  if (parser->parser_function(image, temp2[1], line))
	    return (1);
	  free_tab(temp2);
	  return (0);
	}
      node = node->next;
    }
  my_printf(2, "%s %d\n--> %s\n", ERROR_PARSING, line, temp);
  return (1);
}

static int	apply_image(t_image *image)
{
  if (!image->sprite)
    return (1);
  sfSprite_setPosition(image->sprite, image->pos);
  sfSprite_setScale(image->sprite, image->scale);
  if (image->rect.width)
    sfSprite_setTextureRect(image->sprite, image->rect);
  image->rect = sfSprite_getTextureRect(image->sprite);
  image->rect_dim = image->rect;
  image->rect_dim.width *= image->scale.x;
  image->rect_dim.height *= image->scale.y;
  if (image->interval)
    {
      image->clock = sfClock_create();
      image->time = sfSeconds(0);
    }
  return (0);
}

t_node		*parse_image(t_node *file, t_image *image, int *line)
{
  t_root	*fct_parser;
  t_node	*node;

  init_image(image);
  node = file->next;
  my_printf(1, "\t\tStart parsing image:\n");
  if ((fct_parser = init_image_function()) == NULL)
    return (NULL);
  *line += 1;
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if (parse_image2(node->data, image, fct_parser->first, *line))
	return (NULL);
      *line += 1;
      node = node->next;
    }
  list_delete_all(fct_parser);
  if (apply_image(image))
    return (NULL);
  my_printf(1, "\t\tParsing image done\n");
  return (node);
}
