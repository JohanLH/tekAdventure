/*
** str_function.c for minishell in /home/johan/Documents/Rendu/PSU/PSU_2016_minishell2
**
** Made by johan
** Login   <johan@epitech.net>
**
** Started on  Mon Mar 20 14:23:09 2017 johan
** Last update Fri May  5 12:39:56 2017 johan
*/

#ifndef MY_STRING_H_
# define MY_STRING_H_

#include <stdio.h>
#include <stdlib.h>

float	my_get_float(char *, int *);

int	my_strcmp(char *, char *);
int	my_strlen(char *);
int	my_strncmp(char *, char *, int);
int	count_elem(char *, char);
int	only_str_char(char *, char);
int	my_strlen_wordtab(char **);
int	my_atoi(char *, int *);

char	*my_nstrcpy(char *, char *, int);
char	*my_strdup(char *);
char	*concat(char *, char *, int, int);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
char	*replace_str(char *, char, char);
char	*my_lower_case(char *);

char	**my_str_to_wordtab(char *, char);

void	free_tab(char **);

#endif /* !MY_STRING_H_ */
