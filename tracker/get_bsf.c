/*
** get_bsf.c for get_bsf_scroller in /home/Akeno85/delivery/test_scroller
** 
** Made by Bastien Guesdon
** Login   <Akeno85@epitech.net>
** 
** Started on  Sat Apr  1 17:16:07 2017 Bastien Guesdon
** Last update Sun Apr  2 22:27:55 2017 ferchaud kevin
*/

#include "../include/tracker.h"

int     get_nb_line(char *fp, char *str, int i)
{
  int   fd;
  int   nb;
  char  *gnl;

  nb = 0;
  fd = open(fp, O_RDONLY);
  while (i--)
    while ((gnl = get_next_line(fd)) && my_strcomp2(gnl, "[track") == 0);
  while ((gnl = get_next_line(fd)) &&
	 my_strcomp2(gnl, str) == 0 && ++nb);
  return (nb + 1);
}

int     get_nb_node(char *fp, int j)
{
  int   eg;
  int   fd;
  int   nb;
  char  *str;
  int   i;

  eg = 0;
  nb = 0;
  fd = open(fp, O_RDONLY);
  while (j--)
    while ((str = get_next_line(fd)) &&
	   my_strcomp2(str, "[track") == 0);
  while ((str = get_next_line(fd)) && my_strcomp2(str, "sample=") == 0);
  while (eg < 2 && (str = get_next_line(fd)))
    {
      i = -1;
      while (str[++i] && eg < 2)
	{
	  if (str[i] == ',')
	    nb++;
	  if (str[i] == '=')
	    eg++;
	}
    }
  return (nb + 1);
}

int     *get_int_arr(char *str, int *arr, int *nb)
{
  int   i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == '\"' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
	  arr[++*nb] = 0;
	  while (str[++i] != '.' && str[i] != '\"' && str[i])
	    arr[*nb] = arr[*nb] * 10 + (str[i] - '0');
	}
    }
  return (arr);
}

int     *get_frequency(char *fp, int j)
{
  int   *fq;
  char  *str;
  int   fd;
  int   nb;
  int   i;

  nb = get_nb_line(fp, "frequency", j);
  fd = open(fp, O_RDONLY);
  fq = malloc(sizeof(int) * (get_nb_node(fp, j) + 1));
  fq[get_nb_node(fp, j)] = -1;
  while (j--)
    while ((str = get_next_line(fd)) && my_strcomp2(str, "[track") == 0);
  while (--nb && (str = get_next_line(fd)));
  nb = -1;
  while ((str = get_next_line(fd)) && my_strcomp2(str, "duration") == 0)
    fq = get_int_arr(str, fq, &nb);
  return (fq);
}

int     *get_duration(char *fp, int nb)
{
  int   *dur;
  char  *str;
  int   fd;
  int   i;
  int   j;

  j = get_nb_line(fp, "duration", nb);
  fd = open(fp, O_RDONLY);
  dur = malloc(sizeof(int) * (get_nb_node(fp, nb) + 1));
  dur[get_nb_node(fp, nb)] = -1;
  while (nb--)
    while ((str = get_next_line(fd)) && my_strcomp2(str, "[track") == 0);
  while (--j && (str = get_next_line(fd)));
  j = -1;
  while ((str = get_next_line(fd)) && my_strcomp2(str, "frequency") == 0)
    dur = get_int_arr(str, dur, &j);
  return (dur);
}
