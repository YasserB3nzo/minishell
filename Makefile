CC      = cc
#CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -lreadline

SRCS    = src/main.c
OBJS    = $(SRCS:.c=.o)

NAME    = minishell

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
