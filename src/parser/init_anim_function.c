/*
** init_anim_function.c for parser in /home/johan/Documents/MUL/tekadventure2/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sun May 28 00:11:39 2017 johan
** Last update Sun May 28 00:40:51 2017 johan
*/

#include "parsing.h"
#include "my_string.h"

static t_parser *init_parser2(char *cmd, int (*parser_function2)
			      (t_anim *, char *, int))
{
  t_parser      *parser;

  if ((parser = malloc(sizeof(*parser))) == NULL)
    return (NULL);
  if ((parser->cmd = my_strdup(cmd)) == NULL)
    return (NULL);
  parser->parser_function2 = parser_function2;
  return (parser);
}

static void     free_anim_function(void *ptr)
{
  t_parser      *image;

  image = (t_parser*)ptr;
  free(image->cmd);
  free(ptr);
}

static int	init_anim_function2(t_root *root)
{
  t_parser	*parser;

  if ((parser = init_parser2(ACTION_UNLOCK, &load_action_unlock)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_NODE, &load_action_node)) == NULL
      || list_prepend(root, parser))
    return (1);
  return (0);
}

t_root          *init_anim_function()
{
  t_root        *root;
  t_parser      *parser;

  if ((root = list_init(&free_anim_function)) == NULL)
    return (NULL);
  if ((parser = init_parser2(ACTION_TYPE, &load_type)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_LOAD, &load_action_load)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_ACTION, &load_action)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_NAME, &load_action_name)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_VISIBILITY,
			     &load_action_visibility)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_TIME, &load_action_time)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser2(ACTION_LOCK, &load_action_lock)) == NULL
      || list_prepend(root, parser)
      || init_anim_function2(root))
    return (NULL);
  return (root);
}

