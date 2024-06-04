NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c

LIBFT	= -Llibft -lft

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean  fclean re
