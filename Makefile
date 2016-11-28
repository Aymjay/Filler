NAME =	darabi.filler

SRC =	main.c\
		check.c\
		can_i.c\
		map_func.c\
		map_placing.c\
		map_check.c\
		bonus_count.c\

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ) 
	make -C libft
	gcc $(GCCF) -o $(NAME) $(OBJ) -L libft -lft

%.o: %.c libft/libft.h
	gcc $(GCCF) -c -I libft $< -o $@

.PHONY: clean fclean re

clean:
	make -C libft fclean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all