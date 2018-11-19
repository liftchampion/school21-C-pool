/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:07:13 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/31 23:39:27 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list *ptr;

	ptr = (t_list*)malloc(sizeof(t_list) * 1);
	ptr->data = data;
	ptr->next = 0;
	return (ptr);
}
