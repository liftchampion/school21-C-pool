/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 06:12:00 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/30 17:12:08 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char_works.h"
#include "ft_atoi.h"
#include "ft_operations_simple.h"
#include "ft_operations_extra.h"
#include "ft_operation.h"

const t_operation	g_ops[] = {&ft_sub, &ft_add, &ft_mul,
	&ft_div, &ft_mod, &ft_usage};
const char		g_ops_signs[] = "-+*/%";

void		ft_do_op(t_operation op, int a, int b)
{
	op(a, b);
}

int			ft_get_pos(char c, const char *base)
{
	int i;

	i = 0;
	while (*base && c != *base)
	{
		base++;
		i++;
	}
	return (i);
}

int			ft_check_input(int ac, char **av)
{
	if (ac < 3)
		return (0);
	if (ac == 3)
		return (2);
	if (ft_strlen(av[2]) != 1)
		return (0);
	if (av[2][0] != '-' && av[2][0] != '+' && av[2][0] != '*'
			&& av[2][0] != '/' && av[2][0] != '%')
		return (0);
	return (1);
}

void		ft_calculate(int ac, char **av)
{
	if (ft_check_input(ac, av) == 0)
	{
		ft_putstr("0\n");
		return ;
	}
	if (ft_check_input(ac, av) == 2)
	{
		ft_do_op(g_ops[ft_get_pos(av[2][0], g_ops_signs)],
				ft_atoi(av[1]), 0);
		ft_putchar('\n');
		return ;
	}
	ft_do_op(g_ops[ft_get_pos(av[2][0], g_ops_signs)],
			ft_atoi(av[1]), ft_atoi(av[3]));
	ft_putchar('\n');
}
