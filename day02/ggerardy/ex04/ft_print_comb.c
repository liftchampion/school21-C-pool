/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:08:42 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/18 18:38:13 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		ft_print_comb(void)
{
	int num;

	num = 12;
	while (num <= 789)
	{
		if (num % 100 / 10 > num / 100 && num % 10 > num % 100 / 10)
		{
			ft_putchar(num / 100 + 48);
			ft_putchar(num % 100 / 10 + 48);
			ft_putchar(num % 10 + 48);
			if (num != 789)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		num++;
	}
}
