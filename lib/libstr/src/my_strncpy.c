/*
** my_strncpy.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 13:02:46 2017 johan
** Last update Mon Apr 10 13:03:06 2017 johan
*/

char    *my_strncpy(char *dest, char *src, int n)
{
  int   i;

  i = 0;
  while (src[i] && i < n)
    dest[i++] = src[i++];
  dest[i] = 0;
  return (dest);
}
