/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polish_works_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:57:34 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 04:08:46 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_polish_list.h"
#include "ft_list_works.h"
#include "ft_char_checks.h"
#include <stdlib.h>

int			ft_get_priority(char c)
{
	if (c == '+' || c == '-')
		return (1);
	if (c == '/' || c == '%' || c == '*')
		return (2);
	return (0);
}

int			ft_need_pop(t_list *ops, char op)
{
	if (ops == 0)
		return (0);
	if (ft_get_priority(ops->op) > ft_get_priority(op))
		return (1);
	if (ft_get_priority(ops->op) < ft_get_priority(op))
		return (0);
	if (ft_is_left_ass(ops->op))
		return (1);
	return (0);
}

int			ft_do_op_math(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	return (0);
}

int			ft_do_op_list(t_list *prev, t_list *op, int is_fin)
{
	int		a;
	int		b;
	char	c;
	t_list	*tmp;

	a = op->next->next->data;
	b = op->next->data;
	c = op->op;
	tmp = op->next->next->next;
	free(op->next->next);
	free(op->next);
	free(op);
	if (is_fin)
	{
		return (ft_do_op_math(a, b, c));
	}
	ft_list_push_front(&tmp, ft_do_op_math(a, b, c), '=');
	prev->next = tmp;
	return (0);
}

void		ft_handle_op(t_list **ops, t_list **out, char op)
{
	if (op == '(')
		ft_list_push_front(ops, 0, '(');
	else if (op == ')')
	{
		while (*ops && (*ops)->op != '(')
			ft_list_pop_push(ops, out);
		ft_list_free_front(ops);
	}
	else
	{
		while (*ops && ft_need_pop(*ops, op))
			ft_list_pop_push(ops, out);
		ft_list_push_front(ops, 0, op);
	}
}
