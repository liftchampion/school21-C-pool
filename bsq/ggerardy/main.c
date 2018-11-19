/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:59:16 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/06 09:59:20 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void		ft_update_map(char *data, t_sq sq, size_t len, t_mask mask)
{
	size_t i;
	size_t j;
	size_t up_sq;

	up_sq = sq.it - (len + 1) * (sq.side - 1);
	data[up_sq] = mask.full;
	i = 0u;
	while (i < sq.side)
	{
		j = 0u;
		while (j < sq.side)
		{
			data[up_sq + j] = mask.full;
			++j;
		}
		up_sq += len;
		++i;
	}
}

int8_t		ft_bsq(int file)
{
	t_mask	mask;
	size_t	len;
	char	*data;
	t_sq	sq;

	sq = ft_create_sqr();
	if (!ft_read_mask(file, &mask))
		return (0);
	len = 0;
	data = ft_create_data(file, &len, mask);
	if (!data)
		return (0);
	if (!ft_find_sq(mask, len, data, &sq))
	{
		free(data);
		return (0);
	}
	ft_update_map(data, sq, len, mask);
	write(1, data, len * mask.num);
	free(data);
	return (1);
}

int			main(int argc, char **argv)
{
	int	i;
	int	file;

	i = 1;
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1 || !ft_bsq(file))
		{
			write(2, "map error\n", 10);
		}
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
		close(file);
	}
	if (argc == 1)
	{
		if (!ft_bsq(0))
		{
			write(2, "map error\n", 10);
		}
	}
	return (0);
}
