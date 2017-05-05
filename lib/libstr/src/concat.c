/*
** concat.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 12:59:18 2017 johan
** Last update Wed Apr 19 13:35:44 2017 johan
*/

#include "my_string.h"

char    *concat(char *str1, char *str2, int f1, int f2)
{
  char  *res;
  int   i;
  int   j;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1)))
      == NULL)
    return (NULL);
  if (str1 != NULL)
    while (str1[i])
      res[i++] = str1[j++];
  j = 0;
  if (str2 != NULL)
    while (str2[j])
      res[i++] = str2[j++];
  res[i] = 0;
  if (f1 == 1 && str1 != NULL)
    free(str1);
  if (f2 == 1 && str2 != NULL)
    free(str2);
  return (res);
}
