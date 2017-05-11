/*
** main.c for tekadvanture in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 18:09:59 2017 johan
** Last update Thu May 11 18:28:38 2017 johan
*/

#include <unistd.h>
#include <fcntl.h>
#include "parsing.h"
#include "my_string.h"
#include "get_next_line.h"
#include "printf.h"
#include "window.h"
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
  t_room	*room;
  t_window	window;
  
  if (!(root = parse_file(av[1])))
    return (84);
  if ((window.game = parse_list(root)) == NULL)
    return (84);
  if (init_window(WINDOW_NAME, &window))
    return (84);
  loop_window(&window);
  list_delete_all(root);
  free_parsing(window.game);
  return (0);
}
