/*
** list_error.c for liblist in /home/johan/Thing/liblist/src
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May  2 14:23:48 2017 johan
** Last update Tue May  2 15:04:33 2017 johan
*/

#include <unistd.h>
#include "list.h"

static int	liblist_strlen(char *str)
{
  int		cmp;

  cmp = 0;
  while (str[cmp])
    {
      cmp++;
    }
  return (cmp);
}

int	list_print_error(char *error, int value)
{
  if (write(2, error, liblist_strlen(error)) == -1)
    return (WRITE_ERROR_VALUE);
  return (value);
}
