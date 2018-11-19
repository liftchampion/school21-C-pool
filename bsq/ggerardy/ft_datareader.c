/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datareader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:54:10 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/06 10:54:11 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int8_t	ft_check_coolest_read(int file, size_t full_len, char *data, size_t res)
{
	char b;

	if (res != full_len)
	{
		free(data);
		return (0);
	}
	if (file != 0 && read(file, &b, 1) != 0)
	{
		free(data);
		return (0);
	}
	return (1);
}

int8_t	ft_check_cool_read(int file, size_t len, char *data, t_mask mask)
{
	size_t	res_of_read;
	char	b;
	int		chitatel;

	if (read(file, &b, 0) == -1)
		return (0);
	res_of_read = 0;
	chitatel = 0u;
	if (file == 0)
	{
		while (chitatel++ < mask.num && res_of_read < mask.num * len)
			res_of_read += read(file, data + len + res_of_read, len);
	}
	else
		res_of_read = (size_t)read(file, data + len, mask.num * len);
	if (!ft_check_coolest_read(file, (len * mask.num), data, res_of_read))
		return (0);
	return (1);
}

char	*ft_create_data(int file, size_t *len, t_mask mask)
{
	char		b;
	char		*data;
	t_vector	v;

	v = ft_make_vector();
	if (!v.data)
		return (0);
	while (read(file, &b, 1) && b != '\n')
	{
		if (!ft_v_push_back(&v, b))
			return (0);
		(*len)++;
	}
	data = (char*)malloc(sizeof(char) * (mask.num)-- * ++(*len));
	if (!data)
	{
		ft_free_vector(&v);
		return (0);
	}
	ft_copy_data(v.data, data, *len - 1);
	ft_free_vector(&v);
	if (!ft_check_cool_read(file, *len, data, mask))
		return (0);
	return (data);
}
