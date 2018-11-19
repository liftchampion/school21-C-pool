/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 06:56:59 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/30 14:22:31 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char_works.h"
#include "ft_operation.h"

extern t_opp g_opptab[];

void		ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	ft_putnbr(a / b);
}

void		ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	ft_putnbr(a % b);
}

void		ft_usage(int a, int b)
{
	int c;
	int i;

	c = a + b;
	i = 0;
	ft_putstr("error : only [ ");
	while (ft_strlen(g_opptab[i].sign) != 0)
	{
		ft_putstr(g_opptab[i].sign);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("] are accepted");
}
