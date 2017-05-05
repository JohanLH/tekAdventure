/*
** my_putstr.c for minishell in /home/johan/Documents/Shell/PSU_2016_minishell2
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri Apr  7 12:08:24 2017 johan
** Last update Fri Apr  7 12:08:25 2017 johan
*/

#include "printf.h"

int	my_putstr(int st, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(st, str[i]);
      i += 1;
    }
  return (0);
}
