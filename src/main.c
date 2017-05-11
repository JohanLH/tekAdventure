/*
** main.c for tekadvanture in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 18:09:59 2017 johan
** Last update Thu May 11 16:14:32 2017 johan
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
  t_game	*game;
  t_node	*node;
  t_room	*room;
  
  if (!(root = parse_file(av[1])))
    return (84);
  if ((game = parse_list(root)) == NULL)
    return (84);
  node = find_elem_graph_coor(game->map.graph, 224, 241);
  room = (t_room *)node->data;
  my_printf(1, "x = %d y = %d\n", room->coor.x, room->coor.y);
  list_delete_all(root);
  list_delete_all(game->map.graph);
  return (0);
}
