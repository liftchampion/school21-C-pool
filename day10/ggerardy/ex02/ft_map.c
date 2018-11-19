/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:47:16 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/29 23:47:31 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int lenght, int (*f)(int))
{
	int i;
	int *res;

	i = 0;
	res = (int*)malloc(sizeof(int) * lenght);
	if (!res)
		return (res);
	while (i < lenght)
	{
		res[i] = (*f)(tab[i]);
		i++;
	}
	return (res);
}
