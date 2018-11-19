/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:37:03 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 03:58:26 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char_checks.h"

int			ft_pow(int a, int b)
{
	int res;
	int i;

	i = 0;
	res = 1;
	if (a == 0)
	{
		return (0);
	}
	while (i < b)
	{
		res *= a;
		i++;
	}
	return (res);
}

int			ft_atoi(char *str, int *it)
{
	int res;
	int i;
	int sign;

	res = 0;
	i = 0;
	sign = 1 - 2 * (str[i + *it] == '-');
	if (str[i + *it] == '+' || str[i + *it] == '-')
		(*it)++;
	while (str[i + *it] && ft_is_digit(str[i + *it]))
		i++;
	while (i > 0)
	{
		res += ft_pow(10, i - 1) *
				(str[*it] - '0') * sign;
		(*it)++;
		i--;
	}
	return (res);
}
