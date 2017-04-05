/*
** param_window.c for emacs in /home/kevin.ferchaud/scroller/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Apr  1 11:22:37 2017 ferchaud kevin
** Last update Sun Apr  2 15:27:26 2017 ferchaud kevin
*/

#include "my.h"

sfRenderWindow          *create_window(char *name)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = WINDOW_WIDTH;
  mode.height = WINDOW_HEIGHT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

t_my_framebuffer         *my_framebuffer_create(int awidth, int aheight)
{
  int                    i;
  sfUint8                *apixels;
  t_my_framebuffer       *res;

  res = malloc(sizeof(*res));
  apixels = malloc(awidth * aheight * 4 * sizeof(*apixels));
  if (apixels == NULL)
    return (NULL);
  i = -1;
  while (++i < awidth * aheight * 4)
    apixels[i] = 0;
  res->pixels = apixels;
  res->width = awidth;
  res->height = aheight;
  return (res);
}

sfColor         *set_color(int r, int g, int b, int a)
{
  sfColor       *color;

  color = malloc(sizeof(*color));
  if (color == NULL)
    return (NULL);
  color->r = r;
  color->g = g;
  color->b = b;
  color->a = a;
  return (color);
}

sfColor         set_palette(int r, int g, int b, int a)
{
  sfColor       color;

  color.r = (int)(128.0 + 128 * sin(3.1415 * r / 32.0));
  color.g = (int)(128.0 + 128 * sin(3.1415 * g / 64.0));
  color.b = (int)(128.0 + 128 * sin(3.1415 * b / 128.0));
  color.a = a;
  return (color);
}
