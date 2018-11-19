/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:41:41 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/20 21:18:49 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_check_diag(int *data, int x, int y)
{
	int i;
	int j;
	int a;
	int b;

	i = 0;
	j = 0;
	while (i < 8)
	{
		if (data[i] != 9)
		{
			if (x >= i)
				a = x - i;
			else
				a = i - x;
			if (y >= data[i])
				b = y - data[i];
			else
				b = data[i] - y;
			if (a == b)
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_check_queen(int *data, int x, int y)
{
	int i;

	i = 0;
	if (data[x] != 9)
	{
		return (0);
	}
	while (i < 8)
	{
		if (data[i++] == y)
		{
			return (0);
		}
	}
	return (ft_check_diag(data, x, y));
}

void		ft_fill_str(int *data, int str_num, int *vars)
{
	int i;
	int k;
	int data_c[8];

	if (str_num == 8)
	{
		(*vars)++;
		return ;
	}
	i = 0;
	while (i++ < 8)
	{
		if (ft_check_queen(data, str_num, i - 1))
		{
			k = 0;
			while (k++ < 8)
				data_c[k - 1] = data[k - 1];
			data_c[str_num] = i - 1;
			ft_fill_str(data_c, str_num + 1, vars);
		}
	}
}

int			ft_eight_queens_puzzle(void)
{
	int data[8];
	int vars;
	int i;

	i = 0;
	while (i < 8)
	{
		data[i] = 9;
		i++;
	}
	vars = 0;
	ft_fill_str(data, 0, &vars);
	return (vars);
}
