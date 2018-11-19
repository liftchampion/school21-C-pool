/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:18:19 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/27 13:23:44 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_size.h"
#include "t_point.h"
#include <stdint.h>

int			ft_check_is_already_in(int8_t **m, int line_num, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (m[line_num][i] == num)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_check_lines(int8_t **m, t_point p, int value)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		if (m[i][p.column] == value || m[p.line][i] == value)
			return (0);
		i++;
	}
	return (1);
}

t_point		ft_get_square(t_point p)
{
	int line;
	int column;

	line = p.line / (SIZE / 3);
	column = p.column / (SIZE / 3);
	return ((t_point){line, column});
}

int			ft_check_subsquare(int8_t **m, t_point sq, int value)
{
	int i;
	int j;

	i = sq.line * (SIZE / 3);
	while (i < sq.line * (SIZE / 3) + (SIZE / 3))
	{
		j = sq.column * 3;
		while (j < sq.column * (SIZE / 3) + (SIZE / 3))
		{
			if (m[i][j] == value)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_check_insert(int8_t **m, t_point p, int value)
{
	int line_check;
	int sq_check;

	if (m[p.line][p.column] != 0)
		return (0);
	line_check = ft_check_lines(m, p, value);
	sq_check = ft_check_subsquare(m, ft_get_square(p), value);
	return (line_check * sq_check);
}
