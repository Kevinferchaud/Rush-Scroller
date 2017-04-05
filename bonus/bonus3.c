/*
** bonus3.c for emacs in /home/kevin.ferchaud/scroller/bonus
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Apr  2 21:58:16 2017 ferchaud kevin
** Last update Sun Apr  2 22:40:58 2017 ferchaud kevin
*/

#include "my.h"

t_my_framebuffer        *refreshbuf(t_my_framebuffer *b)
{
  int                   i;
  sfUint8               *apixels;

  i = -1;
  while (++i < b->width * b->height * 4)
    b->pixels[i] = 0;
  return (b);
}

int             changenum(int num)
{
  if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
    num = 0;
  if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
    num = 1;
  if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
    num = 2;
  if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
    num = 3;
  if (sfKeyboard_isKeyPressed(sfKeyT) == sfTrue)
    num = 4;
  return (num);
}

void            imageslider(t_my_framebuffer *b, sfTexture *t, int h)
{
  sfImage       *img;
  int           x;
  int           y;
  sfColor       col;

  img = sfImage_createFromFile("sujet/voiture.jpg");
  y = -1;
  while (++y < WINDOW_HEIGHT)
    {
      x = -1;
      while (++x < WINDOW_WIDTH)
	{
	  if (y < WINDOW_HEIGHT - h)
	    col = sfImage_getPixel(img, x, WINDOW_HEIGHT - 1 - h);
	  else
	    col = sfImage_getPixel(img, x, y);
	  my_put_pixel(b, x, y, col);
	}
    }
  sfTexture_updateFromPixels(t, b->pixels, b->width, b->height, 0, 0);
}

void            checkboard(t_my_framebuffer *b, sfTexture *t)
{
  sfImage       *img;
  int           x;
  int           y;
  sfColor       col;

  img = sfImage_createFromFile("sujet/voiture.jpg");
  y = -1;
  while (++y < WINDOW_HEIGHT)
    {
      x = -1;
      while (++x < WINDOW_WIDTH)
	{
	  col = sfImage_getPixel(img, x, y);
	  if ((y % 50 < 25 && x % 50 < 25) ||
	      (y % 50 > 25 && x % 50 > 25))
	    {
	      col.r = 255 - col.r;
	      col.g = 255 - col.g;
	      col.b = 255 - col.b;
	    }
	  my_put_pixel(b, x, y, col);
	}
    }
  sfTexture_updateFromPixels(t, b->pixels, b->width, b->height, 0, 0);
}
