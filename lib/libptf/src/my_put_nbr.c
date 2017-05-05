/*
** my_put_nbr.c for minishell in /home/johan/Documents/Shell/PSU_2016_minishell2
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri Apr  7 12:08:11 2017 johan
** Last update Fri Apr  7 12:08:13 2017 johan
*/

#include "printf.h"

int     my_put_nbr(int st, int nb)
{
  if (nb < 0)
    {
      nb *= -1;
      my_putchar(st, '-');
    }
  if (nb >= 10)
    my_put_nbr(st, nb / 10);
  my_putchar(st, nb % 10 + 48);
  return (0);
}
