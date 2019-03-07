NAME = fillit
SRCS = check.c main.c move_tetri.c parsing.c solver.c display.c\
		validation.c verifications.c cleaning.c
OBJS = check.o main.o move_tetri.o parsing.o solver.o display.o\
		validation.o verifications.o cleaning.o
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@clang $(FLAGS) -I libft -c $(SRCS)
	@clang $(FLAGS) -o $(NAME) $(OBJS) -I libft/ -L libft/ -lft

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)

re: fclean all
