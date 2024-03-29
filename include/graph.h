/*
** graph.h for tekAdventure in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 12:46:52 2017 johan
** Last update Mon May 15 12:23:40 2017 johan
*/

#ifndef GRAPH_H_
# define GRAPH_H_

#include "list.h"

typedef struct	s_vector3i
{
  int		x;
  int		y;
  int		z;
}		t_vector3i;

typedef struct	s_path
{
  t_node	*node;
}		t_path;

typedef struct	s_room
{
  char		*name;
  t_vector3i	coor;
  t_root	*link;
  t_node	*prev;
  int		weigth;
  int		visited;
}		t_room;

typedef	struct	s_link
{
  t_node	*room;
  char		*name;
  int		dist;
}		t_link;

t_root		*path_finding(t_root *, t_node *, t_node *);

t_node		*find_elem_graph(t_root *, char *);
t_node		*find_elem_graph_coor(t_root *, int, int);

int		add_node_graph(t_root *, char **, char *);
int		add_data_graph(t_root *, char *, char *);
int		my_abs(int);

void		graph_free_data(void *);
void		graph_free_room(void *);

#endif /* !GRAPH_H_ */
