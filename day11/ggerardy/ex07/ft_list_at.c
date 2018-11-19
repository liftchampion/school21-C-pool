/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:14:58 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:33:42 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*ptr;

	if (!begin_list)
		return (0);
	i = 0;
	ptr = begin_list;
	while (ptr->next && i < nbr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == nbr)
		return (ptr);
	return (0);
}
