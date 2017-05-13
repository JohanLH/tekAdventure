/*
** loading_anim_function.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 13 17:46:18 2017 johan
** Last update Sat May 13 18:53:23 2017 johan
*/

#include <stdlib.h>
#include "printf.h"
#include "my_string.h"
#include "parsing.h"

int	load_interaction(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading interaction]\n");
  if (!my_strcmp(argu, INTERACTION_ON))
    {
      anim->interaction = 1;
    }
  else if (!my_strcmp(argu, INTERACTION_OFF))
    {
      anim->interaction = 0;
    }
  else
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  return (0);
}

int	load_type(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading type]\n");
  if (anim->is_type)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  if ((anim->type = my_strdup(argu)) == NULL)
    return (1);
  anim->is_type = 1;
  return (0);
}

int	load_action(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading action]\n");
  if (anim->is_action)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  if ((anim->action = my_strdup(argu)) == NULL)
    return (1);
  anim->is_action = 1;
  return (0);
}
