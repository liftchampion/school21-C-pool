/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 18:11:04 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/21 20:14:12 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UL '/'
#define UM '*'
#define UR '\\'
#define DL '\\'
#define DM '*'
#define DR '/'
#define ML '*'
#define MM ' '
#define MR '*'

int			ft_putchar(char c);

void		ft_check_and_print(int i, int j, int x, int y)
{
	if (i == 1 && j == 1)
		ft_putchar(UL);
	else if (i == 1 && j == x)
		ft_putchar(UR);
	else if (i == 1)
		ft_putchar(UM);
	else if (i == y && j == 1)
		ft_putchar(DL);
	else if (i == y && j == x)
		ft_putchar(DR);
	else if (i == y)
		ft_putchar(DM);
	else if (j == 1)
		ft_putchar(ML);
	else if (j == x)
		ft_putchar(MR);
	else
		ft_putchar(MM);
}

void		rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			ft_check_and_print(i, j, x, y);
			j++;
		}
		if (1)
		{
			ft_putchar('\n');
		}
		i++;
	}
}
