/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:17:44 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 18:26:34 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#include "ft_char_works.h"

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		ft_echo();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
		{
			ft_echo();
			i++;
			continue;
		}
		ft_read_file(argv[i]);
		i++;
	}
	return (0);
}
