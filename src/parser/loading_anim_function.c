/*
** loading_anim_function.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 13 17:46:18 2017 johan
** Last update Thu May 25 14:08:08 2017 johan
*/

#include <stdlib.h>
#include "printf.h"
#include "my_string.h"
#include "parsing.h"

int	load_action_load(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading load]\n");
  if (!my_strcmp(argu, INTERACTION_ON))
    {
      anim->load = 1;
    }
  else if (!my_strcmp(argu, INTERACTION_OFF))
    {
      anim->load = 0;
    }
  else
    return (error_parsing(line));
  return (0);
}

int	load_type(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading type]\n");
  if (anim->is_type)
    return (error_parsing(line));
  if ((anim->type = my_strdup(argu)) == NULL)
    return (1);
  anim->is_type = 1;
  return (0);
}

int	load_action(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading action]\n");
  if (anim->is_action || (anim->action = my_strdup(argu)) == NULL)
    return (error_parsing(line));
  anim->is_action = 1;
  return (0);
}

int	load_action_name(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading action]\n");
  if (anim->name || (anim->name = my_strdup(argu)) == NULL)
    return (error_parsing(line));
  return (0);
}

int	load_action_visibility(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading visibility]\n");
  if (!my_strcmp(argu, INTERACTION_ON))
    {
      anim->visibility = 1;
    }
  else if (!my_strcmp(argu, INTERACTION_OFF))
    {
      anim->visibility = 0;
    }
  else
    return (error_parsing(line));
  return (0);
}
