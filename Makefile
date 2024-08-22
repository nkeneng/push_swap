NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = stack.c ops.c sort.c midpoint_algo.c free.c flip_a.c flip_b.c utilities.c change-name.c
SRC = push_swap.c
MAIN = test/main.c
TESTS = $(shell find ./test -name "*test.c")

LIBFT = -Llibft -lft

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TESTS:.c=.o)
SRC_OBJ = $(SRC:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)

all: submodules libft $(NAME)

check-sort:
	cc test/main_count.c -o check.out && ./check.out

run: all
	./$(NAME) 2 3 5 12 10 6 9 7 4 1 8 11

submodules:
	if [ -z "$(shell ls -A libft)" ]; then \
		echo "libft submodule not initialized, initializing..."; \
		git submodule init && git submodule update --recursive; \
	fi
	if [ -z "$(shell ls -A libft/ft_printf)" -o -z "$(shell ls -A libft/get_next_line)" ]; then \
		echo "libft submodule not initialized, initializing..."; \
		cd libft && git submodule init && git submodule update --recursive; \
	fi

libft:
	$(MAKE) -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SRC_OBJ) $(LIBFT) -o $(NAME)

test: $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJS) $(LIBFT) -lcriterion -o test.out && ./test.out

main: $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MAIN_OBJ) -o main.out 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean  fclean re submodules libft
