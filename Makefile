##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles mylib
##

CC 	=	gcc

SRC	=	src/main.c \
		src/error.c \
		src/init.c \
		src/torus.c

LIB 	=	lib/my/my_put.c	\
		lib/my/my_getnbr.c \
		lib/my/my_str.c \
		lib/my/my_str_is.c \
		lib/my/my_str_to_word_array.c \
		lib/my/list_add.c \
		lib/my/list_create.c \
		lib/my/list_get.c \
		lib/my/list_remove.c

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	libmy.a

NAME_BIN	= 	105torus

LIBA	=	-L. -lmy

GLIB	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lm

INCLUDES        =       -I includes/

CFLAGS	=	$(INCLUDES) -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@$(CC) -o $(NAME_BIN) $(LIBA) $(GLIB)
		@echo -e "\033[1;32mCompilation done\033[0m"

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@find . \( -name "*~" -o -name "#*" -o -name "*#" \) -delete
	@echo -e "\033[1;31mClean done\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BIN)
	@rm -f coding-style-reports.log
	@echo -e "\033[1;31mFclean done\033[0m"

re:	fclean all

.PHONY: 	all re clean fclean
