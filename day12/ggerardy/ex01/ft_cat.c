/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:11:35 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 23:32:43 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char_works.h"
#include <zconf.h>
#include <fcntl.h>
#include <errno.h>

#define SIZE (12 * 1024)

void			ft_read_file(char *name)
{
	int			file;
	char		buffer[SIZE];
	int			finished;
	ssize_t		res_of_read;

	finished = 0;
	file = open(name, O_RDONLY);
	if (file == -1)
	{
		ft_print_error(name);
		return ;
	}
	while (!finished)
	{
		res_of_read = read(file, buffer, SIZE);
		if (errno == 21)
			ft_print_error(name);
		if (res_of_read == -1)
			return ;
		write(1, buffer, (size_t)res_of_read);
		if (res_of_read != SIZE)
			finished = 1;
	}
	close(file);
}

void			ft_free_buffer(char *buffer, int *j)
{
	buffer[*j] = '\0';
	*j = 0;
	ft_putstr(buffer, 1);
}

void			ft_echo(void)
{
	char		tmp;
	char		buffer[SIZE];
	int			j;
	ssize_t		res_of_read;

	j = 0;
	while (1)
	{
		res_of_read = read(0, &tmp, 1);
		if (!res_of_read && !j)
		{
			ft_free_buffer(buffer, &j);
			break ;
		}
		if (!res_of_read)
		{
			ft_free_buffer(buffer, &j);
			continue;
		}
		buffer[j] = tmp;
		j++;
		if (tmp == '\n' || j == (SIZE - 2))
			ft_free_buffer(buffer, &j);
	}
}
