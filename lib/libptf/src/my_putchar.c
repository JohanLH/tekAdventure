/*
** my_putchar.c for minishell in /home/johan/Documents/Shell/PSU_2016_minishell2
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri Apr  7 12:07:59 2017 johan
** Last update Fri Apr  7 12:08:01 2017 johan
*/

#include "unistd.h"

void	my_putchar(int st, char c)
{
  write(st, &c, 1);
}
