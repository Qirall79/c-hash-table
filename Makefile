
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/hash_table.c src/main.c
OBJS = $(SRC:.c=.o)
NAME = hash_table
HEADERS = src/hash_table.h

src/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re