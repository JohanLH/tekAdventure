/*
** window.h for window in /home/johan/Thing/tekAdventure
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:33:45 2017 johan
** Last update Fri May 12 01:11:12 2017 johan
*/

#ifndef WINDOW_H_
# define WINDOW_H_

#include "parsing.h"

# define WIDTH 1280
# define HEIGHT 780
# define WINDOW_NAME "tekAventure"

typedef struct		s_window
{
  sfRenderWindow	*window;
  sfEvent		event;
  sfWindow		*window_event;
  sfMouseButton		mouse;
  sfVector2i		mouse_pos;
  t_game		*game;
  t_node		*cursor;
}			t_window;

int			init_window(char *, t_window *);
int			loop_window(t_window *);
int			action_window(t_window *);

void			free_window(t_window *);

#endif /* !WINDOW_H_ */
