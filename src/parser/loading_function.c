/*
** loading_function.c for parser in /home/johan/Thing/tekadvanture/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 14:31:33 2017 johan
** Last update Tue May  9 18:06:32 2017 johan
*/

#include "printf.h"
#include "my_string.h"
#include "parsing.h"

int	load_image(t_image *image, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading image]\n");
  if ((image->texture = sfTexture_createFromFile(argu, NULL)) == NULL)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  image->sprite = sfSprite_create();
  sfSprite_setTexture(image->sprite, image->texture, sfTrue);
  return (0);
}

int	load_position(t_image *image, char *argu, int line)
{
  char	**temp;
  int	error;

  error = 1;
  my_printf(1, "\t\t\t[Loading position]\n");
  if ((temp = my_str_to_wordtab(argu, ',')) == NULL)
    return (1);
  if (my_strlen_wordtab(temp) != 2)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  if ((image->pos.x = my_atoi(temp[0], &error)) < 0
      || (image->pos.y = my_atoi(temp[1], &error)) < 0 || error < 0)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  free_tab(temp);
  return (0);
}

int	load_scale(t_image *image, char *argu, int line)
{
  int	error;

  error = 1;
  my_printf(1, "\t\t\t[Loading scale]\n");
  if ((image->scale = my_get_float(argu, &error)) <= 0 && error < 0)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  return (0);
}

int	load_music(t_image *image, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading sound]\n");
  if ((image->music = sfMusic_createFromFile(argu)) == NULL)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  return (0);
}

int	load_dimension(t_image *image, char *argu, int line)
{
  char	**temp;
  int	error;

  error = 1;
  my_printf(1, "\t\t\t[Loading dimension]\n");
  if ((temp = my_str_to_wordtab(argu, ',')) == NULL)
    return (1);
  if (my_strlen_wordtab(temp) != 2)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  if ((image->rect.width = my_atoi(temp[0], &error)) < 0
      || (image->rect.height = my_atoi(temp[1], &error)) < 0 || error < 0)
    {
      my_printf(2, "%s %d\n", ERROR_PARSING, line);
      return (1);
    }
  return (0);
}
