/*
* parsing.h for tekadvanture in /home/johan/Thing/liblist
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 16:53:56 2017 johan
** Last update Thu May 11 20:05:00 2017 johan
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

# define ERROR_PARSING "Error while parsing file at line"

# define IMAGE_NAME "name"
# define IMAGE_POS "position"
# define IMAGE_SCALE "scale"
# define IMAGE_INCRE_SCALE "incre-scale"
# define IMAGE_MUSIC "music"
# define IMAGE_DIMENSION "dimension"

# define ACTION_TYPE "type"
# define ACTION_INTERACTION "interaction"

# define INTERACTION_ON "on"
# define INTERACTION_OFF "off"

# define CURSOR "cursor"

typedef struct	s_image
{
  sfSprite	*sprite;
  sfTexture	*texture;
  sfIntRect	rect;
  sfVector2f	pos;
  sfVector2f	scale;
  sfMusic	*music;
  sfVector2f	incre_scale;
}		t_image;

typedef struct	s_parser
{
  char		*cmd;
  int		(*parser_function) (t_image *, char *, int);
}		t_parser;

typedef struct	s_anim
{
  char		*type;
  int		interaction;
  t_image	*image;
  int		is_img;
  int		is_type;
}		t_anim;

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
  t_node	*graph_end;
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
  t_map		map;
  t_player	player;
  t_root	*object;
  int		is_map;
  int		is_player;
}		t_game;

t_root		*init_image_function();
t_root		*parse_file(char *);

t_node		*parse_image(t_node *, t_image *, int *);
t_node		*parse_graph(t_node *, int *, t_map *);
t_node		*parse_map(t_map *, t_node *, int *);
t_node		*parse_animation(t_node *, int *, t_anim *);
t_node		*parse_obj(t_node *, int *, t_obj *);
t_node		*parse_player(t_node *, int *, t_player *);
t_node		*find_cursor(t_root *);

t_game		*parse_list(t_root *);

int		load_image(t_image *, char *, int);
int		load_position(t_image *, char *, int);
int		load_scale(t_image *, char *, int);
int		load_music(t_image *, char *, int);
int		load_dimension(t_image *, char *, int);
int		load_incre_scale(t_image *, char *, int);

void		free_parsing(t_game *);
void		free_image(t_image *);

#endif /* !PARSING_H_ */
