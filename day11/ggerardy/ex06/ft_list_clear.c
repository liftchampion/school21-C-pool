/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:14:10 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:33:17 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_clear(t_list **begin_list)
{
	if (*begin_list == 0)
		return ;
	if ((*begin_list)->next == 0)
	{
		free(*begin_list);
		*begin_list = 0;
		return ;
	}
	ft_list_clear(&(*begin_list)->next);
	free(*begin_list);
	*begin_list = 0;
}
