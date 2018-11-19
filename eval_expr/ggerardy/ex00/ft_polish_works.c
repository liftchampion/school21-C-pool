/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polish_works.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:57:17 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 04:05:45 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_polish_list.h"
#include "ft_polish_works_helper.h"
#include "ft_char_checks.h"
#include "ft_list_works.h"
#include "ft_atoi.h"

int				ft_calc_polish(t_list **pol)
{
	t_list *ptr;
	t_list *prev;
	t_list *first_op;
	t_list *f_o_prev;

	while ((*pol)->next->next->next)
	{
		ptr = *pol;
		prev = 0;
		first_op = 0;
		f_o_prev = 0;
		while (ptr->next)
		{
			if (ft_is_op(ptr->op))
			{
				first_op = ptr;
				f_o_prev = prev;
			}
			prev = ptr;
			ptr = ptr->next;
		}
		ft_do_op_list(f_o_prev, first_op, 0);
	}
	return (ft_do_op_list(*pol, *pol, 1));
}

t_list			*ft_polish(char *str, int *nums_count)
{
	int			it;
	t_list		*out;
	t_list		*ops;

	it = 0;
	out = 0;
	ops = 0;
	while (str[it])
	{
		if (ft_is_digit(str[it]) || ft_is_unary_minus(str, it))
		{
			ft_list_push_front(&out, ft_atoi(str, &it), '=');
			(*nums_count)++;
		}
		if (ft_is_op(str[it]))
		{
			ft_handle_op(&ops, &out, str[it]);
			it++;
		}
		if (ft_is_space(str[it]))
			it++;
	}
	while (ops)
		ft_list_pop_push(&ops, &out);
	return (out);
}
