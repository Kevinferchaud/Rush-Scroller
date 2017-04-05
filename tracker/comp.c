/*
** comp.c for comp_scroller in /home/Akeno85/delivery/test_scroller
** 
** Made by Bastien Guesdon
** Login   <Akeno85@epitech.net>
** 
** Started on  Sun Apr  2 11:10:36 2017 Bastien Guesdon
** Last update Sun Apr  2 18:06:32 2017 Bastien Guesdon
*/

#include "../include/tracker.h"

void	destroy_sound(struct music *mus, int nb)
{
  int	i;

  i = -1;
  while (++i != nb)
    sfSound_destroy(mus[i].sound);
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

int	my_strcomp2(char *str1, char *str2)
{
  int	j;

  j = 0;
  while (str1[j] == str2[j] && str1[j] && str2[j])
    j++;
  if (str2[j] == 0)
    return (1);
  else
    return (0);
}

char	*my_concat(char *str1, char *str2)
{
  char	*str;
  int	i;
  int	j;

  j = -1;
  i = -1;
  str = malloc(sizeof(char) * my_strlen(str1) + my_strlen(str2) + 1);
  str[my_strlen(str1) + my_strlen(str2)] = '\0';
  while (str1[++i])
    str[i] = str1[i];
  while (str2[++j])
    str[i++] = str2[j];
  return (str);
}
