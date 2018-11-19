/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 06:12:00 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/30 17:03:37 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char_works.h"
#include "ft_atoi.h"
#include "ft_operations_simple.h"
#include "ft_operations_extra.h"
#include "ft_operation.h"
#include "ft_opp.h"
#include "ft_strcmp.h"

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
	if (!av)
		return (0);
	if (ac < 3)
		return (0);
	if (ac == 3)
		return (2);
	return (1);
}

void		ft_calculate(int ac, char **av)
{
	int i;

	i = 0;
	if (ft_check_input(ac, av) == 0)
	{
		while (ft_strlen(g_opptab[i].sign) != 0)
			i++;
		ft_do_op(g_opptab[i].op, 1, 1);
		ft_putchar('\n');
		return ;
	}
	i = 0;
	while (ft_strcmp(g_opptab[i].sign, av[2]) != 0 &&
			ft_strlen(g_opptab[i].sign) != 0)
		i++;
	if (ft_check_input(ac, av) == 2)
	{
		ft_do_op(g_opptab[i].op, ft_atoi(av[1]), 0);
		ft_putchar('\n');
		return ;
	}
	ft_do_op(g_opptab[i].op,
			ft_atoi(av[1]), ft_atoi(av[3]));
	ft_putchar('\n');
}
