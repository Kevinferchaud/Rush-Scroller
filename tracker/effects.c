/*
** effects.c for effects_scroller in /home/Akeno85/delivery/test_scroller
** 
** Made by Bastien Guesdon
** Login   <Akeno85@epitech.net>
** 
** Started on  Sat Apr  1 17:21:13 2017 Bastien Guesdon
** Last update Sun Apr  2 16:14:41 2017 Bastien Guesdon
*/

#include "../include/tracker.h"

void                    my_vibrato(float *j, int *b)
{
  if (*j <= -0.1)
    *b = 1;
  if (*j >= 0.1)
    *b = 0;
  if (*b == 1)
    *j += 0.025;
  if (*b == 0)
    *j -= 0.025;
}

void                    my_slide(struct music *mus, int i, float *j)
{
  if (mus[i].i < mus[i].nb - 1)
    {
      if (mus[i].fq[mus[i].i] * 0.005 + *j < mus[i].fq[mus[i].i + 1] * 0.005)
	*j += 0.001;
      if (mus[i].fq[mus[i].i] * 0.005 + *j > mus[i].fq[mus[i].i + 1] * 0.005)
	*j -= 0.001;
    }
}

void                    get_keyboard(struct music *mus, int i, float *j, int *b)
{
  float                 volup;
  float                 voldwn;

  volup = sfSound_getVolume(mus[i].sound) + 0.1;
  voldwn = sfSound_getVolume(mus[i].sound) - 0.1;
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    sfSound_setVolume(mus[i].sound, volup);
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    sfSound_setVolume(mus[i].sound, voldwn);
  if (sfKeyboard_isKeyPressed(sfKeyV) == sfTrue)
    my_vibrato(j, b);
  if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
    my_slide(mus, i, j);
}

int                     get_nb_sounds(char *fp)
{
  int                   fd;
  char                  *str;
  int                   nb;

  nb = 0;
  fd = open(fp, O_RDONLY);
  while ((str = get_next_line(fd)))
    {
      if (my_strcomp2(str, "[track") != 0)
	nb++;
    }
  close(fd);
  return (nb);
}

char            *get_rand_fp(int nb)
{
  DIR           *dir;
  struct dirent *rd;
  int           rnd;

  rnd = 1 + (rand() % (nb - 1));
  dir = opendir("sujet/modlike");
  while (rnd--)
    {
      rd = readdir(dir);
      while (rd->d_name[0] == '.' || rd->d_name[my_strlen(rd->d_name) - 1] == 'g')
	rd = readdir(dir);
    }
  return (rd->d_name);
}
