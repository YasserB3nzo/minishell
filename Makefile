CC      = cc
#CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -lreadline

LIB_PATH = ./printf
LIBFT_PATH = ./Libft

LIB_NAME = libftprintf.a
LIBFT_NAME = Libft.a


SRCS    = src/main.c src/parssing/parssing.c src/execution/exacution.c
OBJS    = $(SRCS:.c=.o)

NAME    = minishell

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) -L$(LIB_PATH) -lftprintf -L$(LIBFT_PATH) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
 #$(CC) -L$(LIB_PATH) -l$(LIB_NAME)