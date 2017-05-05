/*
** my_str_to_wordtab.c for mysh in /home/johan/Documents/Rendu/PSU_2016_minishell1
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat Jan 21 11:48:30 2017 johan
** Last update Mon Mar 20 12:34:52 2017 johan
*/

#include <stdlib.h>

int	count_word(char *str, char sep)
{
  int	i;
  int	cmp;

  i = 0;
  cmp = 0;
  while (str[i])
    {
      if (str[i] == sep && i != 0 && str[i - 1] != sep)
	cmp++;
      i++;
    }
  return (cmp + 1);
}

char	*write_word(char *str, int *i, char sep, char *dest)
{
  int	j;

  j = 0;
  while (str[*i] != sep && str[*i])
    {
      dest[j++] = str[*i];
      *i += 1;
    }
  dest[j] = 0;
  return (dest);
}

int	size_word(char *str, int i, char sep)
{
  int	cmp;

  cmp = 0;
  while (str[i] != sep && str[i])
    {
      cmp++;
      i++;
    }
  return (cmp);
}

char	**create_tab(char *str, char **dest, char sep)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] != sep)
	{
	  if ((dest[j] =
	       malloc(sizeof(char) * size_word(str, i, sep) + 1)) == NULL)
	    return (NULL);
	  dest[j] = write_word(str, &i, sep, dest[j]);
	  j++;
	}
      if (str[i] != 0)
	i++;
    }
  dest[j] = '\0';
  return (dest);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  char	**dest;

  if ((dest = malloc(sizeof(char *) * (count_word(str, sep) + 1))) == NULL)
    return (NULL);
  if ((dest = create_tab(str, dest, sep)) == NULL)
    return (NULL);
  return (dest);
}
