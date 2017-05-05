/*
** free_tab.c for minishell2 in /home/johan/Documents/Rendu/PSU/PSU_2016_minishell2/src
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Mon Mar 20 12:32:40 2017 johan
** Last update Tue Apr  4 23:12:16 2017 johan
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
