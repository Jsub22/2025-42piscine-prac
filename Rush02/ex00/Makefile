CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./srcs
HEADERDIR = ./includes

SRCS =	$(SRCDIR)/main.c \
		$(SRCDIR)/convert.c \
		$(SRCDIR)/convert2.c \
		$(SRCDIR)/dict.c \
		$(SRCDIR)/other.c \
		$(SRCDIR)/other2.c \
		$(SRCDIR)/print.c \
		$(SRCDIR)/set.c \
		$(SRCDIR)/free_memory.c

OBJS = $(SRCS:.c=.o)

NAME = rush-02

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -f $(NAME) ] || [ "$(find $(OBJS) -newer $(NAME))" != "" ]; then \
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME); \
	fi

%.o: %.c $(HEADERDIR)/ft.h
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
