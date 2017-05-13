/*
** list.h for liblist in /home/johan/Thing/liblist/include
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 12:21:23 2017 johan
** Last update Sat May 13 19:16:12 2017 johan
*/

#ifndef LIST_H_
# define LIST_H_

# define MALLOC_ERROR "Malloc error\n"
# define ERROR_VALUE 84
# define WRITE_ERROR_VALUE -256

typedef void (*free_function) (void *);

typedef void (*list_iterator) (void *);

typedef struct	s_node
{
  struct s_node	*next;
  struct s_node *prev;
  void		*data;
}		t_node;

typedef struct	s_root
{
  t_node	*first;
  t_node	*last;
  int		nbr_elem;
  free_function	my_free;
}		t_root;

t_root	*list_init(free_function);

int	list_print_error(char *, int);
int	list_prepend(t_root *, void *);
int	list_append(t_root *, void *);

void	list_for_each(t_root *, list_iterator);
void	list_delete_all(t_root *);
void	list_delete_elem(t_root *, t_node *);
void	list_delink_elem(t_root *, t_node *);

#endif /* !LIST_H_ */
