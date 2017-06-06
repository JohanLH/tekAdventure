/*
** test.c for get_next_line in /home/johan/Documents/Novembre-Decembre/CPE_2017_getnextline
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Jan  2 17:55:23 2017 johan
** Last update Sun May 28 00:44:41 2017 johan
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	my_strlen10(char *str, int value)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  if (value == 1)
    {
      while (str[i] != '\0' && str[i] != '\n')
	i++;
      return (i);
    }
  while (str[i] != '\0')
    i += 1;
  return (i);
}

static char	*concat10(char *str1, char *str2)
{
  char		*res;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) * (my_strlen10(str1, 0) +
				    my_strlen10(str2, 1) + 1))) == NULL)
    return (NULL);
  if (str1 != NULL)
    {
      while (str1[i])
	res[i++] = str1[j++];
      free(str1);
    }
  j = 0;
  if (str2 != NULL)
    while (str2[j] != '\n' && str2[j] != '\0')
      res[i++] = str2[j++];
  res[i] = '\0';
  return (res);
}

static char	*modif_buff(char *buff, int i, char *str, int value)
{
  int		j;

  j = 0;
  if (value == 1)
    {
      while (buff[i])
	buff[j++] = buff[i++];
      buff[j] = 0;
      return (buff);
    }
  buff[0] = 0;
  if (str[0] == 0)
    {
      free(str);
      free(buff);
      return (NULL);
    }
  return (str);
}

static char	*init10(char *buff, char *str, const int fd)
{
  int		value;
  static int	fd2;

  if (fd2 != fd || buff == NULL)
    {
      fd2 = fd;
      if ((buff = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
	return (NULL);
      if ((value = read(fd, buff, READ_SIZE)) == -1)
	return (NULL);
      buff[value] = '\0';
    }
  return (buff);
}

char		*get_next_line(const int fd)
{
  int		i;
  static char	*buff;
  char		*str;
  int		value2;

  i = 0;
  if ((buff = init10(buff, str, fd)) == NULL)
    return (NULL);
  str = NULL;
  while (buff[i] != '\n')
    {
      if (buff[i] == '\0')
	{
	  str = concat10(str, buff);
	  if ((value2 = read(fd, buff, READ_SIZE)) == 0)
	    return (modif_buff(buff, i, str, 0));
	  buff[value2] = '\0';
	  i = -1;
	}
      i++;
    }
  if ((str = concat10(str, buff)) == NULL)
    return (NULL);
  buff = modif_buff(buff, i + 1, str, 1);
  return (str);
}
