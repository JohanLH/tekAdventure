/*
** my_strncmp.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 13:03:49 2017 johan
** Last update Mon Apr 10 13:04:23 2017 johan
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n)
    i++;
  return (s1[i] - s2[i]);
}
