/*
** my_strlen.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 13:01:09 2017 johan
** Last update Mon Apr 10 13:01:18 2017 johan
*/

#include <stdlib.h>

int     my_strlen(char *str)
{
  int   i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}
