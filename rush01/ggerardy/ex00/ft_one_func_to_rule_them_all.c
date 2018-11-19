/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_func_to_rule_them_all.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:32:56 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/28 23:29:02 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include "ft_sudoku_solve.h"
#include "ft_memory_works.h"
#include "ft_matrix_works.h"
#include "ft_recursion_args.h"
#include "ft_check_input.h"
#include "ft_one_func_to_rule_them_all.h"
#include "ft_putstr.h"

int			ft_one_func_to_rule_them_all(int ac, char **av, int8_t ***answer)
{
	int8_t		**matrix;
	int8_t		**res;
	int			vars_count;

	if (!ft_check_args(ac, av))
		return (-1);
	matrix = ft_alloc_memory();
	if (!matrix)
		return (2);
	res = ft_alloc_memory();
	if (!res)
		return (2);
	ft_fill_matrix(matrix);
	ft_fill_data(matrix, av);
	ft_matrix_copy(matrix, res);
	if (!ft_check_is_valid(matrix))
		return (3);
	vars_count = 0;
	ft_fill_line((t_recursion_args){matrix, 0, 1, &vars_count, res});
	*answer = res;
	ft_free(matrix);
	return (vars_count);
}

void		ft_sauron(int ac, char **av)
{
	int		key;
	int8_t	**res;

	key = 0;
	key = ft_one_func_to_rule_them_all(ac, av, &res);
	if (key != 1)
	{
		ft_putstr("Error\n");
		return ;
	}
	ft_print_matrix(res);
}
