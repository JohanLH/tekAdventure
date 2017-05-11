/*
** window.h for window in /home/johan/Thing/tekAdventure
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:33:45 2017 johan
** Last update Thu May 11 19:19:16 2017 johan
*/

#ifndef WINDOW_H_
# define WINDOW_H_

#include "parsing.h"

# define WIDTH 980
# define HEIGHT 720
# define WINDOW_NAME "tekAventure"

typedef struct		s_window
{
  sfRenderWindow	*window;
  sfEvent		event;
  sfWindow		*window_event;
  sfMouseButton		mouse;
  sfVector2i		mouse_pos;
  t_game		*game;
}			t_window;

int			init_window(char *, t_window *);
int			loop_window(t_window *);
int			action_window(t_window *);

void			free_window(t_window *);

#endif /* !WINDOW_H_ */
