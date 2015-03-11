NAME=kill_jim_kong

SRC=main.c list.c solve.c

OBJ=$(SRC:.c=.o)

FLAGS=-c -Wall -Werror -Wextra

all:
	@gcc $(FLAGS) $(SRC) 
	@gcc $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
