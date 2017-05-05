##
## Makefile for printf in /home/iseeze92/Novembre-Decembre/printf/PSU_2016_my_printf
## 
## Made by Johan Lhour
## Login   <iseeze92@epitech.net>
## 
## Started on  Sat Nov 19 14:17:21 2016 Johan Lhour
## Last update Mon Apr 10 13:48:23 2017 johan
##

SRC	=	src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/my_putstr.c		\
		src/printf.c

CFLAGS += -I include

OBJ	=  $(SRC:.c=.o)

CC	= gcc

NAME	=  libptf.a

all:  $(NAME)

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:  clean
	rm -f $(NAME)

re:  fclean all

.PHONY: all clean fclean re
