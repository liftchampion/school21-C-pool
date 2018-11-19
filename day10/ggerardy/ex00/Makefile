# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 22:33:54 by ggerardy          #+#    #+#              #
#    Updated: 2018/10/30 22:57:10 by ggerardy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	   ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
HEADERS = ./includes/

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
			gcc -c $(SRCS) -I $(HEADERS)
			ar rc $(TARGET) $(OBJS)
			ranlib $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(TARGET)

re: fclean all
