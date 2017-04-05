/*
** get_next_line.c for emacs in /home/kevin.ferchaud/scroller
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Apr  2 22:25:00 2017 ferchaud kevin
** Last update Sun Apr  2 22:33:01 2017 ferchaud kevin
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	CHAR
{
  char		c;
  struct CHAR	*next;
} CHAR;

void		my_set_new(CHAR *stct, char c)
{
  CHAR		*new;

  new = malloc(sizeof(CHAR));
  while (stct->next)
    stct = stct->next;
  new->next = NULL;
  new->c = c;
  stct->next = new;
}

CHAR		*my_init_struct(char c)
{
  CHAR		*stct;

  stct = malloc(sizeof(CHAR));
  stct->c = c;
  stct->next = NULL;
  return (stct);
}

char		*convert_struct(CHAR *stct)
{
  int		i;
  CHAR		*new;
  char		*str;

  i = -1;
  new = stct;
  while (stct && ++i >= 0)
    stct = stct->next;
  str = malloc(sizeof(char) * (i + 2));
  str[i + 1] = '\0';
  i = -1;
  while (new && ++i >= 0)
    {
      str[i] = new->c;
      new = new->next;
    }
  return (str);
}

int	checkst(int st, int a)
{
  if (!a)
    st = 1;
  return (st);
}

char		*get_next_line(int fd)
{
  static int	st = 0;
  CHAR		*stct;
  char		buffer[1];
  int		a;

  if (st)
    {
      st = 0;
      return (NULL);
    }
  buffer[0] = 0;
  if (!(a = read(fd, buffer, 1)))
    st = 1;
  if (buffer[0] != '\n')
    stct = my_init_struct(buffer[0]);
  else
    return ("\0");
  while (buffer[0] != '\n' && a)
    {
      a = read(fd, buffer, 1);
      st = checkst(st, a);
      if (buffer[0] != '\n' && a)
	my_set_new(stct, buffer[0]);
    }
  return (convert_struct(stct));
}
