/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:56:16 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 03:59:24 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_polish_list.h"
#include "ft_polish_works.h"
#include <stdlib.h>

int			eval_expr(char *str)
{
	t_list	*pol;
	int		res;
	int		nums_count;

	res = 0;
	nums_count = 0;
	pol = ft_polish(str, &nums_count);
	if (nums_count == 0)
		res = 0;
	else if (nums_count == 1)
	{
		res = pol->data;
		free(pol);
	}
	else
		res = ft_calc_polish(&pol);
	return (res);
}
