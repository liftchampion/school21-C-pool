/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:21:23 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/28 23:26:30 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_size.h"
#include "ft_sudoku_checks.h"
#include "t_point.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int		ft_check_str(char *str)
{
	if (ft_strlen(str) != SIZE)
		return (0);
	while (*str)
	{
		if (*str != '.')
		{
			if (*str < '0' || *str > '9')
				return (0);
		}
		str++;
	}
	return (1);
}

int		ft_check_args(int ac, char **av)
{
	int i;

	if (ac - 1 != SIZE)
		return (0);
	i = 1;
	while (i <= SIZE)
	{
		if (!ft_check_str(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_is_valid(int8_t **m)
{
	int		i;
	int		j;
	int8_t	tmp;
	int		count;

	i = 0;
	count = 0;
	while (i++ < SIZE)
	{
		j = 0;
		while (j++ < SIZE)
		{
			if (m[i - 1][j - 1] != 0)
			{
				count++;
				tmp = m[i - 1][j - 1];
				m[i - 1][j - 1] = 0;
				if (!ft_check_insert(m, (t_point){i - 1, j - 1}, tmp))
					return (0);
				m[i - 1][j - 1] = tmp;
			}
		}
	}
	return (count >= 17);
}
