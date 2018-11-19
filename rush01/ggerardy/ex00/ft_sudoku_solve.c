/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:03:35 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/28 23:31:00 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_size.h"
#include "ft_memory_works.h"
#include "ft_matrix_works.h"
#include "ft_sudoku_checks.h"
#include "ft_recursion_args.h"

void		ft_fill_line(t_recursion_args a);

int			ft_insert_num(t_recursion_args a, int i)
{
	int8_t **m_copy;

	m_copy = ft_alloc_memory();
	if (!m_copy)
	{
		*(a.vars_count) = -1;
		return (-1);
	}
	ft_matrix_copy(a.m, m_copy);
	m_copy[a.line_num][i] = a.num;
	ft_fill_line((t_recursion_args){m_copy, a.line_num, a.num + 1,
									a.vars_count, a.answer});
	ft_free(m_copy);
	return (0);
}

void		ft_fill_line(t_recursion_args a)
{
	int i;
	int insert_result;

	i = 0;
	if (a.line_num == SIZE && ++(*(a.vars_count)) >= 0)
	{
		ft_matrix_copy(a.m, a.answer);
		return ;
	}
	if (a.num == SIZE + 1)
		ft_fill_line((t_recursion_args){a.m, a.line_num + 1, 1,
									a.vars_count, a.answer});
	if (ft_check_is_already_in(a.m, a.line_num, a.num))
		ft_fill_line((t_recursion_args){a.m, a.line_num, a.num + 1,
									a.vars_count, a.answer});
	while (i++ < SIZE)
	{
		if (ft_check_insert(a.m, (t_point){a.line_num, i - 1}, a.num))
		{
			insert_result = ft_insert_num((t_recursion_args){a.m, a.line_num,
									a.num, a.vars_count, a.answer}, i - 1);
			if (insert_result == -1)
				return ;
		}
	}
}
