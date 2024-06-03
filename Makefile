NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS =

LIBFT	= -Llibft -lft

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):: $(OBJS)
	${AR} ${NAME} ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
