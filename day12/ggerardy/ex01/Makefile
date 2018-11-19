# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 07:10:04 by ggerardy          #+#    #+#              #
#    Updated: 2018/11/01 18:31:49 by ggerardy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = ft_cat
SRCS = ./ft_cat.c ./ft_char_works.c ./main.c
OBJS = ./ft_cat.o ./ft_char_works.o ./main.o
HEADS = ./ft_cat.h ./ft_char_works.h
W = -Wall -Wextra -Werror

all: $(TARGET)

$(OBJS): $(SRCS) $(HEADS)
	gcc -c $(W) $(SRCS)

$(TARGET): $(OBJS)
	gcc $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)
