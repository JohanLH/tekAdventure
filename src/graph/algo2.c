/*
** algo2.c for algo2 in /home/jack/Documents/sem2/CPE/CPE_2016_Lemin/src
** 
** Made by Jack
** Login   <jacques.lemarchand@epitech.eu>
** 
** Started on  Tue Apr 18 13:48:53 2017 Jack
** Last update Sun Apr 30 19:39:27 2017 Jack
*/

#include <stdlib.h>
#include "list.h"
#include "graph.h"
#include "lemin.h"
#include "my_string.h"

int		is_arrived(t_list *path, t_ant ant)
{
  t_list	*temp;

  temp = path->next;
  while (temp->next != path && temp != NULL)
    temp = temp->next;
  if (temp == NULL)
    return (0);
  if (my_strcmp(temp->obj.name, ant.end->obj.name) == 0)
    return (1);
  return (0);
}
