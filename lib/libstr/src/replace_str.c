/*
** replace_str.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 13:04:45 2017 johan
** Last update Mon Apr 10 13:05:12 2017 johan
*/

char    *replace_str(char *str, char find, char replace)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == find)
	str[i] = replace;
      i++;
    }
  return (str);
}
