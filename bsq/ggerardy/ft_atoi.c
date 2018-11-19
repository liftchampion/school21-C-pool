/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:48:26 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/06 10:48:28 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	ft_copy_data(char *src, char *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
}

t_sq	ft_create_sqr(void)
{
	t_sq sq;

	sq.side = 0;
	sq.it = 0;
	return (sq);
}

int8_t	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_pow(int a, int b)
{
	int		res;
	int		i;

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

int		ft_atoi(char *str, uint8_t *it)
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
