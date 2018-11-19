/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 23:14:23 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/02 23:39:07 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void		btree_insert_data(t_btree **root, void *item,
		int (cmpf)(void *, void *))
{
	if (*root == 0)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
	{
		btree_insert_data(&(*root)->left, item, cmpf);
		return ;
	}
	if (cmpf(item, (*root)->item) >= 0)
	{
		btree_insert_data(&(*root)->right, item, cmpf);
		return ;
	}
}
