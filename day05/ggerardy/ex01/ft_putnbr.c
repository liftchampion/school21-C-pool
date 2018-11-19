/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:07:58 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/22 17:29:58 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		ft_putnbr(int nb)
{
	char	num[10];
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (nb != 0)
	{
		num[i++] = nb % 10;
		nb /= 10;
	}
	while (i-- > 0)
	{
		ft_putchar(num[i] * sign + '0');
	}
}
