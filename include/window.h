/*
** window.h for window in /home/johan/Thing/tekAdventure
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Thu May 11 16:33:45 2017 johan
** Last update Mon May 29 12:55:43 2017 johan
*/

#ifndef WINDOW_H_
# define WINDOW_H_

#include "parsing.h"

# define WIDTH 1280
# define HEIGHT 720
# define WINDOW_NAME "tekAventure"

# define RIGHT 152
# define LEFT 304
# define TOP 0
# define BOTTOM 228
# define BOTTOM_RIGHT 379
# define BOTTOM_LEFT 529
# define TOP_RIGHT 79
# define TOP_LEFT 458

# define CLICK "click"
# define LOAD "load"
# define DELETE "delete"
# define INVENTORY "inventory"

# define MICRO_TIME 100000
# define INTERVAL_OBJ 3000000
# define INVENTORY_SIZE 50

typedef struct		s_click
{
  sfVector2i		start;
  sfVector2i		end;
  t_node		*obj;
}			t_click;

typedef struct		s_window
{
  sfRenderWindow	*window;
  sfEvent		event;
  sfWindow		*window_event;
  sfMouseButton		mouse;
  sfVector2i		mouse_pos;
  sfMusic		*music;
  sfMusic		*music_menu;
  t_game		*game;
  t_node		*cursor;
  t_root		*click;
  t_root		*path;
  t_root		*inventory;
  t_root		*all_map;
  t_root		*menu;
  int			print_menu;
  int			move;
  sfTime		time;
  sfClock		*clock;
}			t_window;

t_root			*find_rect_to_click(t_root *);

t_node			*change_sprite_cursor(t_obj *, int, t_node *, int);

int			init_window(char *, t_window *, int);
int			action_window(t_window *);
int			render_sprite_anim(t_image *);
int			move_player(t_window *);
int			check_node(t_window *);
int			reload_time(t_image *, sfClock *, int, sfTime *);
int			menu_loop(t_window *);

void			loop_window(t_window *);
void			action_object(t_window *, t_node *);
void			free_window(t_window *);
void			move_cursor(t_window *, t_node **, t_node **);
void			check_inventory_door(t_window *);
void			check_inventory_object(t_window *);

#endif /* !WINDOW_H_ */
