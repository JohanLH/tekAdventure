/*
** my_get_float.c for libstr in /home/johan/Thing/tekadvanture/lib/libstr/src
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Fri May  5 12:17:27 2017 johan
** Last update Fri May  5 12:35:13 2017 johan
*/

#include "my_string.h"

static float	add_floating(float result, char *str, int *error)
{
  int		i;
  float		result2;
  
  i = my_strlen(str) - 1;
  result2 = 0;
  while (i != 0 && str[i] != '.')
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  *error = -1;
	  return (result + result2);
	}
      result2 = (result2 + (str[i] - 48)) / 10;
      i--;
    }
  return (result + result2);
}

float	my_get_float(char *str, int *error)
{
  float	result;
  int	i;
  int	neg;

  neg = 1;
  i = 0;
  result = 0;
  if (str[0] == '-')
    {
      neg = -1;
      i = 1;
    }
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
	{
	  *error = -1;
	  return (result * neg);
	}
      if (str[i] == '.')
	return (add_floating(result, str, error) * neg);
      result = result * 10 + str[i] - 48;
      i++;
    }
  return (result * neg);
}
