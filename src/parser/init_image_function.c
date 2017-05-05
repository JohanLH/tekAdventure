/*
** init_image_function.c for parser in /home/johan/Thing/tekadvanture/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 16:22:17 2017 johan
** Last update Wed May  3 20:16:42 2017 johan
*/


#include "list.h"
#include "parsing.h"
#include "my_string.h"

static t_parser	*init_parser(char *cmd, int (*parser_function)
			     (t_image *, char *, int))
{
  t_parser	*parser;

  if ((parser = malloc(sizeof(*parser))) == NULL)
    return (NULL);
  if ((parser->cmd = my_strdup(cmd)) == NULL)
    return (NULL);
  parser->parser_function = parser_function;
  return (parser);
}

static void	free_image_function(void *ptr)
{
  t_parser	*image;

  image = (t_parser*)ptr;
  free(image->cmd);
  free(ptr);
}

t_root		*init_image_function()
{
  t_root	*root;
  t_parser	*parser;
  
  if ((root = list_init(&free_image_function)) == NULL)
    return (NULL);
  if ((parser = init_parser(IMAGE_NAME, &load_image)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_POS, &load_position)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_SCALE, &load_scale)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_INCRE_SCALE, &load_incre_scale)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_MUSIC, &load_music)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_DIMENSION, &load_dimension)) == NULL
      || list_prepend(root, parser))
    return (NULL);
  return (root);
}
