/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:48:26 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/19 23:37:37 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_parser(char *str, int *len, int *sign)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			if (*str != '-' || *len != 0)
			{
				if (*len > 0)
					break ;
				else
					return ;
			}
		}
		if (*str == '-')
		{
			*sign = -1;
		}
		str++;
		(*len)++;
	}
}

int			ft_atoi(char *str)
{
	int res;
	int sign;
	int len;

	while (*str == ' ')
		str++;
	len = 0;
	res = 0;
	sign = 1;
	ft_parser(str, &len, &sign);
	len -= sign < 0;
	str += sign < 0;
	while (len > 0)
	{
		res += (*str - '0') * ft_pow(10, len - 1);
		len--;
		str++;
	}
	return (res * sign);
}
