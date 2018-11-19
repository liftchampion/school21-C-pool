/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_intmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:23:34 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/07 15:27:10 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_intmap			create_intmap(size_t len, t_sq *sq)
{
	t_intmap intmap;

	intmap.sq = sq;
	intmap.curr = (uint16_t*)malloc(sizeof(uint16_t) * len);
	intmap.prev = (uint16_t*)malloc(sizeof(uint16_t) * len);
	intmap.i = len;
	intmap.j = 0;
	return (intmap);
}

void				ft_swap(uint16_t **a, uint16_t **b)
{
	uint16_t *c;

	c = *a;
	*a = *b;
	*b = c;
}
