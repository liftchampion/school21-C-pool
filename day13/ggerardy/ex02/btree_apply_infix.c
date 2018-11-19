/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 23:12:04 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/02 23:25:34 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void		btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
	{
		return ;
	}
	btree_apply_infix(root->left, applyf);
	applyf((*root).item);
	btree_apply_infix(root->right, applyf);
}
