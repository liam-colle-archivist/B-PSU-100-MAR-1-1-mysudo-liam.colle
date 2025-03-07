##
## EPITECH PROJECT, 2024
## libmy
## File description:
## Makefile v2
##

NAME = libmy.a

SRC = $(shell find . -type f -name '*.c')

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ./printf/
	@ar rcs $(NAME) $(OBJ)
	@cp $(NAME) ../../$(NAME)
	@cp my.h ../../include/my.h

clean:
	@$(MAKE) clean -C ./printf/
	@$(RM) $(OBJ)
	@$(RM) *.gch
	@$(RM) ../../include/my.h

fclean: clean
	@$(MAKE) fclean -C ./printf/
	@$(RM) ../../$(NAME)
	@$(RM) $(NAME)

re: fclean all
