CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./srcs
HEADERDIR = ./includes

SRCS =	$(SRCDIR)/main.c \
		$(SRCDIR)/file.c \
		$(SRCDIR)/map.c \
		$(SRCDIR)/solution.c \
		$(SRCDIR)/validation.c \
		$(SRCDIR)/func.c \

OBJS = $(SRCS:.c=.o)

NAME = BSQ

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(HEADERDIR)/main.h
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re
