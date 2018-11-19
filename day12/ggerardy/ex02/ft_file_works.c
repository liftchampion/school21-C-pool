/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_works.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:46:13 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 23:42:59 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_size.h"
#include <zconf.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>

uint64_t		ft_get_file_size(char *name)
{
	int			file;
	int			res_of_read;
	uint64_t	len;
	char		b;
	int			was_decr;

	res_of_read = 1;
	len = 0u;
	was_decr = 0;
	file = open(name, O_RDONLY);
	while (res_of_read != 0)
	{
		res_of_read = (int)read(file, &b, 1);
		len++;
		if (len == 1u && !was_decr)
		{
			len--;
			was_decr = 1;
		}
	}
	close(file);
	return (len);
}

void			ft_print_file(int file)
{
	char		buffer[SIZE];
	int			finished;
	ssize_t		res_of_read;

	finished = 0;
	while (!finished)
	{
		res_of_read = read(file, buffer, SIZE);
		if (res_of_read == -1)
			return ;
		write(1, buffer, (size_t)res_of_read);
		if (res_of_read != SIZE)
			finished = 1;
	}
	close(file);
}

int				ft_check_file(char *name)
{
	int			file;
	char		b;

	file = open(name, O_RDONLY);
	if (file == -1)
	{
		return (2);
	}
	read(file, &b, 1);
	if (errno == 21)
	{
		return (1);
	}
	close(file);
	return (0);
}
