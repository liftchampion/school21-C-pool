/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 23:09:14 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/20 02:13:12 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;
	int i;

	if (nb < 0 || nb > 12)
		return (0);
	res = 1;
	i = 1;
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}