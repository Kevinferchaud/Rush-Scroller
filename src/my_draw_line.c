/*
** my_draw_line.c for emacs in /home/kevin.ferchaud/wireframe/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Dec 10 17:08:43 2016 ferchaud kevin
** Last update Sun Apr  2 19:14:30 2017 ferchaud kevin
*/

#include "my.h"

void            draw_linex(t_my_framebuffer *buffer, sfVector2i from, \
			   sfVector2i to, sfColor color)
{
  int           x;
  int           y;
  float         a;
  sfVector2i    swit;

  if (from.x > to.x)
    {
      swit = from;
      from = to;
      to = swit;
    }
  a = (float)(to.y - from.y) / (to.x - from.x);
  x = from.x;
  while (x != to.x)
    {
      y = (x - from.x) * a + from.y;
      my_put_pixel(buffer, x, y, color);
      x++;
    }
}

void            draw_liney(t_my_framebuffer *buffer, sfVector2i from, \
			   sfVector2i to, sfColor color)
{
  float         x;
  float         y;
  float         a;
  sfVector2i    swit;

  if (from.y > to.y)
    {
      swit = from;
      from = to;
      to = swit;
    }
  a = (float)(to.x - from.x) / (to.y - from.y);
  y = from.y;
  while (y != to.y)
    {
      x = (y - from.y) * a + from.x;
      my_put_pixel(buffer, x, y, color);
      y++;
    }
}

void    my_draw_line(t_my_framebuffer *buffer, sfVector2i from, \
		     sfVector2i to, sfColor color)
{
  float a;

  if ((from.x == to.x) &&
      (from.y == to.y))
    my_put_pixel(buffer, from.x, from.y, color);
  if (from.x > to.x)
    a = (float)(from.y - to.y) / (from.x - to.x);
  else
    a = (float)(to.y - from.y) / (to.x - from.x);
  if (a >= -1 && a <= 1)
    draw_linex(buffer, from, to, color);
  else
    draw_liney(buffer, from, to, color);
}
