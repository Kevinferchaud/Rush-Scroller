/*
** main.c for carte in /home/jimmy/carte
**
** Made by jimmy
** Login   <jimmy@epitech.net>
**
** Started on  Sat Apr  1 14:01:32 2017 jimmy
** Last update Sun Apr  2 23:16:11 2017 ferchaud kevin
*/

#include "my.h"

sfVector2i	newpos(int i, int y)
{
  sfVector2i	new;

  new.x = i;
  new.y = y;
  return (new);
}

sfVector2i	ret_iy(int i, int y)
{
  sfVector2i	ret;

  i = i + 100;
  if (i == 500 && y < 300)
    {
      i = 0;
      y = y + 100;
    }
  else
    if (i == 400 && y == 200)
      {
	i = 0;
	y = y + 100;
      }
    else
      if (i == 200 && y == 300)
	{
	  y = y + 100;
	  i = 0;
	}
  ret = newpos(i, y);
  return (ret);
}

int		init(t_ev *s)
{
  int		i = 0;
  int		y = 0;
  int		z = 0;
  sfIntRect	*rect;
  sfVector2i	rec;

  rect = malloc(sizeof(*rect));
  s->mode.width = SCREEN_WIDTH;
  s->mode.height = SCREEN_HEIGHT;
  s->s = malloc(sizeof(*s) * 7);
  rect->width = 100;
  rect->height = 100;
  while (z < 16)
    {
      rect->left = i;
      rect->top = y;
      s->t = sfTexture_createFromFile("wolf/wolf.png", rect);
      s->s[z] = malloc(sizeof(*s->s) * i * y);
      s->s[z] = sfSprite_create();
      sfSprite_setTexture(s->s[z], s->t, sfTrue);
      z++;
      rec = ret_iy(i, y);
      i = rec.x;
      y = rec.y;
    }
}

void	next(t_ev *s, t_my_framebuffer *b, sfTexture *t,
	     sfRenderWindow *window)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, s->s[i], NULL);
      sfRenderWindow_display(window);
      i++;
      usleep(150000);
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(window);
    }
}

void			wolf(t_my_framebuffer *b, sfTexture *t,
			     sfRenderWindow *window)
{
  t_ev			*s;

  s = malloc(sizeof*s);
  init(s);
  next(s, b, t, window);
}
