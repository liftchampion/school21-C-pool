/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:10:26 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:32:51 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*ptr;

	size = 1;
	ptr = begin_list;
	if (begin_list == 0)
	{
		return (0);
	}
	while (ptr->next != 0)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}
