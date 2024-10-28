# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subjeong <subjeong@student.42gyeongsa      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 14:35:55 by subjeong          #+#    #+#              #
#    Updated: 2024/09/27 14:36:20 by subjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./srcs
HEADERDIR = ./includes

SRCS =	$(SRCDIR)/main.c $(SRCDIR)/ft_putchar.c

OBJS = $(SRCS:.c=.o)

NAME = ft_display_file

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -f $(NAME) ] || [ "$(find $(OBJS) -newer $(NAME))" != "" ]; then \
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME); \
	fi

%.o: %.c $(HEADERDIR)/main.h
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
