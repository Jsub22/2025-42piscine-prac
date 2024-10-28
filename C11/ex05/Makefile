CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./srcs
HEADERDIR = ./includes

SRCS =	$(SRCDIR)/main.c \
		$(SRCDIR)/base.c \
		$(SRCDIR)/print.c \
		$(SRCDIR)/calc.c \

OBJS = $(SRCS:.c=.o)

NAME = do-op

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -f $(NAME) ] || [ "$(find $(OBJS) -newer $(NAME))" != "" ]; then \
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME); \
	fi

%.o: %.c $(HEADERDIR)/main.h
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re