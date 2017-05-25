/*
** loading_img_function.c for parser in /home/johan/Thing/tekAdventure/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Sat May 13 17:45:55 2017 johan
** Last update Fri May 19 20:41:25 2017 johan
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
  my_printf(1, "\t\t\t[Loading position]\n");
  if (parse_coor_float(argu, line, &image->pos, 1))
    return (1);
  return (0);
}

int	load_scale(t_image *image, char *argu, int line)
{
  my_printf(1, "\t\t\t[Loading scale]\n");
  if (parse_coor_float(argu, line, &image->scale, 1))
    return (1);
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

int		load_dimension(t_image *image, char *argu, int line)
{
  sfVector2i	tmp;

  my_printf(1, "\t\t\t[Loading dimension]\n");
  if (parse_coor_integer(argu, line, &tmp, 1))
    return (1);
  image->rect.width = tmp.x;
  image->rect.height = tmp.y;
  return (0);
}
