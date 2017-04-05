/*
** scroller2.c for emacs in /home/kevin.ferchaud/scroller/scrollingtxt
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Apr  2 23:17:25 2017 ferchaud kevin
** Last update Sun Apr  2 23:18:25 2017 ferchaud kevin
*/

#include "my.h"

sfVector2f              triang(sfVector2f pos,
			       sfRenderWindow *window,
			       t_my_framebuffer **b, sfSprite *sprite)
{
  static int            status;

  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  sfSprite_setPosition (sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  pos.x++;
  if (pos.x == (*b)->width - WIDTH_IMG)
    pos.x = 0;
  if (pos.y == (*b)->height * 3 / 4)
    status = 1;
  if (pos.y == (*b)->height / 4)
    status = 0;
  if (status == 0)
    pos.y++;
  else
    pos.y--;
  return (pos);
}

sfVector2f              rotate_sprite(sfVector2f pos, sfSprite *sprite,
				      int dir)
{
  static float          rot;

  if (dir == 0)
    pos.x++;
  if (dir == 1)
    {
      pos.y++;
      pos.x--;
      sfSprite_setRotation(sprite, rot++);
    }
  if (dir == 2)
    {
      pos.y--;
      pos.x--;
      sfSprite_setRotation(sprite, rot--);
    }
  return (pos);
}

sfVector2f              scrolling(sfVector2f pos,
				  sfRenderWindow *window,
				  t_my_framebuffer **b, sfSprite *sprite)
{
  static int            dir;

  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  sfSprite_setPosition (sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  if (pos.x == 0 || pos.y == (*b)->height - HEIGHT_IMG ||
      (pos.y == 0 && pos.x != (*b)->width - WIDTH_IMG))
    dir = 0;
  if (pos.y == 0 && pos.x == (*b)->width - WIDTH_IMG)
    dir = 1;
  if (pos.y == (*b)->height - HEIGHT_IMG &&
      pos.x == (*b)->width - WIDTH_IMG)
    dir = 2;
  pos = rotate_sprite(pos, sprite, dir);
  return (pos);
}

sfVector2f              parall1(sfVector2f pos, sfRenderWindow *window,
				t_my_framebuffer **b, sfSprite *sprite)
{
  static int            time;

  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  sfSprite_setPosition (sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  time++;
  if (time % 10 == 0)
    pos.x++;
  if (pos.x == (*b)->width)
    pos.x = -(*b)->width;
  if (time == 6000000)
    time = 0;
  return (pos);
}

sfVector2f              parall2(sfVector2f pos, sfRenderWindow *window,
				t_my_framebuffer **b, sfSprite *sprite)
{
  static int            time;

  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  sfSprite_setPosition (sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  time++;
  if (time % 50 == 0)
    pos.x++;
  if (pos.x == (*b)->width)
    pos.x = -(*b)->width;
  if (time == 6000000)
    time = 0;
  return (pos);
}
