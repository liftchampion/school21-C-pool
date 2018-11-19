/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:55:15 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/30 01:55:33 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int is_more;
	int is_less;

	i = 0;
	is_more = 1;
	is_less = 1;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			is_more = 0;
		if ((*f)(tab[i], tab[i + 1]) < 0)
			is_less = 0;
		i++;
	}
	return (is_more == 1 || is_less == 1);
}
