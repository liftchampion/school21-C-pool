/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 05:24:53 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/25 05:53:07 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ptr;
	int i;

	if (min >= max)
		return (0);
	ptr = (int*)malloc(sizeof(int) * (max - min));
	if (!ptr)
		return (ptr);
	i = min;
	while (i < max)
	{
		ptr[i - min] = i;
		i++;
	}
	return (ptr);
}

int		ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (!range)
		return (0);
	return (max - min);
}
