/*
** my_put_pixel.c for emacs in /home/kevin.ferchaud/scroller/src
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Apr  1 11:24:08 2017 ferchaud kevin
** Last update Sat Apr  1 11:24:09 2017 ferchaud kevin
*/

#include "my.h"

void    my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color)
{
  if (x >= 0 && x <= buffer->width &&
      y >= 0 && y <= buffer->height)
    {
      buffer->pixels[(buffer->width * y + x) * 4] = color.r;
      buffer->pixels[(buffer->width * y + x) * 4 + 1] = color.g;
      buffer->pixels[(buffer->width * y + x) * 4 + 2] = color.b;
      buffer->pixels[(buffer->width * y + x) * 4 + 3] = color.a;
    }
}
