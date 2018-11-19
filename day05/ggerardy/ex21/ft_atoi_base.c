/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:14:29 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/23 23:40:40 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_base(char *base)
{
	unsigned int	len;
	char			all_chars[256];
	int				i;

	len = 0;
	i = 0;
	while (i < 256)
		all_chars[i++] = 0;
	while (*base++)
	{
		len++;
		if (*(base - 1) == '+' || *(base - 1) == '-')
			return (0);
		all_chars[*(base - 1)]++;
		if (all_chars[*(base - 1)] > 1)
			return (0);
	}
	if (len <= 1)
		return (0);
	return (len);
}

int		ft_check_str(char *str, char *base)
{
	int		was_in;
	char	*base_begin;

	base_begin = base;
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			str++;
			continue;
		}
		base = base_begin;
		was_in = 0;
		while (*base)
		{
			if (*base == *str)
				was_in = 1;
			base++;
		}
		if (!was_in)
			return (0);
		str++;
	}
	return (1);
}

int		ft_pow(int a, int b)
{
	int	res;
	int	i;

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

int		ft_get_pos(char c, char *base)
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

int		ft_atoi_base(char *str, char *base)
{
	int		res;
	int		sign;
	int		radix;
	int		i;
	char	*ptr;

	res = 0;
	sign = 1;
	radix = ft_check_base(base);
	i = 0;
	if (radix == 0 || ft_check_str(str, base) == 0)
		return (0);
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	ptr = str;
	while (str[++i - 1] != '\0' && str[i - 1] != '+' && str[i - 1] != '-');
	while (*ptr != '\0' && *ptr != '+' && *ptr != '-')
	{
		res += ft_pow(radix, i - 1) + ft_get_pos(*ptr, base);
		i--;
		ptr++;
	}
	return (res * sign);
}
