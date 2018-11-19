/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_works.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:56:33 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 04:03:59 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_polish_list.h"

t_list		*ft_create_elem(int data, char op)
{
	t_list *ptr;

	ptr = (t_list*)malloc(sizeof(t_list) * 1);
	ptr->data = data;
	ptr->op = op;
	ptr->next = 0;
	return (ptr);
}

void		ft_list_push_front(t_list **begin_list, int data, char op)
{
	t_list *ptr;

	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data, op);
		return ;
	}
	ptr = ft_create_elem(data, op);
	ptr->next = *begin_list;
	ptr->op = op;
	*begin_list = ptr;
}

void		ft_list_pop_push(t_list **ops, t_list **out)
{
	t_list *tmp;

	if (*ops == 0)
		return ;
	tmp = *ops;
	*ops = (*ops)->next;
	tmp->next = *out;
	*out = tmp;
}

void		ft_list_free_front(t_list **list)
{
	t_list *tmp;

	if (*list == 0)
		return ;
	tmp = *list;
	*list = (*list)->next;
	free(tmp);
}
