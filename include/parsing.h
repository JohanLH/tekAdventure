/*
** parsing.h for tekadvanture in /home/johan/Thing/liblist
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 16:53:56 2017 johan
** Last update Fri May  5 21:01:55 2017 johan
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
# define ERROR_PARSING "Error parsing file at line"

# define IMAGE_NAME "name"
# define IMAGE_POS "position"
# define IMAGE_SCALE "scale"
# define IMAGE_INCRE_SCALE "incre-scale"
# define IMAGE_MUSIC "music"
# define IMAGE_DIMENSION "dimension"

typedef struct	s_image
{
  sfSprite	*sprite;
  sfTexture	*texture;
  sfIntRect	rect;
  sfVector2f	pos;
  float		scale;
  sfMusic	*music;
  sfVector2f	incre_scale;
}		t_image;

typedef struct	s_parser
{
  char		*cmd;
  int		(*parser_function) (t_image *, char *, int);
}		t_parser;

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
  t_image	player;
  t_image	animation;
}		t_player;

typedef struct	s_png
{
  t_image	image;
  t_image	text;
}		t_png;

typedef	struct	s_game
{
  t_map		map;
  t_player	player;
  t_root	*object;
  t_root	*png;
}		t_game;

t_root		*init_image_function();
t_root		*parse_file(char *);

t_node		*parse_image(t_node *, t_image *, int *);
t_node		*parse_graph(t_node *, int *, t_map *);
t_node		*parse_map(t_map *, t_node *, int *);

int		load_image(t_image *, char *, int);
int		load_position(t_image *, char *, int);
int		load_scale(t_image *, char *, int);
int		load_music(t_image *, char *, int);
int		load_dimension(t_image *, char *, int);
int		load_incre_scale(t_image *, char *, int);

#endif /* !PARSING_H_ */
