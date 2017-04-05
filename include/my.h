/*
** my.h for emacs in /home/kevin.ferchaud/scroller/include
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Apr  1 11:25:32 2017 ferchaud kevin
** Last update Sun Apr  2 23:31:13 2017 ferchaud kevin
*/

#ifndef MY_H
# define MY_H

#include "tracker.h"
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Glyph.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Config.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Image.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Types.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Types.h>
#include <stddef.h>
#include <SFML/System/InputStream.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Color.h>
#include "my.h"
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define HEIGHT_IMG 60
#define WIDTH_IMG 490
#define WINDOW_HEIGHT 782
#define WINDOW_WIDTH 1280

typedef struct          s_ev
{
  sfSprite              **s;
  sfVideoMode           mode;
  sfRenderWindow*       window;
  sfEvent               event;
  sfTexture             *t;
}                       t_ev;

typedef struct		s_mysprite
{
  sfVector2f            pos;
  sfVector2f            pos1;
  sfVector2f            pos2;
  sfVector2f            pos3;
  sfVector2f            pos4;
  sfTexture             *t;
  sfTexture             *t2;
  sfTexture             *t3;
  sfTexture             *t4;
  sfSprite              *sprite;
  sfSprite              *sprite2;
  sfSprite              *sprite3;
  sfSprite              *sprite4;
  sfSprite              *sprite5;
  sfSprite              *sprite6;
}			t_mysprite;

typedef struct          s_my_framebuffer
{
  sfUint8               *pixels;
  int                   width;
  int                   height;
}                       t_my_framebuffer;

sfRenderWindow		*create_window(char *);
t_my_framebuffer	*my_framebuffer_create(int, int);
void                    mandatory();
void                    my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void                    bonus();
sfColor                 *set_color(int, int, int, int);
sfColor                 set_palette(int, int, int, int);
void                    my_draw_line(t_my_framebuffer *buffer,
				     sfVector2i from, sfVector2i to,
				     sfColor color);
sfVector2f              rotate_sprite(sfVector2f, sfSprite *, int);
sfVector2f              scrolling(sfVector2f, sfRenderWindow *,
				  t_my_framebuffer **, sfSprite *);
sfVector2f              triang(sfVector2f, sfRenderWindow *,
			       t_my_framebuffer **, sfSprite *);
sfVector2i		sendpos(int i, int a);
t_mysprite		init_sp(t_my_framebuffer *);
t_mysprite		init_sp2(t_my_framebuffer *, t_mysprite);
sfVector2f		parall3mario(sfVector2f, sfRenderWindow *,
				     t_my_framebuffer **, t_mysprite);
sfVector2f		parall3(sfVector2f, sfRenderWindow *,
				     t_my_framebuffer **, t_mysprite);
sfVector2f		parall2(sfVector2f, sfRenderWindow *,
				     t_my_framebuffer **, sfSprite *);
sfVector2f		parall1(sfVector2f, sfRenderWindow *,
				     t_my_framebuffer **, sfSprite *);
void                    main2(sfRenderWindow *window, int bb);
void                    mario(sfRenderWindow *window, struct music *mus,
			      int bb);
int			changenum(int);
void			wolf(t_my_framebuffer *, sfTexture *,
			     sfRenderWindow *);
void			starfield(t_my_framebuffer *, sfTexture *);
void			plasma(t_my_framebuffer *, sfTexture *);
void			checkboard(t_my_framebuffer *, sfTexture *);
void			imageslider(t_my_framebuffer *, sfTexture *, int);
t_my_framebuffer	*refreshbuf(t_my_framebuffer *);

#endif /* !MY_H */
