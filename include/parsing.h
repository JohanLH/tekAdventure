/*
** parsing.h for tekadvanture in /home/johan/Thing/liblist
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 16:53:56 2017 johan
** Last update Sat May 27 19:57:51 2017 johan
*/

#ifndef PARSING_H_
# define PARSING_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "list.h"

# define END_PARSING "[END]"
# define IMAGE_PARSING "[IMAGE]"
# define MAP_PARSING "[MAP]"
# define GRAPH_PARSING "[GRAPH]"
# define ROOM_PARSING "[ROOM]"
# define LINK_PARSING "[LINK]"
# define OUT_PARSING "[OUT]"
# define PLAYER_PARSING "[PLAYER]"
# define OBJ_PARSING "[OBJET]"
# define SPAWN_PARSING "[SPAWN]"
# define ANIM_PARSING "[ANIMATION]"
# define ACTION_PARSING "[ACTION]"
# define FILE_PARSING "[FILE]"

# define ERROR_PARSING "Error while parsing file at line"

# define IMAGE_NAME "name"
# define IMAGE_POS "position"
# define IMAGE_SCALE "scale"
# define IMAGE_INCRE_SCALE "incre-scale"
# define IMAGE_MUSIC "music"
# define IMAGE_DIMENSION "dimension"
# define IMAGE_MAX_DIMENSION "max"
# define IMAGE_INCRE_DIM "incre-dim"
# define IMAGE_START "start"
# define IMAGE_INTERVAL "interval"

# define ACTION_TYPE "type"
# define ACTION_INTERACTION "interaction"
# define ACTION_ACTION "action"
# define ACTION_NAME "name"
# define ACTION_VISIBILITY "visibility"
# define ACTION_TIME "time"
# define ACTION_LOAD "load"
# define ACTION_LOCK "lock"
# define ACTION_NODE "node"
# define ACTION_UNLOCK "unlock"

# define OUT_START "start"
# define OUT_END "end"
# define OUT_NAME "name"
# define OUT_LOCK "lock"
# define OUT_OBJECT "object"
# define OUT_NODE "node"

# define FILE_NAME "name"
# define FILE_PATH "path"

# define INTERACTION_ON "on"
# define INTERACTION_OFF "off"

# define SEPARATOR_DATA ','
# define SEPARATOR_NAME ':'

# define CURSOR "cursor"

typedef struct	s_image
{
  sfSprite	*sprite;
  sfTexture	*texture;
  sfIntRect	rect;
  sfIntRect	rect_dim;
  sfVector2f	pos;
  sfVector2f	scale;
  sfVector2i	incre_dim;
  sfMusic	*music;
  sfVector2f	incre_scale;
  sfClock	*clock;
  sfTime	time;
  int		interval;
  int		max;
  int		status;
}		t_image;

typedef struct	s_anim
{
  t_image	*image;
  char		**node;
  char		*type;
  char		*name;
  char		*action;
  int		load;
  int		lock;
  char		*unlock;
  sfClock	*clock;
  sfTime	time;
  int		interval;
  int		load_image;
  int		visibility;
  int		is_img;
  int		is_type;
  int		is_action;
}		t_anim;

typedef struct	s_out
{
  sfVector2i	start;
  sfVector2i	end;
  char		*name;
  char		*object;
  char		**all_node;
  int		lock;
  int		is_end;
  int		is_start;
}		t_out;

typedef struct	s_parser
{
  char		*cmd;
  int		(*parser_function) (t_image *, char *, int);
  int		(*parser_function2) (t_anim *, char *, int);
  int		(*parser_function3) (t_out *, char *, int);
}		t_parser;

typedef struct	s_obj
{
  t_anim	anim;
  t_image	image;
  int		is_img;
  int		is_anim;
}		t_obj;

typedef struct	s_map
{
  t_image	image;
  t_root	*out;
  t_root	*graph;
  int		is_image;
  int		is_graph;
}		t_map;

typedef	struct	s_player
{
  t_image	image;
  t_node	*position;
  char		*node;
  int		is_image;
  int		is_position;
}		t_player;

typedef	struct	s_game
{
  char		*name;
  t_map		map;
  t_player	player;
  t_root	*object;
  int		is_map;
  int		is_player;
  int		init;
}		t_game;

t_root		*init_image_function();
t_root		*init_anim_function();
t_root		*init_out_function();
t_root		*parse_file(char *);
t_root		*parse_all_map(char *);
t_root		*parse_menu(char *);

t_node		*parse_out(t_node *, int *, t_map *);
t_node		*parse_image(t_node *, t_image *, int *);
t_node		*parse_graph(t_node *, int *, t_map *);
t_node		*parse_map(t_map *, t_node *, int *);
t_node		*parse_animation(t_node *, int *, t_anim *);
t_node		*parse_obj(t_node *, int *, t_obj *);
t_node		*parse_player(t_node *, int *, t_player *);
t_node		*find_cursor(t_root *);

t_game		*parse_list(t_root *, char *);

int		parse_coor_integer(char *, int, sfVector2i *, int);
int		parse_coor_float(char *, int, sfVector2f *, int);
int		parse_integer(char *, int, int *, int);
int		parse_float(char *, int, float *, int);

int		load_image(t_image *, char *, int);
int		load_position(t_image *, char *, int);
int		load_scale(t_image *, char *, int);
int		load_music(t_image *, char *, int);
int		load_dimension(t_image *, char *, int);
int		load_incre_scale(t_image *, char *, int);
int		load_max_dimension(t_image *, char *, int);
int		load_incre_dim(t_image *, char *, int);
int		load_start_img(t_image *, char *, int);
int		load_interval(t_image *, char *, int);

int		load_action_load(t_anim *, char *, int);
int		load_type(t_anim *, char *, int);
int		load_action(t_anim *, char *, int);
int		load_action_name(t_anim *, char *, int);
int		load_action_visibility(t_anim *, char *, int);
int		load_action_time(t_anim *, char *, int);
int		load_action_lock(t_anim *, char *, int);
int		load_action_unlock(t_anim *, char *, int);
int		load_action_node(t_anim *, char *, int);

int		load_out_object(t_out *, char *, int);
int		load_out_name(t_out *, char *, int);
int		load_out_start(t_out *, char *, int);
int		load_out_end(t_out *, char *, int);
int		load_out_lock(t_out *, char *, int);
int		load_out_node(t_out *, char *, int);

int		error_parsing(int);

void		free_parsing(void *);
void		free_image(t_image *);
void		free_graph_out(void *);

#endif /* !PARSING_H_ */
