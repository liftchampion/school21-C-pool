/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:20:52 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:37:24 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_find(t_list *begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_list *ptr;

	if (!begin_list)
		return (0);
	ptr = begin_list;
	while (ptr)
	{
		if (cmp(ptr->data, data_ref) == 0)
		{
			return (ptr);
		}
		ptr = ptr->next;
	}
	return (0);
}
