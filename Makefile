##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile lib
##

SRC    =    init_assets_func.c\
			my_putstr.c\
			screen_dispatcher.c\
			element_init.c\
			func_hover.c\
			my_putchar.c\
			screen_settings.c\
			screen_gameplay.c\
			my_put_nbr.c\
			screen_parralax.c\
			obstacles_manager.c\
			screen_gameover.c\
			my_getnbr.c\
			audio_effect.c\
			main.c

OBJ 	=	$(SRC:.c=.o)

NAME	= 	my_runner

CFLAGS	=  	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	find . -name "*.o" -delete
	find . -name "*~" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all