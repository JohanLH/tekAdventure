/*
** main.c for tekadvanture in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 18:09:59 2017 johan
** Last update Tue May 23 00:54:03 2017 johan
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

/* static void	print_list(void *ptr) */
/* { */
/*   t_game		*out; */

/*   out = (t_game *)ptr; */
/*   printf("%s\n", out->name); */
/* } */

int		main(int ac, char **av)
{
  t_window	window;
  
  if (ac != 2 || (window.all_map = parse_all_map(av[1])) == NULL)
    return (84);
  window.game = (t_game *)window.all_map->first->data;
  if (init_window(WINDOW_NAME, &window, 1))
    return (84);
  //list_for_each(window.all_map, &print_list);
  loop_window(&window);
  list_delete_all(window.click);
  list_delete_all(window.all_map);
  return (0);
}
