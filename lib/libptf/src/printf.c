/*
** main.c for printf in /home/johan/Things/Projet/printf
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed Mar  1 16:14:18 2017 johan
** Last update Tue Apr  4 23:29:54 2017 johan
*/

#include "printf.h"

void	print_argu(int st, char c, va_list ap)
{
  int	nb;
  char	*str;
  char	cara;

  if (c == 'd')
    my_put_nbr(st, va_arg(ap, int));
  else if (c == 's')
    {
      if ((str = va_arg(ap, char *)) == NULL)
	my_putstr(st, "(null)");
      else
	my_putstr(st, str);
    }
  else if (c == 'c')
    my_putchar(st, va_arg(ap, int));
  else if (c == '%')
    my_putchar(st, '%');
}

int		my_printf(int st, char *str, ...)
{
  va_list	ap;
  int		i;

  if (str == NULL)
    return (84);
  va_start(ap, str);
  i = 0;
  while (str[i])
    {
      if (str[i] == '%')
	print_argu(st, str[++i], ap);
      else
	my_putchar(st, str[i]);
      i++;
    }
  va_end(ap);
  return (0);
}
