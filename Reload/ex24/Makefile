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

CFLAGS = -Wall -Wextra -Werror -I $(HEADERDIR)

SRCDIR = ./srcs

HEADERDIR = ./includes

SRCS =	$(SRCDIR)/ft_putchar.c \
		$(SRCDIR)/ft_swap.c \
		$(SRCDIR)/ft_putstr.c \
		$(SRCDIR)/ft_strlen.c \
		$(SRCDIR)/ft_strcmp.c \

OBJS = $(SRCS:.c=.o)

TARGET = libft.a

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
