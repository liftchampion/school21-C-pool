/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_works.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:13:31 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/27 13:20:28 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_size.h"
#include <stdlib.h>

int8_t		**ft_alloc_memory(void)
{
	int		k;
	int8_t	**m;

	k = 0;
	m = (int8_t**)malloc(sizeof(int8_t*) * SIZE);
	if (!m)
		return (0);
	while (k < SIZE)
	{
		m[k] = (int8_t*)malloc(sizeof(int8_t) * SIZE);
		if (!m[k])
			return (0);
		k++;
	}
	return (m);
}

void		ft_free(int8_t **m)
{
	int k;

	k = 0;
	while (k < SIZE)
	{
		free(m[k]);
		k++;
	}
	free(m);
}
