/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:55:14 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 23:41:47 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_char_works.h"
#include "ft_atoi.h"
#include "ft_file_works.h"
#include "ft_tail.h"

void		ft_print_name(char *name)
{
	ft_putstr("==> ", 1);
	ft_putstr(name, 1);
	ft_putstr(" <==\n", 1);
}

int			ft_str_is_numeric(char *str)
{
	if (*str == 0)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int			ft_check_args(char **argv, char *mode, uint64_t *n)
{
	char *str;

	str = argv[2];
	if (ft_strcmp(argv[1], "-c") != 0)
		return (-1);
	if (str[0] == '+')
	{
		*mode = '+';
		str++;
	}
	else if (str[0] == '-' || ft_str_is_numeric(&str[0]))
	{
		*mode = '-';
		str += (str[0] == '-');
	}
	if (ft_str_is_numeric(str) == 0)
	{
		ft_putstr("tail: illegal offset -- ", 2);
		ft_putstr(argv[2], 2);
		ft_putchar('\n', 2);
		return (-1);
	}
	*n = (uint64_t)ft_atoi(str);
	return (0);
}

int			main(int argc, char **argv)
{
	uint64_t	n;
	char		mode;
	int			i;

	i = 3;
	if (argc < 4)
		return (0);
	if (ft_check_args(argv, &mode, &n) == -1)
		return (0);
	if (argc == 4)
	{
		ft_tail(argv[3], mode, n);
		return (0);
	}
	while (i < argc)
	{
		if (ft_check_file(argv[i]) <= 1)
			ft_print_name(argv[i]);
		ft_tail(argv[i], mode, n);
		if (i != argc - 1 && ft_check_file(argv[i]) == 0)
			ft_putchar('\n', 1);
		i++;
	}
	return (0);
}
