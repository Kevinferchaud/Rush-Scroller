/*
** bonus.c for emacs in /home/kevin.ferchaud/scroller/bonus
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Apr  2 13:13:03 2017 ferchaud kevin
** Last update Sun Apr  2 23:00:07 2017 ferchaud kevin
*/

#include "my.h"

int		check_num2(int num, t_my_framebuffer *b, sfTexture *t, int h)
{
  if (num == 3)
    {
      b = refreshbuf(b);
      checkboard(b, t);
      h = 0;
    }
  if (num == 2)
    {
      b = refreshbuf(b);
      imageslider(b, t, h);
      if (h < WINDOW_HEIGHT)
	h++;
    }
  return (h);
}

void		check_num(int num, t_my_framebuffer *b, sfTexture *t,
			  sfRenderWindow *window)
{
  static int	h;

  if (num == 0)
    {
      b = refreshbuf(b);
      plasma(b, t);
      h = 0;
    }
  if (num == 1)
    {
      b = refreshbuf(b);
      starfield(b, t);
      h = 0;
    }
  if (num == 4)
    {
      b = refreshbuf(b);
      wolf(b, t, window);
      h = 0;
    }
  h = check_num2(num, b, t, h);
}

void		mainbonus(sfRenderWindow *window, sfSprite *sprite,
			  t_my_framebuffer *b, sfTexture *t)
{
  int		num;

  num = 0;
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(window);
      num = changenum(num);
      check_num(num, b, t, window);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
}

void			bonus()
{
  sfRenderWindow        *window;
  sfTexture             *t;
  sfSprite              *sprite;
  t_my_framebuffer      *b;

  window = create_window("Window");
  sprite = sfSprite_create();
  t = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
  sfSprite_setTexture(sprite, t, sfTrue);
  b = my_framebuffer_create(WINDOW_WIDTH, WINDOW_HEIGHT);
  mainbonus(window, sprite, b, t);
}
