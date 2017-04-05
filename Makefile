##
## Makefile for emacs in /home/kevin.ferchaud/scroller
## 
## Made by ferchaud kevin
## Login   <kevin.ferchaud@epitech.net>
## 
## Started on  Sat Apr  1 10:54:36 2017 ferchaud kevin
## Last update Sun Apr  2 23:20:16 2017 ferchaud kevin
##

NAME	=	scroller

SRC	=	scrollingtxt/scroller.c		\
		scrollingtxt/scroller2.c	\
		scrollingtxt/scroller3.c	\
		src/my_put_pixel.c		\
                src/my_draw_line.c              \
		src/param_window.c		\
		bonus/bonus.c			\
		wolf/main.c			\
		bonus/bonus2.c			\
		bonus/bonus3.c			\
		rush.c				\
		tracker/get_next_line.c 	\
                tracker/tracker.c       	\
                tracker/get_bsf.c       	\
                tracker/comp.c          	\
                tracker/effects.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CFLAGS	=	-I include -Ofast

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lcsfml-window -lcsfml-graphics -lc_graph_prog -lm

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
