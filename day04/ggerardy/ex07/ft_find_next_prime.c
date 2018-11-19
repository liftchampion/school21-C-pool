/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 05:40:25 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/20 07:46:05 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	if (nb >= 46340 * 46340)
	{
		return (46340);
	}
	i = 1;
	while (i < 46341)
	{
		if (i * i == nb)
		{
			return (i);
		}
		if (i * i > nb)
		{
			return (i - 1);
		}
		i++;
	}
	return (0);
}

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (i < ft_sqrt(nb) + 1)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 2)
	{
		return (2);
	}
	i = nb;
	while (i <= 2147483647)
	{
		if (ft_is_prime(i))
		{
			return (i);
		}
		i++;
	}
	return (0);
}
