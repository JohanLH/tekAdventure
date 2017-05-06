/*
** main.c for tekadvanture in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 18:09:59 2017 johan
** Last update Fri May  5 21:05:30 2017 johan
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
  t_map		map;
  int		line;
  
  if (!(root = parse_file(av[1])))
    return (84);
  node = root->first;
  line = 1;
  while (node)
    {
      if (!my_strcmp(node->data, MAP_PARSING))
	{
	  if (!(node = parse_map(&map, node, &line)))
	    return (84);
	}
      line++;
      node = node->next;
    }
  list_delete_all(map.graph);
  list_delete_all(root);
  return (0);
}
