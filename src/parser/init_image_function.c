/*
** init_image_function.c for parser in /home/johan/Thing/tekadvanture/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 16:22:17 2017 johan
** Last update Thu May 25 13:15:45 2017 johan
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

static t_parser	*init_parser2(char *cmd, int (*parser_function2)
			     (t_anim *, char *, int))
{
  t_parser	*parser;

  if ((parser = malloc(sizeof(*parser))) == NULL)
    return (NULL);
  if ((parser->cmd = my_strdup(cmd)) == NULL)
    return (NULL);
  parser->parser_function2 = parser_function2;
  return (parser);
}

static void	free_ptr_function(void *ptr)
{
  t_parser	*image;

  image = (t_parser*)ptr;
  free(image->cmd);
  free(ptr);
}

t_root		*init_anim_function()
{
  t_root	*root;
  t_parser	*parser;

  if ((root = list_init(&free_ptr_function)) == NULL)
    return (NULL);
  if ((parser = init_parser2(ACTION_TYPE, &load_type)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_LOAD, &load_action_load)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_ACTION, &load_action)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_NAME, &load_action_name)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_VISIBILITY, &load_action_visibility)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_TIME, &load_action_time)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_LOCK, &load_action_lock)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_UNLOCK, &load_action_unlock)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_NODE, &load_action_node)) == NULL
      || list_prepend(root, parser))
      return (NULL);
  return (root);

}

t_root		*init_image_function()
{
  t_root	*root;
  t_parser	*parser;

  if ((root = list_init(&free_ptr_function)) == NULL)
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
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_MAX_DIMENSION, &load_max_dimension)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_INCRE_DIM, &load_incre_dim)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_START, &load_start_img)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser(IMAGE_INTERVAL, &load_interval)) == NULL
      || list_prepend(root, parser))
    return (NULL);
  return (root);
}
