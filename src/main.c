/*
** main.c for tekadvanture in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 18:09:59 2017 johan
** Last update Sun May 28 00:08:12 2017 johan
*/

#include "window.h"
#include "graph.h"

int		main(int ac, char **av)
{
  t_window	window;

  if (ac != 2 || (window.all_map = parse_all_map(av[1])) == NULL)
    return (84);
  window.game = (t_game *)window.all_map->first->data;
  if ((window.menu = parse_menu("conf/menu.conf")) == NULL
      || init_window(WINDOW_NAME, &window, 1))
    return (84);
  loop_window(&window);
  list_delete_all(window.click);
  list_delete_all(window.all_map);
  list_delete_all(window.inventory);
  list_delete_all(window.menu);
  return (0);
}
