/*
** init_out_function.c for parser in /home/johan/Documents/MUL/tekadventure2
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May 23 00:14:21 2017 johan
** Last update Tue May 23 00:53:36 2017 johan
*/

#include <stdlib.h>
#include "list.h"
#include "parsing.h"
#include "my_string.h"

static void	free_out_function(void *ptr)
{
  t_parser	*out;

  out = (t_parser *)ptr;
  free(out->cmd);
  free(ptr);
}

static t_parser	*init_parser3(char *cmd, int (*parser_function3)
			      (t_out *, char *, int))
{
  t_parser	*parser;

  if ((parser = malloc(sizeof(*parser))) == NULL
      || (parser->cmd = my_strdup(cmd)) == NULL)
    return (NULL);
  parser->parser_function3 = parser_function3;
  return (parser);
}

t_root		*init_out_function()
{
  t_root	*root;
  t_parser	*parser;

  if ((root = list_init(&free_out_function)) == NULL)
    return (NULL);
  if ((parser = init_parser3(OUT_START, &load_out_start)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser3(OUT_END, &load_out_end)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser3(OUT_NAME, &load_out_name)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser3(OUT_LOCK, &load_out_lock)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser3(OUT_OBJECT, &load_out_object)) == NULL
      || list_prepend(root, parser) ||
      (parser = init_parser3(OUT_NODE, &load_out_node)) == NULL
      || list_prepend(root, parser))
    return (NULL);
  return (root);
}
