/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:11:09 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:26:26 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_last(t_list *begin_list)
{
	t_list *ptr;

	ptr = begin_list;
	if (begin_list == 0)
	{
		return (0);
	}
	while (ptr->next != 0)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
