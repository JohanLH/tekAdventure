##
## Makefile for gnl in /home/iseeze92/Novembre-Decembre/printf/PSU_2016_my_printf
## 
## Made by Johan Lhour
## Login   <iseeze92@epitech.net>
## 
## Started on  Sat Nov 19 14:17:21 2016 Johan Lhour
## Last update Mon Apr 10 13:49:45 2017 johan
##

SRC	=	src/get_next_line.c	\

CFLAGS += -I include

OBJ	=  $(SRC:.c=.o)

CC	= gcc

NAME	=  libgnl.a

all:  $(NAME)

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:  clean
	rm -f $(NAME)

re:  fclean all

.PHONY: all clean fclean re
