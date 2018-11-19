# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 07:10:04 by ggerardy          #+#    #+#              #
#    Updated: 2018/11/01 23:39:10 by ggerardy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = ft_tail
SRCS = *.c
OBJS = *.o
HEADS = *.h
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
