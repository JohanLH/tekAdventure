/*
** list_delete.c for liblist.c in /home/johan/Thing/liblist/src
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 14:42:32 2017 johan
** Last update Sat May 13 19:15:57 2017 johan
*/

#include <stdlib.h>
#include "list.h"

void	list_delink_elem(t_root *root, t_node *node)
{
  if (root->first == node)
    root->first = node->next;
  if (root->last == node)
    root->last = node->prev;
  if (node->next)
    node->next->prev = node->prev;
  if (node->prev)
    node->prev->next = node->next;
}
void	list_delete_elem(t_root *root, t_node *node)
{
  list_delink_elem(root, node);
  if (root->my_free)
    root->my_free(node->data);
  else
    free(node->data);
  free(node);
  root->nbr_elem -= 1;
}

void		list_delete_all(t_root *root)
{
  t_node	*node;

  if (root != NULL)
    {
      while (root->first)
	{
	  node = root->first;
	  list_delete_elem(root, node);
	}
      free(root);
    }
}
