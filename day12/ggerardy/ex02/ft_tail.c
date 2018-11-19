/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:51:49 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 23:36:35 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_works.h"
#include "ft_char_works.h"
#include <zconf.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>

void			ft_tail_plus(char *name, uint64_t n)
{
	uint64_t	i;
	char		b;
	int			file;

	file = open(name, O_RDONLY);
	i = 1u;
	while (i < n)
	{
		read(file, &b, 1);
		i++;
	}
	ft_print_file(file);
}

void			ft_tail_minus(char *name, uint64_t n)
{
	uint64_t	len;
	uint64_t	i;
	char		b;
	int			file;

	len = ft_get_file_size(name);
	if (len == 0u)
		return ;
	if (n > len)
		len = 0u;
	else
		len -= n;
	file = open(name, O_RDONLY);
	i = 0u;
	while (i < len)
	{
		read(file, &b, 1);
		i++;
	}
	ft_print_file(file);
}

void			ft_tail(char *name, char mode, uint64_t n)
{
	int			file;
	char		b;

	file = open(name, O_RDONLY);
	if (file == -1)
	{
		ft_print_error(name);
		return ;
	}
	read(file, &b, 1);
	if (errno == 21)
	{
		return ;
	}
	close(file);
	if (mode == '+')
		ft_tail_plus(name, n);
	if (mode == '-')
		ft_tail_minus(name, n);
}
