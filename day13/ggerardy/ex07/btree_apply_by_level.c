/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 23:19:01 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/02 23:38:15 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "h.h"

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

void		ft_apply_one_level(t_btree *root, t_node_data data, int depth,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (root == 0)
	{
		return ;
	}
	if (data.deep == depth)
	{
		applyf(root->item, data.deep, *data.is_first);
		if (*data.is_first)
			*data.is_first = 0;
	}
	ft_apply_one_level(root->left, (t_node_data){data.deep + 1,
			data.is_first}, depth, applyf);
	ft_apply_one_level(root->right, (t_node_data){data.deep + 1,
			data.is_first}, depth, applyf);
}

void		btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int max_depth;
	int i;
	int is_first;

	max_depth = btree_level_count(root);
	i = 0;
	while (i < max_depth)
	{
		is_first = 1;
		ft_apply_one_level(root, (t_node_data){0, &is_first}, i, applyf);
		i++;
	}
}
