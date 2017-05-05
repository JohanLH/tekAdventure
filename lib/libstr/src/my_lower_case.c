/*
** my_lower_case.c for libstr in /home/johan/Thing/tekadvanture
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 18:19:30 2017 johan
** Last update Wed May  3 18:20:48 2017 johan
*/

char	*my_lower_case(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] -= 32;
      i++;
    }
}
