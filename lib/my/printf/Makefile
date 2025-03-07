##
## EPITECH PROJECT, 2024
## printf
## File description:
## Makefile v2
##

NAME = printf.a

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -g3

all: $(NAME)

$(NAME):
	@cp my_printf.h ../../../include/my_printf.h
	@cp switcher.h ../../../include/switcher.h

clean:
	@$(RM) $(OBJ)
	@$(RM) *.gch
	@$(RM) ../../../include/my_printf.h
	@$(RM) ../../../include/switcher.h

fclean: clean
	@$(RM) $(NAME)

re: fclean all
