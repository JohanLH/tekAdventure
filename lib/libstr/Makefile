##
## Makefile for printf in /home/iseeze92/Novembre-Decembre/printf/PSU_2016_my_printf
## 
## Made by Johan Lhour
## Login   <iseeze92@epitech.net>
## 
## Started on  Sat Nov 19 14:17:21 2016 Johan Lhour
## Last update Fri May  5 12:34:49 2017 johan
##

SRC	=	src/concat.c			\
		src/count_elem.c		\
		src/my_strcmp.c			\
		src/my_strcpy.c			\
		src/my_strdup.c			\
		src/my_strlen.c			\
		src/my_strlen_wordtab.c		\
		src/my_str_to_wordtab.c		\
		src/my_lower_case.c		\
		src/my_strncmp.c		\
		src/my_strncpy.c		\
		src/my_atoi.c			\
		src/my_get_float.c		\
		src/replace_str.c		\
		src/free_tab.c			\

CFLAGS += -I include

OBJ	=  $(SRC:.c=.o)

CC	= gcc

NAME	=  libstr.a

all:  $(NAME)

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:  clean
	rm -f $(NAME)

re:  fclean all

.PHONY: all clean fclean re
