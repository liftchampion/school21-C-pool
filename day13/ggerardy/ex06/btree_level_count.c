/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 23:17:52 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/02 23:40:08 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void		ft_recursive(t_btree *root, int this_deep, int *max_deep)
{
	if (root == 0)
	{
		if (this_deep > *max_deep)
			*max_deep = this_deep;
		return ;
	}
	this_deep++;
	ft_recursive(root->left, this_deep, max_deep);
	ft_recursive(root->right, this_deep, max_deep);
}

int			btree_level_count(t_btree *root)
{
	int deep;

	deep = 0;
	ft_recursive(root, 0, &deep);
	return (deep);
}
