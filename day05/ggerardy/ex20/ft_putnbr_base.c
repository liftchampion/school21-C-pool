/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:08:35 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/23 21:09:32 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

int			ft_check_input(char *base)
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
			return (-1);
		all_chars[(int)*(base - 1)]++;
		if (all_chars[(int)*(base - 1)] > 1)
			return (-1);
	}
	if (len <= 1)
		return (-1);
	return (len);
}

void		ft_fill_characters(int *i, int radix, int nbr, int *num)
{
	while (nbr != 0)
	{
		num[(*i)++] = nbr % radix;
		nbr /= radix;
	}
}

void		ft_print_base_char(int i, char *base, int *num, int sign)
{
	while (i-- > 0)
		ft_putchar(base[num[i] * sign]);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int num[32];
	int i;
	int sign;
	int radix;

	i = 0;
	sign = 1;
	radix = ft_check_input(base);
	if (radix == -1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	if (nbr == 0)
	{
		ft_putchar('0');
		return ;
	}
	ft_fill_characters(&i, radix, nbr, num);
	ft_print_base_char(i, base, num, sign);
}
