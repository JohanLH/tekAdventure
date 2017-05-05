/*
** main.c for tekadvanture in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 18:09:59 2017 johan
** Last update Fri May  5 15:48:42 2017 johan
*/

#include <unistd.h>
#include <fcntl.h>
#include "parsing.h"
#include "my_string.h"
#include "get_next_line.h"
#include "printf.h"
#include "list.h"
#include "graph.h"

void	print_list(void *line)
{
  char	*str;

  str = (char*)line;
  my_printf(1, "%s\n", str);
}

int		main(int ac, char **av)
{
  t_root	*root;
  t_node	*node;
  t_image	image;
  t_map		map;
  int		line;
  
  if (!(root = parse_file(av[1])))
    return (84);
  //list_for_each(root, &print_list);
  node = root->first;
  line = 1;
  while (node)
    {
      if (!my_strcmp(node->data, IMAGE_PARSING))
	{
	  if (!(node = parse_image(node, &image, &line)))
	    return (84);
	}
      else if (!my_strcmp(node->data, GRAPH_PARSING))
	{
	  if (!(node = parse_graph(node, &line, &map)))
	    return (84);
	}
      line++;
      node = node->next;
    }
  list_delete_all(map.graph);
  list_delete_all(root);
  return (0);
}
