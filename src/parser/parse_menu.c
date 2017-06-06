/*
** parse_menu.c for parser in /home/johan/Documents/MUL/tekadventure2/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 27 19:41:08 2017 johan
** Last update Sun May 28 00:04:18 2017 johan
*/

#include "parsing.h"
#include "my_string.h"

static void	free_menu(void *ptr)
{
  t_image	*image;

  image = (t_image *)ptr;
  free_image(image);
  free(image);
}

static t_node	*parse_menu_data(t_node *node, t_root *menu, int *line)
{
  t_image	*image;

  if ((image = malloc(sizeof(*image))) == NULL
      || (node = parse_image(node, image, line)) == NULL
      || list_append(menu, image))
    return (NULL);
  return (node);
}

t_root		*parse_menu(char *file)
{
  t_root	*all_file;
  t_root	*menu;
  t_node	*node;
  int		line;

  line = 0;
  if ((all_file = parse_file(file)) == NULL
      || (menu = list_init(&free_menu)) == NULL)
    return (NULL);
  node = all_file->first;
  while (node)
    {
      if (!my_strcmp(node->data, IMAGE_PARSING))
	{
	  if ((node = parse_menu_data(node, menu, &line)) == NULL)
	    return (NULL);
	}
      else
	return (NULL);
      line++;
      node = node->next;
    }
  list_delete_all(all_file);
  return (menu);
}
