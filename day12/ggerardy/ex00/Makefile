# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 05:43:40 by ggerardy          #+#    #+#              #
#    Updated: 2018/11/01 07:55:05 by ggerardy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = ft_display_file
SRCS = ./ft_print_file.c
OBJS = ./ft_print_file.o
W = -Wall -Wextra -Werror

all: $(TARGET)

$(OBJS): $(SRCS)
	gcc -c $(W) $(SRCS)

$(TARGET): $(OBJS)
	gcc $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)
