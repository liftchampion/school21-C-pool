/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:16:07 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:37:50 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_pop_back(t_list *begin_list)
{
	t_list *back;
	t_list *prev;

	if (!begin_list)
		return (0);
	prev = 0;
	back = begin_list;
	while (back->next != 0)
	{
		prev = back;
		back = back->next;
	}
	prev->next = 0;
	return (back);
}

void		ft_list_reverse(t_list **begin_list)
{
	t_list *ptr;
	t_list *new_begin;

	if (!*begin_list)
		return ;
	new_begin = ft_list_pop_back(*begin_list);
	ptr = new_begin;
	while ((*begin_list)->next)
	{
		ptr->next = ft_list_pop_back(*begin_list);
		ptr = ptr->next;
	}
	ptr->next = *begin_list;
	(*begin_list)->next = 0;
	*begin_list = new_begin;
}
