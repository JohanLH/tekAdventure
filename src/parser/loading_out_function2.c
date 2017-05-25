/*
** loading_out_function2.c for parser in /home/johan/Documents/MUL/tekadventure2/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Tue May 23 00:31:40 2017 johan
** Last update Tue May 23 01:07:44 2017 johan
*/

#include <stdlib.h>
#include "parsing.h"
#include "my_string.h"
#include "printf.h"

int	load_out_object(t_out *out, char *argu, int line)
{
  my_printf(1, "\t\t\t\t[Loading object]\n");
  if (out->object || (out->object = my_strdup(argu)) == NULL)
    return (error_parsing(line));
  return (0);
}
