/*
** main.c for emacs in /home/kevin.ferchaud/scroller
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Apr  1 11:04:18 2017 ferchaud kevin
** Last update Sun Apr  2 23:26:35 2017 ferchaud kevin
*/

#include "my.h"

t_mysprite		init_spmario(t_my_framebuffer *b)
{
  t_mysprite		sp;

  sp.pos.x = 0;
  sp.pos.y = 0;
  sp.pos1.x = 0;
  sp.pos1.y = b->height / 2;
  sp.pos2.x = sp.pos.x - 450;
  sp.pos2.y = sp.pos.y;
  sp.pos3 = sp.pos2;
  sp.pos4 = sp.pos1;
  sp.t = sfTexture_createFromFile("sujet/title.png", NULL);
  sp.t3 = sfTexture_createFromFile("sujet/picture/nuages0.png", NULL);
  sp.t2 = sfTexture_createFromFile("sujet/mariop.png", NULL);
  sp.t4 = sfTexture_createFromFile("sujet/mario1.png", NULL);
  return (init_sp2(b, sp));
}

void                    main2(sfRenderWindow *window, int bb)
{
  t_mysprite		sp;
  int			test;
  t_my_framebuffer	*b;
  struct music		*mus;
  int			nb;
  float			j;

  mus = my_init_mus(my_concat("sujet/modlike/", get_rand_fp(8)), &nb);
  j = 0;
  b = my_framebuffer_create(WINDOW_WIDTH, WINDOW_HEIGHT);
  sp = init_sp(b);
  while (sfRenderWindow_isOpen(window))
    {
      mus = tracker(&nb, &bb, &j, mus);
      sfRenderWindow_clear(window, sfBlack);
      sp.pos2 = parall1(sp.pos2, window, &b, sp.sprite3);
      sp.pos3 = parall2(sp.pos3, window, &b, sp.sprite4);
      sp.pos4 = parall3(sp.pos4, window, &b, sp);
      sp.pos = scrolling(sp.pos, window, &b, sp.sprite);
      sp.pos1 = triang(sp.pos1, window, &b, sp.sprite2);
      sfRenderWindow_display(window);
      if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
	mario(window, mus, 1);
    }
}

void                    mario(sfRenderWindow *window, struct music *mus,
			      int bb)
{
  sfEvent               key;
  t_mysprite		sp;
  int			test;
  t_my_framebuffer	*b;
  int			nb;
  float			j;

  j = 0;
  mus = my_init_mus(my_concat("sujet/modlike/", get_rand_fp(8)), &nb);
  b = my_framebuffer_create(WINDOW_WIDTH, WINDOW_HEIGHT);
  sp = init_spmario(b);
  while (sfRenderWindow_isOpen(window))
    {
      mus = tracker(&nb, &bb, &j, mus);
      sfRenderWindow_clear(window, sfBlack);
      sp.pos2 = parall1(sp.pos2, window, &b, sp.sprite3);
      sp.pos4 = parall3mario(sp.pos4, window, &b, sp);
      sp.pos3 = parall2(sp.pos3, window, &b, sp.sprite4);
      sp.pos = scrolling(sp.pos, window, &b, sp.sprite);
      sp.pos1 = triang(sp.pos1, window, &b, sp.sprite2);
      sfRenderWindow_display(window);
      if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
	main2(window, 1);
    }
}

void                     mandatory()
{
  sfRenderWindow        *window;

  srand(time(NULL));
  window = create_window("Window");
  main2(window, 1);
}
