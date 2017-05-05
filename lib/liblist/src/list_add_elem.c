/*
** list_add_elem.c for liblist in /home/johan/Thing/liblist/src
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 14:54:42 2017 johan
** Last update Thu May  4 23:23:58 2017 johan
*/

#include <stdlib.h>
#include "list.h"

int		list_prepend(t_root *root, void *element)
{
  t_node	*node;

  if ((node = malloc(sizeof(*node))) == NULL
      || element == NULL)
    return (list_print_error(MALLOC_ERROR, ERROR_VALUE));
  node->data = element;
  root->nbr_elem += 1;
  node->prev = NULL;
  if (root->first)
    {
      node->next = root->first;
      root->first->prev = node;
    }
  else
    {
      node->next = NULL;
      root->last = node;
    }
  root->first = node;
  return (0);
}

int		list_append(t_root *root, void *element)
{
  t_node	*node;

  if ((node = malloc(sizeof(*node))) == NULL
      || element == NULL)
    return (list_print_error(MALLOC_ERROR, ERROR_VALUE));
  node->data = element;
  root->nbr_elem += 1;
  node->next = NULL;
  if (root->last)
    {
      node->prev = root->last;
      root->last->next = node;
    }
  else
    {
      node->prev = NULL;
      root->first = node;
    }
  root->last = node;
  return (0);
}
