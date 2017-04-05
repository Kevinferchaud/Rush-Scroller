/*
** bonus2.c for emacs in /home/kevin.ferchaud/scroller/bonus
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Apr  2 21:56:43 2017 ferchaud kevin
** Last update Sun Apr  2 21:58:03 2017 ferchaud kevin
*/

#include "my.h"

int             mycolor(int x, int y)
{
  int           col;

  col = (int)(128.0 + (128.0 * sin(x / 16.0)) +
	      128.0 + (128.0 * sin(y / 32.0)) +
	                    128.0 +
	      (128.0 * sin(sqrt((double)((x - WINDOW_WIDTH / 2.0)
					 * (x - WINDOW_WIDTH / 2.0) +
					 (y - WINDOW_HEIGHT / 2.0)
					 * (y - WINDOW_HEIGHT / 2.0)))
			   / 8.0)) +
	      128.0 + (128.0 * sin(sqrt((double)(x * x + y * y)) / 8.0))) / 4;
  return (col);
}

void            plasma(t_my_framebuffer *b, sfTexture *t)
{
  int           x;
  int           y;
  int           col;
  sfColor       color;

  y = -1;
  while (++y < b->height)
    {
      x = -1;
      while (++x < b->width)
	{
	  col = mycolor(x, y);
	  color = set_palette(col, col, col, 255);
	  my_put_pixel(b, x, y, color);
	}
    }
  sfTexture_updateFromPixels(t, b->pixels, b->width, b->height, 0, 0);
}

sfVector2i      sendpos(int x, int y)
{
  sfVector2i    val;

  val.x = x;
  val.y = y;
  return (val);
}

void            print_starfield(t_my_framebuffer *b, sfVector2i val1,
				sfVector2i val2)
{
  int           valx;
  int           valy;
  int           x;
  int           y;

  x = val1.x;
  y = val1.y;
  valx = val2.x;
  valy = val2.y;
  my_draw_line(b, sendpos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
	       sendpos(x - valx % WINDOW_WIDTH, y - valy % WINDOW_HEIGHT),
	       sfWhite);
  my_draw_line(b, sendpos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
	       sendpos(x + valx % WINDOW_WIDTH, y - valy % WINDOW_HEIGHT),
	       sfWhite);
  my_draw_line(b, sendpos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
	       sendpos(x - valx % WINDOW_WIDTH, y + valy % WINDOW_HEIGHT),
	       sfWhite);
  my_draw_line(b, sendpos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
	       sendpos(x + valx % WINDOW_WIDTH, y + valy % WINDOW_HEIGHT),
	       sfWhite);
}

void            starfield(t_my_framebuffer *b, sfTexture *t)
{
  int           x;
  int           y;
  static int    valx;
  static int    valy;

  y = -1;
  valx ++;
  valy ++;
  while (++y != WINDOW_HEIGHT)
    {
      x = -1;
      while (++x != WINDOW_WIDTH)
	{
	  if (x % 50 == 0 && y % 50 == 0)
	    print_starfield(b, sendpos(x, y), sendpos(valx, valy));
	}
    }
  sfTexture_updateFromPixels(t, b->pixels, b->width, b->height, 0, 0);
  if (valx % 50 == 0)
    valx = 0;
  if (valy % 50 == 0)
    valy = 0;
}
