/*
** error_parsing.c for parser in /home/johan/Documents/MUL/tekadventure2
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May 23 00:28:23 2017 johan
** Last update Tue May 23 00:29:17 2017 johan
*/

#include "parsing.h"
#include "printf.h"

int	error_parsing(int line)
{
  my_printf(2, "%s %d\n", ERROR_PARSING, line);
  return (1);
}
