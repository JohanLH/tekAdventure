/*
** main.c for tekadvanture in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 18:09:59 2017 johan
** Last update Sun May 14 18:16:49 2017 johan
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

static void	print_list(void *ptr)
{
  t_link	*link;
  t_room	*room;
  t_node	*node;
  t_node	*tmp;
  
  room = (t_room *)ptr;
  node = room->link->first;
  while (node)
    {
      link = (t_link *)node->data;
      my_printf(1, "Distance = %d\n", link->dist);
      node = node->next;
    }
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
  list_for_each(window.game->map.graph, &print_list);
  loop_window(&window);
  list_delete_all(root);
  free_parsing(window.game);
  return (0);
}
