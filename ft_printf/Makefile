NAME = 	libftprintf.a
CC = gcc
SRCS = ./srcs/ft_printf.c ./srcs/ft_printpc.c ./srcs/ft_numbers.c ./srcs/ft_string.c ./srcs/ft_pointer.c ./srcs/ft_hexa.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I $(INCDIRS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJS)
	make -C ../libft/
	mv ../libft/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
