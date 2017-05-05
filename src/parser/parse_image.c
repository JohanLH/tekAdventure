/*
** parse_image.c for parser in /home/johan/Thing/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 20:24:55 2017 johan
** Last update Fri May  5 12:39:03 2017 johan
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
  image->pos.x = 0;
  image->pos.y = 0;
  image->scale = 1;
  image->incre_scale.x = 0;
  image->incre_scale.y = 0;
}

static int	parse_image2(char *temp, t_image *image, t_root *fct_parser, int line)
{
  char		**temp2 = NULL;
  t_node	*node;
  t_parser	*parser;

  node = fct_parser->first;
  if ((temp2 = my_str_to_wordtab(temp, ':')) == NULL)
    return (1);
  if (my_strlen_wordtab(temp2) != 2)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
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
  free_tab(temp2);
  my_printf(2, "%s %d\n", ERROR_PARSING, line);
  return (1);
}

t_node		*parse_image(t_node *file, t_image *image, int *line)
{
  t_root	*fct_parser;
  t_node	*node;
  
  init_image(image);
  node = file->next;
  my_printf(1, "One image found at line %d\n", *line);
  my_printf(1, "\tStart parsing image:\n");
  if ((fct_parser = init_image_function()) == NULL)
    return (NULL);
  while (my_strcmp(node->data, END_PARSING) != 0)
    {
      if (parse_image2(node->data, image, fct_parser, *line))
	return (NULL);
      *line += 1;
      node = node->next;
    }
  list_delete_all(fct_parser);
  my_printf(1, "Parsing image done\n");
  return (node);
}
