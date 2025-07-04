
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -lreadline

# Source and object files
SRCS    = src/main.c src/execution/pwd.c src/execution/exit.c src/parssing/parssing.c
OBJS    = $(SRCS:.c=.o)

# Libft settings
LIBFT_DIR = Libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

NAME    = minishell

# Build minishell and libft
all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A) $(LDFLAGS)


# Build libft first
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

# Clean project and libft
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re


