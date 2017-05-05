/*
** printf.h for printf in /home/johan/Things/Projet/printf
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed Mar  1 16:42:51 2017 johan
** Last update Wed Apr 12 17:17:42 2017 johan
*/

#ifndef PRINTF_H_
# define PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>

void	my_putchar(int, char);
int	my_putstr(int, char *);
int	my_put_nbr(int, int);
int	my_printf(int, char *, ...);

#endif /* !PRINTF_H_ */
