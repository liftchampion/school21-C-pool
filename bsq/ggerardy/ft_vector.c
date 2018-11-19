/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:45:58 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/06 10:46:01 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_vector	ft_make_vector(void)
{
	t_vector	v;
	uint32_t	v_init;

	v_init = 32;
	v.data = (char*)malloc(sizeof(char) * v_init);
	if (!v.data)
		return ((t_vector){0, 0, 0});
	v.data[0] = 0u;
	v.len = 0u;
	v.capacity = v_init - 1;
	return (v);
}

void		ft_free_vector(t_vector *v)
{
	if (v->data)
		free(v->data);
}

int8_t		ft_v_push_back(t_vector *v, char c)
{
	char		*new;
	uint32_t	i;

	if (v->len == v->capacity)
	{
		new = (char*)malloc(sizeof(char) * (v->capacity + 1) * 2);
		if (!new)
		{
			ft_free_vector(v);
			return (0);
		}
		i = 0;
		while (i <= v->capacity)
		{
			new[i] = v->data[i];
			i++;
		}
		free(v->data);
		v->data = new;
		v->capacity *= 2;
	}
	v->data[v->len] = c;
	v->len++;
	v->data[v->len] = '\0';
	return (1);
}
