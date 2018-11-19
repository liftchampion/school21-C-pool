/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:05:58 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/30 06:43:15 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char*))
{
	int				i;
	unsigned int	sum;

	i = 0;
	sum = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) == 1)
			sum += (*f)(tab[i]);
		i++;
	}
	return (sum > 0u);
}