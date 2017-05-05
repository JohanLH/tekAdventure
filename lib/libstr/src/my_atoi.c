/*
** my_atoi.c for pushswap in /home/johan/Documents/Novembre-Decembre/CPE_2016_Pushswap
**
** Made by johan
** Login   <johan@epitech.net>
**
** Started on  Fri Nov 25 18:50:32 2016 johan
** Last update Fri Apr 28 23:13:24 2017 johan
*/

int	my_atoi(char *av, int *value)
{
  int	i;
  int	nb;
  int	minus;

  minus = 1;
  nb = 0;
  i = 0;
  *value = 0;
  if (av[0] == '-')
    {
      i += 1;
      minus = -1;
    }
  while (av[i])
    {
      if (av[i] == ' ' && av[i] < '0' || av[i] > '9')
	{
	  *value = 1;
	  return (nb * minus);
	}
      else if (av[i] != ' ')
	nb = nb * 10 + av[i] - 48;
      i += 1;
    }
  return (nb * minus);
}
