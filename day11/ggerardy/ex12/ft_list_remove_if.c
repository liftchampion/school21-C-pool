/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:22:05 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:41:20 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_remove_begin_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_list *curr;

	curr = *begin_list;
	while (*begin_list)
	{
		if (!cmp(curr->data, data_ref))
		{
			free(*begin_list);
			*begin_list = curr->next;
			curr = curr->next;
			*begin_list = curr;
		}
		else
			return ;
	}
}

void		ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_list *curr;
	t_list *prev;

	if (*begin_list == 0)
		return ;
	ft_list_remove_begin_if(begin_list, data_ref, cmp);
	if (*begin_list == 0 || !(*begin_list)->next)
		return ;
	curr = (*begin_list)->next;
	prev = *begin_list;
	while (curr)
	{
		if (!cmp(curr->data, data_ref))
		{
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
		}
		else
			curr = curr->next;
	}
}
