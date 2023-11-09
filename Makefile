NAME = pipex
CC = gcc 
SRCS = ./main.c ./srcs/pipex.c
OBJS = $(patsubst %.c, %.o, $(srcs))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJS)
	make -C ./ft_printf
	mv ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lftprintf

clean :
	rn -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
