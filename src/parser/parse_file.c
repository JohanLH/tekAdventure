/*
** parse_file.c for parser in /home/johan/Thing/tekadvanture/src/parser
** 
** Made by johan
** Login   <johan@epitech.net>
** 
** Started on  Wed May  3 20:01:23 2017 johan
** Last update Thu May  4 23:57:07 2017 johan
*/

#include <fcntl.h>
#include "my_string.h"
#include "get_next_line.h"
#include "list.h"

static int	add_line_from_file(t_root *root, char *line)
{
  char		**temp = NULL;
  char		**temp2 = NULL;

  if ((temp = my_str_to_wordtab(line, '#')) == NULL)
    return (84);
  if (temp[0][0] != '\0')
    {
      if ((temp2 = my_str_to_wordtab(temp[0], ' ')) == NULL)
	return (84);
      if (temp2[0] != '\0' && list_append(root, my_strdup(temp2[0])) == 84)
	return (84);
      free_tab(temp2);
    }
  free_tab(temp);
  return (0);
}

t_root		*parse_file(char *file)
{
  int		fd;
  t_root	*root = NULL;
  char		*temp = NULL;

  if ((fd = open(file, O_RDONLY)) < 0 ||
      (root = list_init(NULL)) == NULL)
    return (NULL);
  while ((temp = get_next_line(fd)))
    {
      temp = replace_str(temp, '\t', ' ');
      if (temp[0] != '\0' && add_line_from_file(root, temp) == 84)
	return (NULL);
      free(temp);
    }
  return (root);
}
