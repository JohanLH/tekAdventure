/*
** my_strdup.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 13:00:05 2017 johan
** Last update Mon Apr 10 13:19:45 2017 johan
*/

#include "my_string.h"

char    *my_strdup(char *src)
{
  char  *str;
  int   i;

  if ((str = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (src[i])
    str[i] = src[i++];
  str[i] = 0;
  return (str);
}
