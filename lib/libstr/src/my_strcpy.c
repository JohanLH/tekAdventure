/*
** my_strcpy.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 13:01:41 2017 johan
** Last update Mon Apr 10 13:02:23 2017 johan
*/

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    dest[i++] = src[i++];
  dest[i] = 0;
  return (dest);
}
