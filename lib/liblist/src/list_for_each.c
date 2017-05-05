/*
** list_for_each.c for liblist in /home/johan/Thing/liblist/src
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 14:42:13 2017 johan
** Last update Tue May  2 14:42:19 2017 johan
*/

#include "list.h"

void		list_for_each(t_root *root, list_iterator iterator)
{
  t_node	*node;

  node = root->first;
  while (node)
    {
      iterator(node->data);
      node = node->next;
    }
}
