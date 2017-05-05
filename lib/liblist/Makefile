##
## Makefile for liblist in /home/johan/Thing/liblist
## 
## Made by johan
## Login   <johan@epitech.net>
## 
## Started on  Tue May  2 15:02:41 2017 johan
## Last update Tue May  2 15:48:20 2017 johan
##

SRC	=	src/list_add_elem.c	\
		src/list_delete.c	\
		src/list_error.c	\
		src/list_for_each.c	\
		src/list_init.c		\

CFLAGS += 	-Iinclude

OBJ	=  	$(SRC:.c=.o)

CC	= 	gcc

NAME	=  	liblist.a

all:  $(NAME)

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:  clean
	rm -f $(NAME)

re:  fclean all

.PHONY: all clean fclean re
