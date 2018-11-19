/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 03:56:49 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/18 18:36:38 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		ft_putnbr(int nb)
{
	int num[11];
	int len;

	num[10] = 1;
	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		num[10] = -1;
	}
	while (nb != 0 || len == 0)
	{
		num[len] = nb % 10;
		nb /= 10;
		len++;
	}
	while (--len >= 0)
	{
		ft_putchar('0' + num[10] * num[len]);
	}
}
