/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:42:56 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/06 10:42:58 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int8_t		ft_rabotyaga(t_intmap *im, size_t len, t_mask mask, char *data)
{
	im->j = 1u;
	while (im->j < len)
	{
		if (data[im->i] == mask.empty)
		{
			if (im->prev[im->j] <= im->curr[im->j - 1])
				im->curr[im->j] = 1u + (im->prev[im->j] <= im->prev[im->j - 1] ?
						im->prev[im->j] : im->prev[im->j - 1]);
			else
				im->curr[im->j] = 1u + (im->curr[im->j - 1] <= im->prev[im->j -
				1] ? im->curr[im->j - 1] : im->prev[im->j - 1]);
			if (im->sq->side < im->curr[im->j])
			{
				im->sq->it = im->i;
				im->sq->side = im->curr[im->j];
			}
		}
		else if (data[im->i] == mask.obs)
			im->curr[im->j] = 0u;
		else
			return (0);
		++im->i;
		++im->j;
	}
	return (1);
}

int8_t		ft_fill_ones(t_intmap *im, t_mask mask, char *data)
{
	if (data[im->i] == mask.empty)
	{
		im->curr[im->j] = 1u;
		if (im->sq->side < im->curr[im->j])
		{
			im->sq->it = im->i;
			im->sq->side = im->curr[im->j];
		}
	}
	else if (data[im->i] == mask.obs)
		im->curr[im->j] = 0u;
	else
		return (0);
	++im->i;
	++im->j;
	return (1);
}

int8_t		ft_master(t_intmap *im, char *data, size_t len, t_mask mask)
{
	size_t total_len;

	total_len = mask.num * (len + 1);
	im->j = 0u;
	while (im->i < total_len)
	{
		im->j = 0u;
		if (!ft_fill_ones(im, mask, data))
			return (0);
		if (!ft_rabotyaga(im, len, mask, data))
			return (0);
		++im->i;
		ft_swap(&im->curr, &im->prev);
	}
	return (1);
}

int8_t		ft_parator(t_intmap *im, char *data, size_t len, t_mask mask)
{
	size_t full_len;
	size_t total_len;

	full_len = len + 1;
	total_len = mask.num * full_len;
	while (im->i < total_len)
	{
		if (data[im->i] != '\n')
		{
			return (0);
		}
		im->i += full_len;
	}
	im->i = 0u;
	while (im->i < len)
		if (!ft_fill_ones(im, mask, data))
		{
			return (0);
		}
	return (1);
}

uint16_t	ft_find_sq(t_mask mask, size_t len, char *data, t_sq *sq)
{
	t_intmap im;

	im = create_intmap(--len, sq);
	if (im.curr == 0 || im.prev == 0)
		return (0);
	if (!ft_parator(&im, data, len, mask))
	{
		free(im.prev);
		free(im.curr);
		return (0);
	}
	ft_swap(&im.curr, &im.prev);
	++im.i;
	im.j = 0u;
	if (!ft_master(&im, data, len, mask))
	{
		free(im.prev);
		free(im.curr);
		return (0);
	}
	free(im.prev);
	free(im.curr);
	return (1);
}
