NAME = pipex
CC = gcc 
SRCS = ./main.c ./srcs/pipex.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft/
	mv ./libft/libft.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	make clean -C ./libft/
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
