/*
** scroller3.c for emacs in /home/kevin.ferchaud/scroller/scrollingtxt
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Apr  2 23:18:45 2017 ferchaud kevin
** Last update Sun Apr  2 23:19:43 2017 ferchaud kevin
*/

#include "my.h"

sfVector2f              parall3(sfVector2f pos, sfRenderWindow *window,
				t_my_framebuffer **b, t_mysprite sp)
{
  static int            time;
  sfVector2f            pos2;

  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  sfSprite_setPosition(sp.sprite5, pos);
  pos2.x = pos.x + (*b)->width;
  pos2.y = pos.y;
  sfSprite_setPosition(sp.sprite6, pos2);
  sfRenderWindow_drawSprite(window, sp.sprite5, NULL);
  sfRenderWindow_drawSprite(window, sp.sprite6, NULL);
  time++;
  if (time % 100 == 0)
    pos.x--;
  if (pos.x == (*b)->width)
    pos.x = (*b)->width;
  if (time == 1280)
    time = 0;
  return (pos);
}

sfVector2f              parall3mario(sfVector2f pos, sfRenderWindow *window,
				     t_my_framebuffer **b, t_mysprite sp)
{
  static int            time;
  sfVector2f            pos2;

  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  sfSprite_setPosition(sp.sprite5, pos);
  pos2.x = pos.x + 3384;
  pos2.y = pos.y;
  sfSprite_setPosition(sp.sprite6, pos2);
  sfRenderWindow_drawSprite(window, sp.sprite5, NULL);
  sfRenderWindow_drawSprite(window, sp.sprite6, NULL);
  time++;
  if (time % 20 == 0)
    pos.x--;
  if (pos.x == -3384)
    pos.x = 0;
  if (time == 3384 * 2)
    time = 0;
  return (pos);
}

t_mysprite              init_sp2(t_my_framebuffer *b, t_mysprite sp)
{
  sp.sprite = sfSprite_create();
  sp.sprite2 = sfSprite_create();
  sp.sprite3 = sfSprite_create();
  sp.sprite4 = sfSprite_create();
  sp.sprite5 = sfSprite_create();
  sp.sprite6 = sfSprite_create();
  sfSprite_setTexture(sp.sprite, sp.t, sfTrue);
  sfSprite_setTexture(sp.sprite2, sp.t, sfTrue);
  sfSprite_setTexture(sp.sprite3, sp.t2, sfTrue);
  sfSprite_setTexture(sp.sprite4, sp.t3, sfTrue);
  sfSprite_setTexture(sp.sprite5, sp.t4, sfTrue);
  sfSprite_setTexture(sp.sprite6, sp.t4, sfTrue);
  return (sp);
}

t_mysprite              init_sp(t_my_framebuffer *b)
{
  t_mysprite            sp;

  sp.pos.x = 0;
  sp.pos.y = 0;
  sp.pos1.x = 0;
  sp.pos1.y = b->height / 2;
  sp.pos2.x = sp.pos.x - b->width;
  sp.pos2.y = sp.pos.y;
  sp.pos3 = sp.pos2;
  sp.pos4 = sp.pos1;
  sp.t = sfTexture_createFromFile("sujet/title.png", NULL);
  sp.t2 = sfTexture_createFromFile("sujet/picture/nuages0.png", NULL);
  sp.t3 = sfTexture_createFromFile("sujet/picture/nuages1.png", NULL);
  sp.t4 = sfTexture_createFromFile("sujet/picture/montagnes.png", NULL);
  return (init_sp2(b, sp));
}
