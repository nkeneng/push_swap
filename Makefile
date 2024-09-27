NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS_DIR		= ./sources/
OBJS_DIR		= ./objs/

SRCS = $(addprefix $(SRCS_DIR), \
	   stack.c ops.c sort.c midpoint.c \
	   sorting_utilities.c stack_a.c \
	    stack_b.c utilities.c \
		push_swap.c main.c)

LIBFT = -Llibft -lft

OBJS = $(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))

all: submodules libft $(NAME)

run: all
	./$(NAME) 2 3 5 12 10 6 9 7 4 1 8 11

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 2 3 5 12 10 6 9 7 4 1 8 11
	
submodules:
	@if [ ! -d "libft" ]; then \
		mkdir libft; \
	fi
	@if [ -z "$(shell ls -A libft)" ]; then \
		echo "libft submodule not initialized, initializing..."; \
		git submodule init && git submodule update --recursive; \
	fi
	@if [ -z "$(shell ls -A libft/ft_printf)" -o -z "$(shell ls -A libft/get_next_line)" ]; then \
		echo "libft submodule not initialized, initializing..."; \
		cd libft && git submodule init && git submodule update --recursive; \
	fi

libft:
	$(MAKE) -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re submodules libft
