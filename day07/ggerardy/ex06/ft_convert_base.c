/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:17:15 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/25 16:36:03 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int			ft_(int a, int b, char c, char *base)
{
	int res;
	int i;

	i = 0;
	res = 1;
	if (b == -1)
	{
		while (*base && c != *base++)
			i++;
		return (i);
	}
	if (a == 0)
		return (0);
	while (i++ < b)
		res *= a;
	return (res);
}

void		ft_rev_str(char *str, char *base)
{
	int		i;
	char	tmp;

	i = 0;
	if (*str == '-')
		str++;
	while (i < ft_strlen(str) / 2)
	{
		tmp = str[i];
		str[i] = str[ft_strlen(str) - 1 - i];
		str[ft_strlen(str) - 1 - i] = tmp;
		i++;
	}
	if (*str == 0)
	{
		str[0] = base[0];
		str[1] = 0;
	}
}

char		*ft_int_to_base(int nbr, char *base)
{
	char	*str;
	int		i;
	int		radix;
	int		sign;

	radix = ft_strlen(base);
	i = 0;
	sign = (-1) * (nbr < 0) + 1 * (nbr >= 0);
	str = (char*)malloc(sizeof(char) * 34);
	if (!str)
		return (0);
	if (sign < 0)
	{
		*str = '-';
		i++;
	}
	while (nbr != 0)
	{
		str[i] = base[(nbr % radix) * sign];
		nbr /= radix;
		i++;
	}
	str[i] = 0;
	ft_rev_str(str, base);
	return (str);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		r;
	int		len;
	int		d;
	char	*res;
	int		sign;

	r = ft_strlen(base_from);
	len = ft_strlen(nbr);
	d = 0;
	sign = (-1) * (*nbr == '-') + 1 * (*nbr != '-');
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	len = ft_strlen(nbr);
	while (*nbr)
	{
		d += ft_(r, len - 1, 'P', base_to) * ft_(r, -1, *nbr, base_from) * sign;
		nbr++;
		len--;
	}
	res = ft_int_to_base(d, base_to);
	if (!res)
		return (0);
	return (res);
}
