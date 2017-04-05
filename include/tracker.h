/*
** tracker.h for emacs in /home/kevin.ferchaud/scroller
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Apr  2 22:21:22 2017 ferchaud kevin
** Last update Sun Apr  2 22:21:23 2017 ferchaud kevin
*/

#ifndef  SCROLLER_H_
# define SCROLLER_H

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/System/InputStream.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Export.h>
#include <SFML/Window.h>

#include <stddef.h>

struct  music
{
  struct timespec       beg;
  sfSound               *sound;
  char                  *fp;
  int                   i;
  int                   *dur;
  int                   *fq;
  int                   b;
  int                   nb;
};

int			*get_duration(char *fp, int nb);
int			*get_frequency(char *fp, int j);
int			*get_int_arr(char *str, int *arr, int *nb);
int			get_nb_node(char *fp, int j);
int			get_nb_line(char *fp, char *str, int i);
void			my_vibrato(float *j, int *b);
struct music		*tracker(int *nb, int *b, float *j, struct music *mus);
char			*get_rand_fp(int nb);
int			my_strlen(char *str);
char			*my_concat(char *str1, char *str2);
char			*get_next_line(int fd);
void			get_keyboard(struct music *mus, int i, float *j, int *b);
int			get_nb_sounds(char *fp);
int			my_strcomp2(char *str1, char *str2);
void			set_pause(struct music *mus, int i);
void			my_slide(struct music *mus, int i, float *j);
void			destroy_sound(struct music *mus, int nb);
struct music		*my_init_mus(char *fp, int *nb);

#endif
