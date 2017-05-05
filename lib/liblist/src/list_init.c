/*
** list_init.c for liblist in /home/johan/Thing/liblist/src
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 14:54:18 2017 johan
** Last update Tue May  2 15:06:20 2017 johan
*/

#include <stdlib.h>
#include "list.h"

t_root		*list_init(free_function my_free)
{
  t_root	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    {
      list_print_error(MALLOC_ERROR, 84);
      return (NULL);
    }
  root->my_free = my_free;
  root->nbr_elem = 0;
  root->first = NULL;
  root->last = NULL;
  return (root);
}
