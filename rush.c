/*
** rush.c for emacs in /home/kevin.ferchaud/scroller
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Apr  2 12:32:35 2017 ferchaud kevin
** Last update Sun Apr  2 13:19:19 2017 ferchaud kevin
*/

#include "my.h"

int			return_value(sfTexture *t0, sfTexture *t1,
				     sfSprite *sprite, int val)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    {
      sfSprite_setTexture(sprite, t0, sfTrue);
      val = 0;
    }
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    {
      sfSprite_setTexture(sprite, t1, sfTrue);
      val = 1;
    }
  return (val);
}

void			use_value(int val, sfRenderWindow *window)
{
  if (val == 0)
    mandatory();
  if (val == 1)
    bonus();
  if (val == 2)
    sfRenderWindow_close(window);
}

void                    mainless(sfRenderWindow *window, sfSprite *sprite,
				 t_my_framebuffer *b)
{
  int			val;
  sfTexture             *t0;
  sfTexture             *t1;
  sfTexture             *t2;

  t0 = sfTexture_createFromFile("sujet/menu/menumandatory.jpg", NULL);
  t1 = sfTexture_createFromFile("sujet/menu/menubonus.jpg", NULL);
  t2 = sfTexture_createFromFile("sujet/menu/menuquitter.jpg", NULL);
  sfSprite_setTexture(sprite, t0, sfTrue);
  val = 0;
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      val = return_value(t0, t1, sprite, val);
      if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
	{
	  sfSprite_setTexture(sprite, t2, sfTrue);
	  val = 2;
	}
      if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	use_value(val, window);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
}

int	main(int ac, char **av)
{
  sfRenderWindow        *window;
  sfTexture             *t;
  sfSprite              *sprite;
  t_my_framebuffer      *b;

  window = create_window("Window");
  sprite = sfSprite_create();
  b = my_framebuffer_create(WINDOW_WIDTH, WINDOW_HEIGHT);
  mainless(window, sprite, b);
  return (0);
}
