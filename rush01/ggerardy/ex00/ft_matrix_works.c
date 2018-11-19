/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_works.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:25:53 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/28 22:50:36 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_size.h"
#include "ft_putstr.h"
#include <stdio.h>
#include <stdint.h>

void		ft_matrix_copy(int8_t **src, int8_t **dest)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void		ft_fill_data(int8_t **m, char **data)
{
	int i;
	int j;

	i = 1;
	while (i <= SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (data[i][j] != '.')
			{
				m[i - 1][j] = data[i][j] - '0';
			}
			j++;
		}
		i++;
	}
}

void		ft_fill_matrix(int8_t **m)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		ft_print_matrix(int8_t **m)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			printf("%d  ", m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
