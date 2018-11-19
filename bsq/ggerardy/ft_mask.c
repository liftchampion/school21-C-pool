/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:40:45 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/06 12:26:10 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int8_t	ft_read_mask_helper(t_mask *mask, t_vector *v)
{
	uint8_t	it;

	mask->full = v->data[v->len - 1];
	mask->obs = v->data[v->len - 2];
	mask->empty = v->data[v->len - 3];
	v->data[v->len - 3] = 'I';
	it = 0;
	mask->num = ft_atoi(v->data, &it);
	if ((mask->num <= 0 || it != v->len - 3) || (mask->full == mask->empty ||
					mask->full == mask->obs || mask->empty == mask->obs))
	{
		ft_free_vector(v);
		return (0);
	}
	return (1);
}

int8_t	ft_read_mask(int file, t_mask *mask)
{
	char		b;
	t_vector	v;

	if (read(file, &b, 0) == -1)
		return (0);
	v = ft_make_vector();
	if (!v.data)
		return (0);
	while (read(file, &b, 1) && b != '\n')
		if (!ft_v_push_back(&v, b))
			return (0);
	if (v.len < 4)
	{
		ft_free_vector(&v);
		return (0);
	}
	if (!ft_read_mask_helper(mask, &v))
		return (0);
	ft_free_vector(&v);
	return (1);
}
