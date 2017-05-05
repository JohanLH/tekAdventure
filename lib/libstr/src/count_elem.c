/*
** count_elem.c for my_string in /home/johan/Documents/CPE/lemin/lib/my_string
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Apr 10 13:05:37 2017 johan
** Last update Mon Apr 10 13:05:51 2017 johan
*/

int     count_elem(char *str, char elem)
{
  int   i;
  int   cmp;

  i = 0;
  cmp = 0;
  while (str[i])
    {
      if (str[i] == elem)
	cmp++;
      i++;
    }
  return (cmp);
}
