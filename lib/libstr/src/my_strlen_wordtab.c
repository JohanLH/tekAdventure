/*
** my_strlen_wordtab.c for minishell in /home/johan/Documents/Rendu/PSU/PSU_2016_minishell2
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Mar 20 12:43:29 2017 johan
** Last update Mon Mar 20 12:44:04 2017 johan
*/

int	my_strlen_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
