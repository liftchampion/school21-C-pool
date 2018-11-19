/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 23:06:45 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/02 23:09:28 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *new_node;

	new_node = (t_btree*)malloc(sizeof(t_btree) * 1);
	new_node->right = 0;
	new_node->left = 0;
	new_node->item = item;
	return (new_node);
}
