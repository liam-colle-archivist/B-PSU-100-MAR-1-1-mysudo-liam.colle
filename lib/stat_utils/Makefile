##
## EPITECH PROJECT, 2024
## stat_utils
## File description:
## Makefile v1
##

NAME = libstatutils.a

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@cp $(NAME) ../../$(NAME)
	@cp statutils.h ../../include/statutils.h

clean:
	@$(RM) $(OBJ)
	@$(RM) *.gch
	@$(RM) ../../include/statutils.h

fclean: clean
	@$(RM) ../../$(NAME)
	@$(RM) $(NAME)

re: fclean all
