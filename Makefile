##
## Makefile for makefile in /home/jack/Documents/ressources
## 
## Made by Jack
## Login   <jack@epitech.net>
## 
## Started on  Mon Nov 28 12:48:01 2016 Jack
## Last update Mon May 29 14:11:23 2017 johan
##

SRCS	=	src/parser/init_image_function.c	\
		src/parser/init_anim_function.c		\
		src/parser/utile.c			\
		src/parser/loading_img_function.c	\
		src/parser/loading_img_function2.c	\
		src/parser/loading_anim_function.c	\
		src/parser/loading_anim_function2.c	\
		src/parser/parse_all_map.c		\
		src/parser/parse_out.c			\
		src/parser/parse_image.c		\
		src/parser/parse_file.c			\
		src/parser/parse_graph.c		\
		src/parser/parse_map.c			\
		src/parser/parse_player.c		\
		src/parser/parse_obj.c			\
		src/parser/parse_animation.c		\
		src/parser/parse_list.c			\
		src/parser/free_parsing.c		\
                src/parser/init_out_function.c          \
                src/parser/loading_out_function.c       \
                src/parser/loading_out_function2.c      \
		src/parser/error_parsing.c		\
		src/parser/parse_menu.c			\
		src/graph/find_elem_graph.c		\
		src/graph/free_graph.c			\
		src/graph/init_graph.c			\
		src/graph/pathfinding.c			\
		src/window/init_window.c		\
		src/window/display_window.c		\
		src/window/display_menu.c		\
		src/window/free_window.c		\
		src/window/action_window.c		\
		src/window/action_cursor.c		\
		src/window/find_rect_to_click.c		\
		src/window/render_sprite_animation.c	\
		src/window/change_cursor_sprite.c	\
		src/window/move_player.c		\
		src/window/find_cursor.c		\
		src/window/action_object.c		\
		src/window/inventory.c			\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

NAME	=	tekadventure

CFLAGS	+=	-I./include				\
		-I./lib/libgnl/include			\
		-I./lib/libptf/include			\
		-I./lib/libstr/include			\
		-I./lib/liblist/include			\
		-W -Wall -Wextra

CFLAG 	=	-L ./lib/libstr -lstr			\
		-L ./lib/libgnl -lgnl			\
		-L ./lib/libptf -lptf			\
		-L ./lib/liblist -llist			\
		-lc_graph_prog_full

all:	subsystem $(NAME)

subsystem:
	make -C ./lib/libptf all
	make -C ./lib/libstr all
	make -C ./lib/libgnl all
	make -C ./lib/liblist all

$(NAME): $(OBJS)
	 gcc $(OBJS) -o $(NAME) $(CFLAG)

clean:
	make -C ./lib/libptf clean
	make -C ./lib/libstr clean
	make -C ./lib/libgnl clean
	make -C ./lib/liblist clean
	rm -f $(OBJS)

fclean:	clean
	make -C ./lib/libptf fclean
	make -C ./lib/libstr fclean	
	make -C ./lib/libgnl fclean
	make -C ./lib/liblist fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
