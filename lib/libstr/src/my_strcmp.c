/*
** my_strcmp.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 13:00:41 2017 johan
** Last update Mon Apr 10 13:00:52 2017 johan
*/

#include <stdlib.h>

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[i] && s2[i] && (s1[i] == s2[i]))
    i++;
  return (s1[i] - s2[i]);
}
