NAME = pipex
CC = gcc 
SRCS = ./srcs/main.c ./srcs/pipex.c ./srcs/ft_error.c ./srcs/path_and_cmd_finder.c
SRCS_BONUS = ./srcs/main_bonus.c ./srcs/pipex_bonus.c ./srcs/ft_error_bonus.c ./srcs/path_and_cmd_finder_bonus.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft/
	mv ./libft/libft.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft

bonus : $(SRCS_BONUS)
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
