/*
** loading_anim_function2.c for parser in /home/johan/Documents/MUL/tekadventure2/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May 24 14:18:54 2017 johan
** Last update Sun May 28 00:08:45 2017 johan
*/

#include "parsing.h"
#include "my_string.h"
#include "printf.h"

int	load_action_time(t_anim *anim, char *argu, int line)
{
  my_printf(2, "\t\t\t[Loading time]\n");
  if (parse_integer(argu, line, &anim->interval, 1))
    return (1);
  anim->time = sfSeconds(0);
  anim->clock = sfClock_create();
  return (0);
}

int     load_action_lock(t_anim *anim, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading lock]\n");
  if (!my_strcmp(argu, INTERACTION_ON))
    {
      anim->lock = 1;
    }
  else if (!my_strcmp(argu, INTERACTION_OFF))
    {
      anim->lock = 0;
    }
  else
    return (error_parsing(line));
  return (0);
}

int	load_action_unlock(t_anim *anim, char *argu, int line)
{
  my_printf(2, "\t\t\t[Loading unlock]\n");
  if (anim->unlock || (anim->unlock = my_strdup(argu)) == NULL)
    return (error_parsing(line));
  return (0);
}

int     load_action_node(t_anim *anim, char *argu, int line)
{
  char  **tab = NULL;

  my_printf(1, "\t\t\t\t[Loading node]\n");
  if (anim->node ||
      (tab = my_str_to_wordtab(argu, SEPARATOR_DATA)) == NULL)
    return (error_parsing(line));
  anim->node = tab;
  return (0);
}
