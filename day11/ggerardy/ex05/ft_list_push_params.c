/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:12:00 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:34:46 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *ptr;

	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	ptr = ft_create_elem(data);
	ptr->next = *begin_list;
	*begin_list = ptr;
}

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list		*ptr;
	int			i;

	i = 0;
	ptr = 0;
	while (i < ac)
	{
		ft_list_push_front(&ptr, (void*)av[i]);
		i++;
	}
	return (ptr);
}
