# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 07:23:09 by ggerardy          #+#    #+#              #
#    Updated: 2018/10/30 22:56:29 by ggerardy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = do-op
SRCS = ./ft_atoi.c ./ft_calculate.c ./ft_char_works.c ./ft_operations_extra.c \
	   ./ft_operations_simple.c ./main.c
HEADERS = *.h
W = -Wall -Wextra -Werror

all: $(SRCS) $(HEADERS)
	gcc $(W) $(SRCS) -o $(TARGET)

clean: 
	rm -f $(TARGET)
