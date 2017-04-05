/*
** tracker.c for tracker_scroller in /home/Akeno85/delivery/test_scroller
** 
** Made by Bastien Guesdon
** Login   <Akeno85@epitech.net>
** 
** Started on  Fri Mar 31 21:23:44 2017 Bastien Guesdon
** Last update Sun Apr  2 18:03:49 2017 Bastien Guesdon
*/

#include "../include/tracker.h"

char			*get_sound_name(char *fp, int nb)
{
  char			*ret;
  char			*str;
  int			i;
  int			ct;

  ct = open(fp, O_RDONLY);
  i = -1;
  ret = NULL;
  while (nb-- != 0)
    while ((str = get_next_line(ct)) && my_strcomp2(str, "[track") == 0);
  while ((str = get_next_line(ct)) && my_strcomp2(str, "sample=") == 0);
  ct = 0;
  if (str != NULL)
    {
      while (str[++i] != '\"');
      ct = i + 1;
      while (str[++i] != '\"');
      ret = malloc(sizeof(char) * (i - ct + 1));
      ret[i - ct] = '\0';
      ct--;
      i = -1;
      while (str[++ct] != '\"')
	ret[++i] = str[ct];
    }
  return (my_concat("sujet/modlike/", ret));
}

const sfSoundBuffer	*my_record()
{
  sfSoundBufferRecorder	*rec;

  rec = sfSoundBufferRecorder_create();
  sfSoundBufferRecorder_start(rec, 44100);
  usleep(1000);
  sfSoundBufferRecorder_stop(rec);
  return (sfSoundBufferRecorder_getBuffer(rec));
}

struct music		*my_init_mus(char *fp, int *nb)
{
  sfSound		*sound;
  struct music		*mus;
  int			i;

  i = -1;
  *nb = get_nb_sounds(fp);
  mus = malloc(sizeof(struct music) * *nb);
  while (++i != *nb)
    {
      mus[i].fp = get_sound_name(fp, i + 1);
      mus[i].dur = get_duration(fp, i + 1);
      mus[i].fq = get_frequency(fp, i + 1);
      mus[i].b = 1;
      mus[i].nb = get_nb_node(fp, i + 1);
      sound = sfSound_create();
      if (sfSoundBuffer_createFromFile(mus[i].fp) != NULL)
	sfSound_setBuffer(sound, sfSoundBuffer_createFromFile(mus[i].fp));
      else
	sfSound_setBuffer(sound, my_record());
      mus[i].sound = sound;
      mus[i].i = 0;
    }
  return (mus);
}

struct music		*tracker1(struct music *mus, int status, int i, int *nb)
{
  struct music	*new;

  if (status == 0)
    {
      if (mus[i].i == mus[i].nb)
	{
	  mus[i].i = 0;
	  new = my_init_mus(my_concat("sujet/modlike/", get_rand_fp(8)), nb);
	  mus = new;
	}
      sfSound_setPitch(mus[i].sound, mus[i].fq[mus[i].i] * 0.5 / 100);
      sfSound_play(mus[i].sound);
      clock_gettime(CLOCK_REALTIME, &mus[i].beg);
      mus[i].b = 0;
    }
  if (status == 1)
    {
      mus[i].b = 1;
      mus[i].i++;
      sfSound_stop(mus[i].sound);
    }
  return (mus);
}

struct music		*tracker(int *nb, int *b, float *j, struct music *mus)
{
  int			i;
  int			calc;
  int			calc2;
  struct timespec	end;

  i = -1;
  while (++i != *nb)
    {
      if (mus[i].b)
	mus = tracker1(mus, 0, i, nb);
      clock_gettime(CLOCK_REALTIME, &end);
      calc = (end.tv_nsec - mus[i].beg.tv_nsec) / 1000000;
      calc2 = (end.tv_sec - mus[i].beg.tv_sec) * 1000;
      if (calc + calc2 >= mus[i].dur[mus[i].i])
	mus = tracker1(mus, 1, i, nb);
      get_keyboard(mus, i, j, b);
      sfSound_setPitch(mus[i].sound, mus[i].fq[mus[i].i] * 0.005 + *j);
    }
  return (mus);
}
