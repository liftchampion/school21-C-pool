# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 04:13:09 by ggerardy          #+#    #+#              #
#    Updated: 2018/11/04 04:26:04 by ggerardy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = eval_expr
SRCS = ./ft_atoi.c ./ft_char_checks.c ./ft_eval_expr.c ./ft_list_works.c \
	   ./ft_output.c ./ft_polish_works.c ./ft_polish_works_helper.c ./main.c
OBJS = ./ft_atoi.o ./ft_char_checks.o ./ft_eval_expr.o ./ft_list_works.o \
	   ./ft_output.o ./ft_polish_works.o ./ft_polish_works_helper.o ./main.o
HEADS = ./ft_atoi.h ./ft_char_checks.h ./ft_eval_expr.h ./ft_list_works.h \
		./ft_output.h ./ft_polish_list.h ./ft_polish_works.h \
		./ft_polish_works_helper.h
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
